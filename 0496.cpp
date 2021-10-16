/* CASE 496: NEXT GREATER ELEMENT */

#include <stack>
#include <unordered_map>
#include <vector>


class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int>::iterator it = nums2.begin();
        std::stack<int> s;
        std::unordered_map<int,int> htable; // stores associated value of nums2
        while (it != nums2.end() - 1) {
            s.push(*it); // put elements in the stack
            while (!(s.empty()) && s.top() < *(it + 1)) {
                htable[s.top()] = *(it + 1);
                s.pop(); // we cannot pop until we encounter a bigger value
            }
            ++it;
        }
        while (!s.empty()) {
            htable[s.top()] = -1; // reached nums2.end() before finding greater elements
            s.pop(); // hence these are all -1
        }
        htable[nums2.back()] = -1; // final element is also always -1
        
        std::vector<int> ans;
        it = nums1.begin();
        while (it != nums1.end()) {
            ans.push_back(htable[*it]);
            ++it;
        }
        return ans;
     }
};
