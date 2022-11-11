//maximum no.of segemnt of length in C++

// using dynamic programming memoization

/*
#include<bits/stdc++.h>
using namespace std;
int funans(int sum,int a,int b,int c,vector<int>&dp){
	if(sum==0) return 0;
	if(sum<0) return -1;
	if(dp[sum]!=-1) return dp[sum];
	int maxi= max(funans(sum-a,a,b,c,dp),max(funans(sum-b,a,b,c,dp),funans(sum-c,a,b,c,dp)));
	if(maxi!=-1){
		dp[sum]=maxi+1;
		return dp[sum];
	}
	dp[sum]=maxi;
	return dp[sum];
}
int main(){
	int sum,a,b,c;
	cout<<"enter your sum: ";
	cin>>sum;
	cout<<"enter the values of a,b and c: "<<endl;
	cin>>a>>b>>c;
	vector<int>dp(sum+1,-1);
	cout<<"the maximum no.of segments are: "<<funans(sum,a,b,c,dp)<<endl;
}

*/

//using tabulation in C++
#include <bits/stdc++.h>
using namespace std;
 
// function to find the maximum
// number of segments
int maximumSegments(int n, int a,
                    int b, int c)
{
    // stores the maximum number of
    // segments each index can have
    int dp[n + 1];
     
    // initialize with -1
    memset(dp, -1, sizeof(dp));
 
    // 0th index will have 0 segments
    // base case
    dp[0] = 0;
 
    // traverse for all possible
    // segments till n
    for (int i = 0; i < n; i++)
    {
        if (dp[i] != -1) {
             
            // conditions
        if(i + a <= n )    //avoid buffer overflow
                dp[i + a] = max(dp[i] + 1,
                            dp[i + a]);
                             
        if(i + b <= n ) //avoid buffer overflow
                dp[i + b] = max(dp[i] + 1,
                            dp[i + b]);
                             
        if(i + c <= n )    //avoid buffer overflow
                dp[i + c] = max(dp[i] + 1,
                            dp[i + c]);
        }
    }
    return dp[n];
}
 
// Driver code
int main()
{
    int n = 7, a = 5, b = 2, c = 5;
    cout << maximumSegments(n, a, b, c);
    return 0;
}
