/* CASE 986: INTERVAL LIST INTERSECTIONS */

#include <cmath>
#include <vector>

// O(M + N) Time, M intervals in firstList, N intervals in secondList
// O(1) Space

// adding the std::vector::reserve() function makes the LeetCode submission lighter than 99.69% 
// however, the speed goes from faster than 91% to faster than 73%.

class Solution {
public:
    std::vector<std::vector<int>> 
        intervalIntersection(std::vector<std::vector<int>>& firstList, 
                             std::vector<vector<int>>& secondList) {
        // SPECIAL CASE
        if (firstList.empty() || secondList.empty()) {
            return std::vector<std::vector<int>>{};
        }
        
        // GENERAL CASE
        // - no intersection: fL[i].back() < sL[j].front() OR fL[i].front() > sL[j].back()
        // - partial or full: fL[i].front() <= sL[j].back() AND fL[i].back() >= sL[j].front() OR
        //                    sL[j].front() <= fL[i].back() AND sL[j].back() >= fL[i].front()
        // the intersection is the maximum starting point, minimum ending point
        
        // when comparing the two lists, if one list ends prematurely,
        // then there are no more intervals to consider.
        
        std::vector<std::vector<int>>::iterator it1 = firstList.begin(); 
        std::vector<std::vector<int>>::iterator it2 = secondList.begin();
        std::vector<std::vector<int>> intersection;
        intersection.reserve(2 * std::max(firstList.size(), secondList.size())); // Memory Improver
            
        while (it1 != firstList.end() && it2 != secondList.end()) {
            if (it1->front() <= it2->back() && it1->back() >= it2->front()) {
                intersection.push_back(
                    std::vector<int>{std::max(it1->front(), it2->front()), std::min(it1->back(), it2->back())}
                );
            }
            if (it1->back() < it2->back()) {
                ++it1; // if the end of it1's current interval is smaller, 
                       // we have to check for more intervals 
            }
            else {
                ++it2;
            }
        }
        
        return intersection;
        
    }
};
