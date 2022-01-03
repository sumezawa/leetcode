/* CASE 997: FIND THE TOWN JUDGE */

#include <vector>

// notice:
// 1. trust[][] is a directed graph
// 2. judge trusts nobody implies the judge must not be in the directed graph (if there is, judge is unidentifiable)
// 3. every person that is not the judge must unilaterally agree on the same judge (it must be n - 1 people)

// 2G. there must be no vertex with the judge's id
// 3G. the judge vertex must have n - 1 edges going towards it
// 4. if the judge picks itself the judge is unidentifiable
// 5. if the judge picks anybody the judge is unidentifiable
// 6. an O(1) way to identify if any potential judge chose someone is to subtract from the vertices.

class Solution {
public: 
    
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::vector<int> vertices(n, 0); // array index is the vertex; value at the index is the number of edges

        for (const std::vector<int>& trust_label : trust) {
            ++vertices[(trust_label[1] - 1)]; // 3. add 1 for each voter's judge candidate
            --vertices[(trust_label[0] - 1)]; // 6. logic to check for potential judge's vote
            
        }
        
        for (int i = 0; i < n; ++i) {
            if (vertices[i] == n - 1) {// 3G. exactly (n - 1) people must agree on the judge             
                return i + 1; // zero-index adjusted
            }
        }
        
        return -1; // unable to find a 
    }
};

/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Constraints:

    1 <= n <= 1000
    0 <= trust.length <= 104
    trust[i].length == 2
    All the pairs of trust are unique.
    ai != bi (the town judge does not trust themselves)
    1 <= ai, bi <= n
*/
