class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        int large = -1;
        for (int i = 0; i < n; i++) {
            if(height[i] > large){
                large = height[i];
            }
            prefix[i] = large;
            //  cout<< i << " " << prefix[i]<<endl;
        }
        large = -1;
        for (int i = n-1; i >= 0; i--) {
            if(height[i] > large){
                large = height[i];
            }
            suffix[i] = large;
            // cout<< i << " " << suffix[i]<<endl;
        }
    int res = 0;
        for(int i=0 ;i<n; i++){
            // cout<<"min" << min(prefix[i], suffix[i])<<" p "<<prefix[i]<<" s "<<suffix[i]<<endl;
            // cout<<"height" << height[i]<<endl;
            res+= min(prefix[i], suffix[i]) - height[i];
            // cout<<"res" <<" "<<res<<endl;
        }

        return res;
    }
};
