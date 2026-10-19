class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int res = 0, l = 0, r = people.size()-1;

        while(l <= r) {
            int remain = limit-people[r--];
            res++;
            if(people[l] <= remain) l++;
        }
        return res;
    }
};