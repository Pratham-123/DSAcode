Link- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxi =0;
        
        for(int i=0;i<prices.size();i++){
            minPrice = min(prices[i], minPrice);
            maxi = max(maxi, prices[i]-minPrice);
        }
        return maxi;
    }
};
