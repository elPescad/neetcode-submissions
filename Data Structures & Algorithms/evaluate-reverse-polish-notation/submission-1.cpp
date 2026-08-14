class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> curr;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int firstNum = curr.top();
                curr.pop();
                int secondNum = curr.top();
                curr.pop();
                curr.push(secondNum + firstNum);
            } else if(tokens[i] == "-") {
                int firstNum = curr.top();
                curr.pop();
                int secondNum = curr.top();
                curr.pop();
                curr.push(secondNum - firstNum);
            } else if(tokens[i] == "*") {
                int firstNum = curr.top();
                curr.pop();
                int secondNum = curr.top();
                curr.pop();
                curr.push(secondNum * firstNum);
            } else if(tokens[i] == "/") {
                int firstNum = curr.top();
                curr.pop();
                int secondNum = curr.top();
                curr.pop();
                curr.push(secondNum / firstNum);
            } else {
                curr.push(stoi(tokens[i]));
            }
        }

        return curr.top();
    }
};
