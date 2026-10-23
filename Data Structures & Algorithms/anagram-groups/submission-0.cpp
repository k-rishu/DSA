class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for(auto a: strs){
            vector<int> count(26, 0);
            for(char c : a){
                count[c-'a']++;
            }
            mp[count].push_back(a);
        }

        vector<vector<string>> res;
        for(const auto& [key,count]: mp){
            res.push_back(count);
        }
        return res;
    }
};
