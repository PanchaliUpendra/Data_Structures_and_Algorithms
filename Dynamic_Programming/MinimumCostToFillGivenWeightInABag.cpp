#include <bits/stdc++.h>
using namespace std;
 
int helper(vector<int>& cost, vector<int>& weight, int n,
           int w, vector<vector<int> >& dp)
{
    // base cases
    if (w == 0)
        return 0;
    if (w < 0 or n <= 0)
        return INT_MAX;
 
    if (dp[n][w] != -1)
        return dp[n][w];
 
    if (cost[n - 1] < 0)
        return dp[n][w]
               = min(INT_MAX,
                     helper(cost, weight, n - 1, w, dp));
 
    if (weight[n - 1] <= w) {
        return dp[n][w]
               = min(cost[n - 1]
                         + helper(cost, weight, n,
                                  w - weight[n - 1], dp),
                     helper(cost, weight, n - 1, w, dp));
    }
    return dp[n][w] = helper(cost, weight, n - 1, w, dp);
}
int minCost(vector<int>& cost, int W)
{
    int N = cost.size();
    // Your code goes here
    vector<int> weight(N);
 
    // create the weight array
    for (int i = 1; i <= N; i++) {
        weight[i - 1] = i;
    }
 
    // initialize the dp array
    vector<vector<int> > dp(N + 1, vector<int>(W + 1, -1));
 
    int res = helper(cost, weight, N, W, dp);
 
    // return -1 if result is MAX
    return (res == INT_MAX) ? -1 : res;
}
 
/* Driver code */
int main()
{
    vector<int> cost = { 20, 10, 4, 50, 100 };
    int W = cost.size();
    cout << minCost(cost, W);
    return 0;
}
