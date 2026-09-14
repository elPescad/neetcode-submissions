class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int val = 0;
        int totalGas = 0;
        int currentGas = 0;

        for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];

            if(currentGas < 0) {
                val = i+1;
                currentGas = 0;
            }
        }

        if(totalGas >= 0) {
            return val;
        }
        return -1;
    }
};
