//TC: O(n)
//SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = 1e9;
        int n = prices.size();

        for(int i=0; i<n; i++){
            mini = min(mini,prices[i]); 

            profit = max(profit , (prices[i] - mini));
        }

        return profit;
    }
};
