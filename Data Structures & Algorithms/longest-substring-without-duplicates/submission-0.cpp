class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> newSet;
        int l=0, r=0;
        int ans = 0;
        // newSet.insert(s[l]);
        while(r<s.size()){
            if(newSet.count(s[r]) == 0){
                newSet.insert(s[r]);
                ans = max(ans, r-l+1);
                r++;
            }
            else{
                while(newSet.count(s[r])!=0){
                    newSet.erase(s[l]);
                    l++;
                }
            }
        }
        return ans;
    }
};
