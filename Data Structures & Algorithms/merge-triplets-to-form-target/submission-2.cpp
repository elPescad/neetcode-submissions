class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> shorten;

        for(const auto& trip: triplets) {
            if(trip[0] <= target[0] && trip[1] <= target[1] && trip[2] <= target[2]) {
                shorten.push_back(trip);
            }
        }

        if(shorten.empty()) return false;
        if(shorten[0] == target) return true;

        vector<int> modify = shorten[0];
        for(int i = 1; i < shorten.size(); i++) {
            modify[0] = max(modify[0], shorten[i][0]);
            modify[1] = max(modify[1], shorten[i][1]);
            modify[2] = max(modify[2], shorten[i][2]);
            if(modify == target) {
                return true;
            }
        }
        return false;
    }
};
