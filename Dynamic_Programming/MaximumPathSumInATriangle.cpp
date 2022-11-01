//Maximum path sum in a triangle

//using simple recursion using c++

/*
#include<bits/stdc++.h>
using namespace std;

int maxpathsum(vector<vector<int>>tri,int i,int j,int m,int n){
	if(j==n){
		return 0;
	}
	if(i==m-1){
		return tri[i][j];
	}
	return tri[i][j]+max(maxpathsum(tri,i+1,j,m,n),maxpathsum(tri,i+1,j+1,m,n));
}

int main(){
	int m,n;
	cout<<"no.of rows: ";
	cin>>m;
	cout<<"no.of cols: ";
	cin>>n;
	vector<vector<int>>tri(m,vector<int>(n,-1));
	cout<<"enter the elements of the triangle: "<<endl;
	for(int i=0;i<m;i++){
		cout<<"enter "<<i<<" row elements: "<<endl;
		for(int j=0;j<n;j++){
			cin>>tri[i][j];
		}
	}
	cout<<"Maximum path sum in a triangle: "<<maxpathsum(tri,0,0,m,n)<<endl;
	
	return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

int maxpathsum(vector<vector<int>>tri,int i,int j,int m,int n,vector<vector<int>>&dp){
	if(j==n){
		return 0;
	}
	if(i==m-1){
		return tri[i][j];
	}
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]= tri[i][j]+max(maxpathsum(tri,i+1,j,m,n,dp),maxpathsum(tri,i+1,j+1,m,n,dp));
	return dp[i][j];
}

int main(){
	int m,n;
	cout<<"no.of rows: ";
	cin>>m;
	cout<<"no.of cols: ";
	cin>>n;
	vector<vector<int>>tri(m,vector<int>(n,-1));
	vector<vector<int>>dp(m,vector<int>(n,-1));
	cout<<"enter the elements of the triangle: "<<endl;
	for(int i=0;i<m;i++){
		cout<<"enter "<<i<<" row elements: "<<endl;
		for(int j=0;j<n;j++){
			cin>>tri[i][j];
		}
	}
	cout<<"Maximum path sum in a triangle: "<<maxpathsum(tri,0,0,m,n,dp)<<endl;
	
	return 0;
}
