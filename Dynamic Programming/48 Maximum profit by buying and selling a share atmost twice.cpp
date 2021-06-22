int maxProfit(vector<int>& price) 
{
    int n = price.size();
    vector<int> profit1(n+1, 0), profit2(n+1, 0);

    // min_price is minimum price in price[0..i]
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        if (price[i] < min_price) min_price = price[i];
        profit2[i] = max(profit2[i - 1], price[i] - min_price);
    }

    // max_price has maximum of price[i..n-1]
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (price[i] > max_price) max_price = price[i];
        profit1[i] = max(profit1[i + 1], max_price - price[i]);
    }

    int ans = INT_MIN;
    for(int i=0;i<n;i++)
        ans = max(ans, profit2[i] + profit1[i]);

    return ans;
}

// Using only one extra array
int maxProfit(vector<int>& price) 
{
        int n = price.size();
        vector<int> profit(n+1, 0);
        
        // max_price has maximum of price[i..n-1]
        int max_price = price[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (price[i] > max_price) max_price = price[i];
            profit[i] = max(profit[i + 1], max_price - price[i]);
        }
        
        // min_price is minimum price in price[0..i]
        int min_price = price[0];
        for (int i = 1; i < n; i++) {
            if (price[i] < min_price) min_price = price[i];
            profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
        }
        return profit[n - 1];
    }
