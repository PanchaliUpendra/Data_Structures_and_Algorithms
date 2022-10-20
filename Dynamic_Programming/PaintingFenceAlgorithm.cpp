// Painting Fence Algorithm
// using dynamic programming 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"enter the value of n(no.of posts): ";
	cin>>n;
	int k;
	cout<<"enter the value of k(no.of colors): ";
	cin>>k;
	long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    long long mod = 1000000007;
 
    dp[1] = k;
    dp[2] = k * k;
 
    for (int i = 3; i <= n; i++) {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }
 
    cout<<"final output: "<<dp[n];
	return 0;
}
