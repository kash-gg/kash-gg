class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];  
        for (int price : prices) {
            int newCash = max(cash, hold + price - fee);  
            hold = max(hold, cash - price);               
            cash = newCash;
        }
        
        return cash;
    }
};
