class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(n!=m) return false;
        unordered_map<char, int> mp;
        
        for(char c: s)
            mp[c]++;
        for(char c: t)
            mp[c]--;

        for(const auto&[key, value]: mp){
            if(value != 0){
                return false;
            }
            
        }
        return true;
    }
};
