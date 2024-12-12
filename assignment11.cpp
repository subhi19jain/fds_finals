#include <iostream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
public:
    int getPrecedence(char c) {
        if (c == '+' || c == '-') return 1;
        else if (c == '*' || c == '/') return 2;
        else return 0;
    }

    string infixToPostfix(string s) {
        string postfix;
        stack<char> stk;

        for (auto i : s) {
            if (isalnum(i)) {
                postfix.push_back(i);
            } else if (i != ' ') {
                while (!stk.empty() && getPrecedence(i) <= getPrecedence(stk.top())) {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                stk.push(i);
            }
        }

        while (!stk.empty()) {
            postfix.push_back(stk.top());
            stk.pop();
        }

        return postfix;
    }

    int calculate(string s) {
        string values = infixToPostfix(s);
        stack<int> stk;

        for (auto i : values) {
            if (isalnum(i)) {
                stk.push(i - '0');
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                int res = 0;
                if (i == '/') {
                    res = a / b;
                } else if (i == '*') {
                    res = a * b;
                } else if (i == '-') {
                    res = a - b;
                } else {
                    res = a + b;
                }

                stk.push(res);
            }
        }

        return stk.top();
    }
};

int main() {
    Solution sol;
    string expression = "42";
    string postfixExpression = sol.infixToPostfix(expression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    int result = sol.calculate(expression);
    cout << "Result: " << result << endl;

    return 0;
}
