/* CASE 821: SHORTEST DISTANCE TO A CHARACTER */

#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c) {
        int n = s.size();
        int p = -n; // let the initial p be arbitrarily small
        std::vector<int> distance(n,n); // let default distance be arbitrarily big
        
        // the crux of this problem:
        //
        // going left, we keep track of distance from the most recent
        // c that we encountered, but this distance is not necessarily
        // the shortest distance if we went the reverse direction.
        //
        // double pass is 2 * O(n) time, which is still O(n) time.
        
        // PASS 1 (LEFT TO RIGHT)
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                p = i;
            }
            distance[i] = i - p;
        }
        
        // PASS 2 (RIGHT TO LEFT)
        for (int i = p - 1; i >= 0; --i) {
            if (s[i] == c) {
                p = i;
            }
            distance[i] = min_distance(distance[i], p - i);
        }
        
        return distance;
    }
    
    // HELPER
    int min_distance(int a, int b) {
        if (a > b) {
            return b;
        }
        else {
            return a;
        }
    }
};
