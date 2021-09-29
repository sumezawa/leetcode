/* CASE 292: CAN WIN NIM */

// rules:
// initial heap of stones
// you and opponent alternates you go first
// on each turn, person can remove 1 to 3 stones
// person who removes last stone wins

// i.e., if you have multiples of 4
// at the beginning of your first turn
// no matter how optimal you act,
// you will lose if the opponent is
// also optimal

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
        
    }
};
