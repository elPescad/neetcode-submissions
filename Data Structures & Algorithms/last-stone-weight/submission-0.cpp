class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int stone: stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            if(s1 == s2) {
                continue;
            } else {
                int newS = s1-s2;
                pq.push(newS);
            }
        }

        if(pq.size() == 1) {
            return pq.top();
        }
        return 0;
    }
};
