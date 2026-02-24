class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = 0;
        int sell = 0;
        for(int i=n-1; i>=0; i--) {
            buy = max(buy, -prices[i]+sell);
            sell = max(sell, prices[i]+buy-fee);
        }
        return buy;
    }
};