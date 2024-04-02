#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Function to evaluate a prefix expression
int evaluatePrefix(string expression) {
    stack<int> operands;
    
    for (int i = expression.size() - 1; i >= 0; --i) {
        char token = expression[i];
        
        if (isdigit(token)) {
            operands.push(token - '0');
        } else {
            int operand1 = operands.top();
            operands.pop();
            
            int operand2 = operands.top();
            operands.pop();
            
            switch (token) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Invalid operator" << endl;
                    return -1;
            }
        }
    }
    
    return operands.top();
}

int main() {
    string expression = "+*543";
    int result = evaluatePrefix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
