//Maximum weight path ending at any element of last row in a matrix
//simple recursion using C++

/*
#include<bits/stdc++.h>
using namespace std;
int funans(vector<vector<int>>m,int i,int j,int n){
	if(j>=n) return 0;
	if(i==n-1) return m[i][j];
	return m[i][j]+max(funans(m,i+1,j,n),funans(m,i+1,j+1,n));
	
}
int main(){
	int n;
	cout<<"enter the size of the vector: ";
	cin>>n;
	vector<vector<int>>m(n,vector<int>(n,-1));
	cout<<"enter the elements of vector: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter the elements of "<<i<<" row: "<<endl;
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}
	cout<<"the maximum weight is: "<<funans(m,0,0,n)<<endl;
	return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int funans(vector<vector<int>>m,int i,int j,int n,vector<vector<int>>&dp){
	if(j>=n) return 0;
	if(i==n-1) return m[i][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int x= m[i][j]+max(funans(m,i+1,j,n,dp),funans(m,i+1,j+1,n,dp));
	dp[i][j]=x;
	return dp[i][j];
	
}
int main(){
	int n;
	cout<<"enter the size of the vector: ";
	cin>>n;
	vector<vector<int>>m(n,vector<int>(n,-1));
	cout<<"enter the elements of vector: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter the elements of "<<i<<" row: "<<endl;
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}
	vector<vector<int>>dp(n,vector<int>(n,-1));
	cout<<"the maximum weight is: "<<funans(m,0,0,n,dp)<<endl;
	return 0;
}
