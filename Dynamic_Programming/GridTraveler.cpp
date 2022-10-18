// Grid Traveler

/* 
say that you are a traveler on a 2d grid . you begin i the top-left corner
and your goal is to travel to the bottom -right corner. you may only move down or right
*/

// -> In how many ways can you travel to the goal on a grid with dimensions m*n?

// Simple recursion solution in C++

/*
#include<bits/stdc++.h>
using namespace std;
int fun(int m,int n){
	if(m==1 and n==1) return 1;
	if(m==0 || n==0) return 0;
	return fun(m-1,n)+fun(m,n-1);
}
int main(){
	int m,n;
	cout<<"enter no.of rows in grid(m): ";
	cin>>m;
	cout<<"enter no.of cols in grid(n): ";
	cin>>n;
	cout<<"Number of ways : "<<fun(m,n)<<endl;
	
}
*/

// Using Memoization in dynamic programming

#include<bits/stdc++.h>
using namespace std;
long long fun(int m,int n,vector<vector<long long>>&dp){
	if(dp[m][n]!=-1) return dp[m][n];
	if(m==1 and n==1){
		dp[m][n]=1;
		return dp[m][n];
	}
	if(m==0||n==0){
		dp[m][n]=0;
		return dp[m][n];
	}
	dp[m][n]=fun(m-1,n,dp)+fun(m,n-1,dp);
}
int main(){
	int m,n;
	cout<<"enter no.of rows(m): ";
	cin>>m;
	cout<<"enter no.of cols(n): ";
	cin>>n;
	vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
	cout<<"no.of ways top get down is : "<<fun(m,n,dp);
	return 0;
}
