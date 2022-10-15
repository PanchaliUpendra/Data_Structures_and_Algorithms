#include<bits/stdc++.h>
using namespace std;
int cmodp(int n,int k,int p,vector<vector<int>>&dp){
	if(dp[n][k]!=-1) return dp[n][k];
	if(k>n){
		dp[n][k]=0;
		return dp[n][k];
	}
	if(k==0||k==n){
		dp[n][k]=1;
		return dp[n][k];
	}
	dp[n][k]=(cmodp(n-1,k-1,p,dp)%p+cmodp(n-1,k,p,dp)%p)%p;
	return dp[n][k];
}
int main(){
	int n,k,p;
	cout<<"enter the value of n: ";
	cin>>n;
	cout<<"enter the value of k: ";
	cin>>k;
	cout<<"enter the value of p: ";
	cin>>p;
	vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
	cout<<"the out the function is : "<<cmodp(n,k,p,dp);
	return 0;
}
