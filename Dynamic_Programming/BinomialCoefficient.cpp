// Binomial coefficient 

// Using simple recursion in C++;

/*
#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int k){
	if(k>n) return 0;
	if(k==0||k==n) return 1;
	return ncr(n-1,k-1)+ncr(n-1,k);
}
int main(){
	int n,k;
	cout<<"enter the value of n: ";
	cin>>n;
	cout<<"enter the value of k: ";
	cin>>k;
	cout<<"the nCr of n and k: "<<ncr(n,k)<<endl;
	return 0;
}
*/

//using memoization in c++

/*
#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int k,vector<vector<int>>& dp){
	if(dp[n][k]!=-1){
		return dp[n][k];
	}
	if(k>n){
		dp[n][k]=0;
		return dp[n][k];
	}
	if(k==0||k==n){
		dp[n][k]=1;
		return dp[n][k];
	}
	dp[n][k]=ncr(n-1,k-1,dp)+ncr(n-1,k,dp);
	return dp[n][k];
}
int main(){
	int n,k;
	cout<<"enter the value of n: ";
	cin>>n;
	cout<<"enter the value of k: ";
	cin>>k;
	vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
	cout<<"output using memoization : "<<ncr(n,k,dp);
	return 0;
}
*/

//using tabulation in c++

#include<bits/stdc++.h>
using namespace std;
int ncr(int n,int k){
	int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
 
    return C[n][k];
	
}
int main(){
	int n,k;
	cout<<"enter the value of n: ";
	cin>>n;
	cout<<"enter the value of k: ";
	cin>>k;
	cout<<"tabulation output: "<<ncr(n,k);
	return 0;
}
