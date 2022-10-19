// gold main program using simple recursion

//Recursion Solution

/*
#include<bits/stdc++.h>
using namespace std;
int collect(vector<vector<int>>gold,int x,int y,int m,int n){
	if((x<0)||(x==n)||(y==m)){
		return 0;
	}
	int rightupper=collect(gold,x-1,y+1,m,n);
	int right=collect(gold,x,y+1,m,n);
	int rightbottom=collect(gold,x+1,y+1,m,n);
	
	return gold[x][y]+max(rightupper,max(right,rightbottom));
}
int getMaxGold(vector<vector<int>>gold,int m,int n){
	int maxGold=0;
	for(int i=0;i<n;i++){
		int goldcollected=collect(gold,i,0,n,m);
		maxGold=max(maxGold,goldcollected);
	}
	return maxGold;
}
int main(){
	int m,n;
	cout<<"Enter no.of rows: ";
	cin>>m;
	cout<<"enter no.of col: ";
	cin>>n;
	vector<vector<int>>v(m,vector<int>(n,-1));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>v[i][j];
		}
	}
	cout<<"the maximum gold is: "<<getMaxGold(v,m,n);
	return 0;
}
*/

// simple solution using dynamic Programming 

#include<bits/stdc++.h>
using namespace std;
int collect(vector<vector<int>>gold,int x,int y,int m,int n,vector<vector<int>>&dp){
	
	if((x<0)||(x==n)||(y==m)) return 0;
	
	if(dp[x][y]!=-1) return dp[x][y];
	
	int rightupper=collect(gold,x-1,y+1,m,n,dp);
	int right=collect(gold,x,y+1,m,n,dp);
	int rightbottom=collect(gold,x+1,y+1,m,n,dp);
	
	dp[x][y]=gold[x][y]+max(rightupper,max(right,rightbottom));
	return dp[x][y];
}
int getMaxGold(vector<vector<int>>gold,int m,int n){
	int maxGold=0;
	vector<vector<int>>dp(m,vector<int>(n,-1));
	for(int i=0;i<n;i++){
		int goldcollected=collect(gold,i,0,n,m,dp);
		maxGold=max(maxGold,goldcollected);
	}
	return maxGold;
}
int main(){
	int m,n;
	cout<<"Enter no.of rows: ";
	cin>>m;
	cout<<"enter no.of col: ";
	cin>>n;
	vector<vector<int>>v(m,vector<int>(n,-1));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>v[i][j];
		}
	}
	cout<<"the maximum gold is: "<<getMaxGold(v,m,n);
	return 0;
}
