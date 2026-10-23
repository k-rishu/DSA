class Solution {
   public:
    bool same(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        if (m > n) return false;

        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for (int i = 0; i < m; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if (same(cnt1, cnt2)) return true;

        for (int i = m; i < n; i++) {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - m] - 'a']--;

            if (same(cnt1, cnt2)) return true;
        }

        return false;
    }
};
