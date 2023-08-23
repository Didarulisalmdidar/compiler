#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Operator precedence
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Generate three-address code
string generateThreeAddressCode(const string& expression) {
    stack<char> operators;
    stack<string> operands;
    int kk=1;
    for (char token : expression) {
        if (isdigit(token)) {
            //string num(1, token);
            //cout<<"num "<<num<<endl;
            operands.push(token);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                string temp = "t" + to_string(kk);
                kk++;
                operands.push(temp);

                string code = temp + " = " + op1 + " " + op + " " + op2;
                cout << code << endl;
            }
            operators.push(token);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                string temp = "t" + to_string(kk);
                kk++;
                operands.push(temp);

                string code = temp + " = " + op1 + " " + op + " " + op2;
                cout << code << endl;
            }
            operators.pop(); // Pop '('
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        string temp = "t" + to_string(kk);
        kk++;
        operands.push(temp);

        string code = temp + " = " + op1 + " " + op + " " + op2;
        cout << code << endl;
    }

    return operands.top();
}

int main() {
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin,expression);

    string result = generateThreeAddressCode(expression);
    cout << "Result: " << result << endl;

    return 0;
}
