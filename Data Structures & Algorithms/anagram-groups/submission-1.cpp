class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(string s: strs) {
            vector<int> freq(26, 0);

            string ans = "";
            for(char ch: s){
                freq[ch - 'a']++;
            }

            for(int it: freq){
                ans += to_string(it) + "#";
            }

            mpp[ans].push_back(s);
        }

        vector<vector<string>> temp;
        for(auto it: mpp){
            temp.push_back(it.second);
        }
        return temp;
    }
};
