//Matrix Chain Multiplication

//simple recursion solution using C++

/*
#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>v,int i,int j){
	if(i==j) return 0;
	int mini=INT_MAX,count;
	for(int k=i;k<j;k++){
		count=funans(v,i,k)+funans(v,k+1,j)+v[i-1]*v[k]*v[j];
		mini=min(mini,count);
	}
	return mini;
	
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<"the minimum no.of multiplication of sequence of an array: "<<funans(v,1,n-1);
	return 0;
}

*/

//using memoization in dynamic programming
#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>v,int i,int j,vector<vector<int>>&dp){
	if(i==j) return 0;
	dp[i][j]=INT_MAX;
	for(int k=i;k<j;k++){
		dp[i][j]=min(dp[i][j],funans(v,i,k,dp)+funans(v,k+1,j,dp)+v[i-1]*v[k]*v[j]);
	}
	return dp[i][j];
	
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	cout<<"the minimum no.of multiplication of sequence of an array: "<<funans(v,1,n-1,dp);
	return 0;
}
