class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int maxR = 0;
        int n = prices.size()-1;
        for(int i=n; i>=0; i--){
            maxR = max(prices[i], maxR);
            cout<<" maxR "<<maxR<<endl;
            maxP = max(maxR-prices[i], maxP);
            cout<<" maxP "<<maxP<<endl;
        }
        return maxP;
    }
};
