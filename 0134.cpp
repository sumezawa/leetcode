/* CASE 134: GAS STATION */

/* Problem Statement
There are n gas stations along a circular route, 
where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] 
of gas to travel from the ith station to its next (i + 1)th station.
You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index 
if you can travel around the circuit once in the clockwise direction, 
otherwise return -1. If there exists a solution, it is guaranteed to be unique.

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

Constraints:

    gas.length == n
    cost.length == n
    1 <= n <= 105
    0 <= gas[i], cost[i] <= 104
*/

#include <vector>

// O(n) time, O(1) space

class Solution {
public:
    
    // ONE-PASS SOLUTION (check existence and uniqueness in one pass)
    // LeetCode: 59 ms, 49.8 MB
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int start_index = 0; // the index to start the circuit
        int tank = 0; // gas in the tank
        int sum_gas = 0;
        int sum_cost = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            sum_gas += gas[i];
            sum_cost += cost[i];
            tank = tank - cost[i] + gas[i];
            if (tank < 0) {
                start_index = i + 1; // postulate 3
                tank = 0; // reset the counter
            }
        }
        
        if (sum_gas < sum_cost) {
            return -1;
        }
        else {
            return start_index;
        }
    }
        
    // TWO-PASS SOLUTION (check existence, then check uniqueness)
    // LeetCode: 122 ms, 49.8 MB
    int canCompleteCircuit_TwoPass(std::vector<int>& gas, std::vector<int>& cost) {
        // postulate 1
        if (not_enough_gas(gas, cost)) {
            return -1;
        }
        
        int start_index = 0; // the index to start the circuit
        int tank = 0; // gas in the tank
        for (int i = 0; i < gas.size(); ++i) {
            tank = tank - cost[i] + gas[i];
            if (tank < 0) {
                start_index = i + 1; // postulate 3
                tank = 0; // reset the counter
            }
        }
        return start_index;
    }
    
    // helper function
    bool not_enough_gas(std::vector<int>& gas, std::vector<int>& cost) {
        int sum_gas = 0;
        int sum_cost = 0;
        std::vector<int>::iterator it;
        for (it = gas.begin(); it != gas.end(); ++it) {
            sum_gas += *it;
        }
        for (it = cost.begin(); it != cost.end(); ++it) {
            sum_cost += *it;
        }
        return sum_gas < sum_cost;
    }
};

/* 
TIPS TO SELF:
1. you can start anywhere, but you have to complete a clockwise (ascending index) circuit.
2. cost[i] is the amount of gas spent, not the price of the gas that was spent
3. generally we need to satisfy: gas_current - cost[i] + gas[i + 1] > 0

POSTULATES (that I don't know what mathematical discipline proves):
1. sum_of_gas > sum_of_cost implies solution exists (contrapositive is also true)
2. this solution is unique (not always true but it is true for LeetCode's test cases)
3. for some indices i, j, j cannot be reached from i, any index from i to j cannot reach it (due to uniqueness)
*/
