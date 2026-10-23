class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto& [key, value] : mp) {
            if(pq.size() < k)
                pq.push({value, key});
            else if(value > pq.top().first){
                pq.pop();
                pq.push({value, key});
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();

        }
        return result;
    }
};
