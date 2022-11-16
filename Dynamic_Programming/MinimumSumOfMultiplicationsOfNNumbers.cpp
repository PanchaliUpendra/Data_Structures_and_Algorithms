#include <bits/stdc++.h>
using namespace std;
long long dp[1000][1000];

long long sum(int a[], int i, int j)
{    
    long long ans = 0;
    for (int m = i; m <= j; m++)    
        ans = (ans + a[m]) % 100;
    return ans;
}
 
long long solve(int a[], int i, int j)
{
    
    if (i == j)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];
     
   
    dp[i][j] = INT_MAX;
     
    
    for (int k = i; k < j; k++)
    {
      
        dp[i][j] = min(dp[i][j], (solve(a, i, k) +
                              solve(a, k + 1, j) +
              (sum(a, i, k) * sum(a, k + 1, j))));
    }
     
   
    return dp[i][j];
}
 
void initialize(int n)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;    
}
 
int main() {
    int a[] = {40, 60, 20};
    int n = sizeof(a) / sizeof(a[0]);
    initialize(n);
    cout << solve(a, 0, n - 1) << endl;
    return 0;
}
