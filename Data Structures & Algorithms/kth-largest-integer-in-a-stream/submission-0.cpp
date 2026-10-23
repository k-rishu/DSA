class KthLargest {
public:
    // map<int, int> mp;
    int target;
    priority_queue<int, vector<int>, greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        // priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<<int, int>>> q;
    
        // for(auto n : nums){
        //     mp[n]++;
        // }
        target = k;
        for(auto n: nums){
            q.push(n);
        }
        
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > target){
            while(q.size() > target){
                q.pop();
            }
        }
        return q.top();
    }
};
