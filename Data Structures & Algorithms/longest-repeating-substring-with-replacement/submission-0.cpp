class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int result = 0;
        for (int right = 0; right < s.size(); right++) {
            mp[s[right] - 'A']++;
            maxFreq = max(maxFreq, mp[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                mp[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }
        return result;

    }
};
