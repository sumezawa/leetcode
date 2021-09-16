/* CASE 2: ADDING DIGITS IN LINKED LISTS */

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* O(n) LINKED LIST ADDER */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head; // holds the pointer to the head of the list
        ListNode* newlist = &head;
        bool carry = false;
        int digit;
        
        // SPECIAL CASES (TO SPEED UP CODE)
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        else if (l1 != nullptr && l2 == nullptr) {
            return l1;
        }
        else if (l1 == nullptr && l2 != nullptr) {
            return l2;
        }
        
        // NORMAL CASES
        while (l1 != nullptr || l2 != nullptr || carry) { // expands the list, until l1, l2, and carry are all 0/nullptr
            digit = 0;
            if (carry) {
                ++digit;
                carry = false;
            }
            if (l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2->next;
            }
            carry = digit > 9;
            newlist->next = new ListNode{digit % 10};
            newlist = newlist->next;
        }
        return head.next;
    }
};
