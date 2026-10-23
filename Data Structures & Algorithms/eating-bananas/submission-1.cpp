class Solution {
   public:
    bool kokoCanEat(vector<int>& piles, int m, int h) {
        long long count = 0;
        for (int i = 0; i < piles.size(); i++) {
            count += ceil((double)piles[i] / m);
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX ;

            while (low <= high) {
            int mid = low + (high - low) / 2;
            if (kokoCanEat(piles, mid, h)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
