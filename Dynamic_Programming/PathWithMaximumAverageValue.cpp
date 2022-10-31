//path with maximum average value

//using simple recursion in C++

/*
#include<bits/stdc++.h>
using namespace std;
int funmax(vector<vector<int>>grid,int m,int n){
	if(m==0 && n==0) return grid[m][n];
	int maxi=INT_MIN;
	if(m>0)
	{
		maxi=grid[m][n]+funmax(grid,m-1,n);
	}
	if(n>0){
		int s=grid[m][n]+funmax(grid,m,n-1);
		maxi=max(maxi,s);
	}
	return maxi;
	
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<vector<int>>grid(n,vector<int>(n,-1));
	cout<<"enter the values of the grid: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter the "<<i<<" row elements: "<<endl;
			for(int j=0;j<n;j++){
				cin>>grid[i][j];
			}
	}
	int maxi=funmax(grid,n-1,n-1);
	cout<<"the maximum value is: "<<maxi<<endl;
	cout<<"path with maximum average value is: "<<(float)maxi/(2*n-1);
	return 0;
}
*/

//2nd method using dynamic programming in C++

#include<bits/stdc++.h>
using namespace std;
int funmax(vector<vector<int>>grid,int m,int n,vector<vector<int>>&dp){
	if(m==0 && n==0){
		dp[m][n]=grid[m][n];
		return dp[m][n];
	}
	int maxi=INT_MIN;
	if(dp[m][n]!=-1) return dp[m][n];
	if(m>0)
	{
		maxi=grid[m][n]+funmax(grid,m-1,n,dp);
	}
	if(n>0){
		int s=grid[m][n]+funmax(grid,m,n-1,dp);
		maxi=max(maxi,s);
	}
	dp[m][n]=maxi;
	return dp[m][n];
	
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<vector<int>>grid(n,vector<int>(n,-1));
	cout<<"enter the values of the grid: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter the "<<i<<" row elements: "<<endl;
			for(int j=0;j<n;j++){
				cin>>grid[i][j];
			}
	}
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	int maxi=funmax(grid,n-1,n-1,dp);
	cout<<"the maximum value is: "<<maxi<<endl;
	cout<<"path with maximum average value is: "<<(float)maxi/(2*n-1);
	return 0;
}
