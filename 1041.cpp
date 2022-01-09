/* CASE 1041: BOUNDED MOVEMENT CHECKER */

#include <cmath> // std::abs
#include <string> // std::string::iterator

class Solution {
public:
    bool isRobotBounded(std::string instructions) {
        std::string::iterator it = instructions.begin();
        int direction = 0; // 0 == north, 1 == east, 2 == south, 3 == west
        int position[2] = {0, 0}; // cartesian x, y (west-east, north-south)
        while(it != instructions.end()) {
            if (*it == 'G') {
                if (std::abs(direction) % 4 == 0) {
                    ++position[1]; // increment north    
                }
                if (std::abs(direction) % 4 == 1) {
                    ++position[0]; // increment east   
                }
                if (std::abs(direction) % 4 == 2) {
                    --position[1]; // increment south
                }
                if (std::abs(direction) % 4 == 3) {
                    --position[0]; // increment west    
                }
            }
            else if (*it == 'L') {
                --direction;
            }
            else if (*it == 'R') {
                ++direction;
            }
            ++it;
        }
        return (position[0] == 0 && position[1] == 0) || (direction % 4 != 0);
    }
};

/* TIPS
1. Robot is unbounded if the directions only have G
2. Robot is unbounded if the directions remain the same after one set of instruction.
3. Taking the contrapositive statements of 1. and 2., 
   Robot is bounded if the directions has no G or the directions change after one set of instruction.
*/
/*
On an infinite plane, a robot initially stands at (0, 0) and faces north. 
The robot can receive one of three instructions:

    "G": go straight 1 unit;
    "L": turn 90 degrees to the left;
    "R": turn 90 degrees to the right.

The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
*/
