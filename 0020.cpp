/* CASE 20: CLOSED BRACKETS */

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets;
        for (char c : s) {
            // if c == { [ (, add
            if (c == '{' || c == '[' || c == '(') {
                brackets.push(c);
            }
            else {
                if (brackets.empty()) {
                    return false; // pushing closing bracket to empty stack
                }
                else {
                    if (c == '}') {
                        if (brackets.top() == '{') {
                            brackets.pop();
                        }
                        else {
                            return false;
                        }
                    }
                    else if (c == ']') {
                        if (brackets.top() == '[') {
                            brackets.pop();
                        }
                        else {
                            return false;
                        }
                    }
                    else if (c == ')') {
                        if (brackets.top() == '(') {
                            brackets.pop();
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
        return brackets.empty(); 
    }
};
