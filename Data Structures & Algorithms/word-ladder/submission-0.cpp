class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_map<string, vector<string>> mp;
        wordList.push_back(beginWord);
        for(const string& word: wordList) {
            for(int i = 0; i < word.size(); i++) {
                string pattern = word.substr(0, i) + '*' + word.substr(i+1);
                mp[pattern].push_back(word);
            }
        }

        int res = 1;
        unordered_set<string> visit{beginWord};
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if(word == endWord) {
                    return res;
                }

                for(int j = 0; j < word.size(); j++) {
                    string pattern = word.substr(0,j) + '*' + word.substr(j+1);
                    for(const string& neighbor: mp[pattern]) {
                        if(!visit.contains(neighbor)) {
                            q.push(neighbor);
                            visit.insert(neighbor);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};
