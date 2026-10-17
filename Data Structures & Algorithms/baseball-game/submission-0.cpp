class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> res;

        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "+") {
                int num1 = res.top();
                res.pop();
                int num2 = res.top();
                res.push(num1);
                res.push(num1+num2);
            } else if(operations[i] == "C") {
                res.pop();
            } else if(operations[i] == "D") {
                res.push(2*res.top());
            } else {
                res.push(stoi(operations[i]));
            }
        }

        int ans = 0;
        while(!res.empty()) {
            ans += res.top();
            res.pop();
        }

        return ans;
    }
};