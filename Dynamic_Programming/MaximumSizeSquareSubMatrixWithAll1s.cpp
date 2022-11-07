/*
Maximum size square sub-matrix with all 1s

Difficulty Level : Medium
Last Updated : 31 Oct, 2022
Given a binary matrix, find out the maximum size square sub-matrix with all 1s. 
For example, consider the below binary matrix. 
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> funans(vector<vector<int>>M,int m,int n){
	vector<vector<int>>S(m,vector<int>(n,0));
	for(int i=0;i<m;i++) S[i][0]=M[i][0];
	for(int i=0;i<n;i++) S[0][i]=M[0][i];
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(M[i][j]==1){
				S[i][j]=min(M[i][j-1],min(M[i-1][j],M[i-1][j-1]))+1;
			}else{
				S[i][j]=0;
			}
		}
	}
	return S;
}

int main(){
	int m,n;
	cout<<"enter the number of rows: ";
	cin>>m;
	cout<<"enter the no.of columns: ";
	cin>>n;
	vector<vector<int>>M(m,vector<int>(n,-1)),S;
	cout<<"enter the matrix: "<<endl;
	for(int i=0;i<m;i++){
		cout<<"enter the "<<i<<" row elements: "<<endl;
		for(int j=0;j<n;j++){
			cin>>M[i][j];
		}
	}
	S=funans(M,m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<S[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
