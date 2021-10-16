/* CASE 1266: MINIMUM TIME VISIT ALL POINTS */

#include <vector>

class Solution {
public:
    
    int abs(int n) {
        if (n < 0) {
            return n * -1;
        }
        return n;
    }
    int displacement(int& q1, int& q2) {
        // return magnitude of displacement (hence time elapsed)
        // parameters: two coordinates (x's or y's)
        return abs(q1 - q2);
    }
    
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        // notice the following:
        // it is optimal to move diagonally until you are on the same line
        // as the point you are trying to move (horizontal or vertical)
        // for this code, we can move diagonally until the horizontal are the same
        
        int time = 0;
        size_t size = points.size();
        size_t o;
        for (size_t p = 1; p < size; ++p) {
            o = p - 1;
            if (points[o][0] == points[p][0]) { // horizontally aligned
                time += abs(points[o][1] - points[p][1]); // vertical displacement
            }
            else if (points[o][1] == points[p][1]) { // vertically aligned
                time += abs(points[o][0] - points[p][0]); // horizontal displacement
            }
            else {
                if (abs(points[o][0] - points[p][0]) < abs(points[o][1] - points[p][1])) {
                   // steeper vertically, so align horizontal first
                   time += abs(points[o][0] - points[p][0]); // horizontal displacement
                   time += abs(points[o][1] - points[p][1]) - abs(points[o][0] - points[p][0]);
                   // the vertical displacement would be the remaining amount after
                   // diagonal shifting (hence horizontal shifting)
                }
                else { // steeper horizontally
                   time += abs(points[o][1] - points[p][1]); // vertical displacement
                   time += abs(points[o][0] - points[p][0]) - abs(points[o][1] - points[p][1]);
                }
            }    
        }
        return time;
    }
};
