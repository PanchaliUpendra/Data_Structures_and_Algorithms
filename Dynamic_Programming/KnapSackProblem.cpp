
//0-1 knapsack Problem 

//using simple recursion in C++

/*
#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,vector<int>wt,vector<int>val,int n){
	if(n==0||W==0) return 0;
	if(wt[n-1]>W){
		return knapsack(W,wt,val,n-1);
	}
	
	return max(knapsack(W,wt,val,n-1),val[n-1]+knapsack(W-wt[n-1],wt,val,n-1));
}
int main(){
	int n,W;
	cout<<"enter the size of an array: ";
	cin>>n;
	vector<int>val(n,-1);
	cout<<"enter the elements of value array: "<<endl;
	for(int i=0;i<n;i++) cin>>val[i];
	vector<int>wt(n,-1);
	cout<<"enter the elements of weights array: "<<endl;
	for(int i=0;i<n;i++) cin>>wt[i];
	cout<<"enter your weight: ";
	cin>>W;
	cout<<"the maximum value is: "<<knapsack(W,wt,val,n);
	
	return 0;
}
*/

//using dynamic programming in C++

#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,vector<int>wt,vector<int>val,int n,vector<vector<int>>&dp){
	if(n==0||W==0){
		dp[n][W]=0;
		return dp[n][W];
	}
	if(dp[n][W]!=-1) return dp[n][W];
	if(wt[n-1]>W){
		dp[n][W]= knapsack(W,wt,val,n-1,dp);
		return dp[n][W];
	}
	
	dp[n][W]= max(knapsack(W,wt,val,n-1,dp),val[n-1]+knapsack(W-wt[n-1],wt,val,n-1,dp));
	return dp[n][W];
}
int main(){
	int n,W;
	cout<<"enter the size of an array: ";
	cin>>n;
	vector<int>val(n,-1);
	cout<<"enter the elements of value array: "<<endl;
	for(int i=0;i<n;i++) cin>>val[i];
	vector<int>wt(n,-1);
	cout<<"enter the elements of weights array: "<<endl;
	for(int i=0;i<n;i++) cin>>wt[i];
	cout<<"enter your weight: ";
	cin>>W;
	
	vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
	cout<<"the maximum value is: "<<knapsack(W,wt,val,n,dp);
	
	return 0;
}
