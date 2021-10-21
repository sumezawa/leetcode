/* CASE 495: OVERRIDING SCHEDULES */

#include<vector>

class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        // SPECIAL CASE
        if (timeSeries.size() == 1) {
            return duration;
        }
        
        // STANDARD CASE        
        int total = 0;
        std::vector<int>::iterator it = timeSeries.begin();
        while (it != timeSeries.end() - 1) {
            total += min_duration(*(it + 1) - *it, duration);
            ++it;
        }
        
        return total + duration;
    }
    
    // HELPER FUNCTIONS
    
    int min_duration(int a, int b) {
        if (a < b) {
            return a;
        }
        else {
            return b;
        }
    }
};

/* THREE QUESTIONS:
Q: Why do you use iterators instead of for loops based on vector size?
A: Iterators are used for elements that do not have a guaranteed O(1) vector size operation.
   
Q: Why do you add the minimum of the duration vs. time interval difference?
A: If the duration is shorter than the time interval, the durations runs as scheduled (entirely).
   If the time interval is shorter, then we prematurely end the scheduled duration, and reset.
   
Q: Why do you add duration at the very end of total?
A: The while-loop accounts for all but one final scheduled duration. Hence we add that duration.
*/
