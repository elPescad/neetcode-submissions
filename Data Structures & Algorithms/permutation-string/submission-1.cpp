class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        array<int, 26> letS1 = {0}; 
        array<int, 26> letS2 = {0}; 

        for(int i = 0; i < s1.size(); i++) {
            int val = s1[i] - 'a';
            letS1[val]++;
        }

        int l = 0;
        for(int r = 0; r < s2.size(); r++) {
            int difference = r-l+1;
            int val = s2[r] - 'a';
            letS2[val]++;
            if(difference == n) {

                if(letS1 == letS2) {
                    return true;
                }
                letS2[s2[l]-'a']--;
                l++;
            }
        }
        return false;
    }
};
