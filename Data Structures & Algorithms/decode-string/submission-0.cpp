class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return output(s, i);
    }

    string output(string& s, int& i) {
        string curr = "";

        while(i < s.size() && s[i] != ']') {
            if(isdigit(s[i])) {
                int count = 0;
                while(i < s.size() && isdigit(s[i])) {
                    count = count * 10 + (s[i]-'0');
                    i++;
                }

                i++;

                string temp = output(s, i);

                i++;

                while(count--) {
                    curr += temp;
                }
            } else {
                curr += s[i];
                i++;
            }
        }

        return curr;
    }
};