//Maximum sum of a path in a Right Number Triangle

#include<bits/stdc++.h>
using namespace std;
int funans(vector<vector<int>>&grid,int r,int c,int m,int n, vector<vector<int>>&dp){
	if(r==m) return 0;
	if(dp[r][c]!=-1) return dp[r][c];
	dp[r][c]=grid[r][c]+min(funans(grid,r+1,c+1,m,n,dp),funans(grid,r+1,c,m,n,dp));
	return dp[r][c];
	
}
int main(){
	int n;
	cout<<"enter the value of n(row and col): ";
	cin>>n;
	vector<vector<int>>grid(n,vector<int>(n,-1));
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter the values of "<<i<<" row: "<<endl;
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	cout<<"the minimum sum of the triangle is: "<<funans(grid,0,0,n,n,dp);
	return 0;
}
