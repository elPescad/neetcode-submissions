class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;

        for(int i = 0; i < position.size(); i++) {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int count = 0;
        double time = 0.0;
        for(int i = 0; i < ps.size(); i++) {
            double math = (double)(target - ps[i].first) / ps[i].second;
            if(time < math) {
                time = math;
                count++;
            }
        }

        return count;
    }
};