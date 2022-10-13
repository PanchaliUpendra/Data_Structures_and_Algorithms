#include<bits/stdc++.h>
using namespace std;
int getcount(vector<int> v,int n,int sum,vector<vector<int>>&dp){
	if(sum==0){
		dp[sum][n]=1;
		return dp[sum][n];
	}
	if(n==0){
		dp[sum][n]=0;
		return dp[sum][n];
	}
	if(dp[sum][n]!=-1) return dp[sum][n];
	int res=getcount(v,n-1,sum,dp);
	if(v[n-1]<=sum){
		res+=getcount(v,n,sum-v[n-1],dp);
	}
	dp[sum][n]=res;
	return dp[sum][n];
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter your array elements: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	int sum;
	cout<<"enter your sum value : ";
	cin>>sum;
	vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
	cout<<"the no.of ways are : "<<getcount(v,n,sum,dp)<<endl;
	return 0;
}
