#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (char c : s) {
            // If opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            else {
                // Closing bracket: check if stack is empty
                if (stk.empty()) {
                    return false;
                }
                
                char top = stk.top();
                
                // Check if it matches
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        // All brackets must be matched
        return stk.empty();
    }
};