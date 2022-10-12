//Subset with sum divisible by m

/*
Given a set of non-negative distinct integers, 
and a value m, determine if there is a subset of the 
given set with sum divisible by m. 
*/

//1st method using simple recursion in C++

/*
#include<bits/stdc++.h>
using namespace std;
bool fun(vector<int>v,int m,int sum,int z){
	if(sum%m==0 and sum>0) return true;
	if(z==0) return false;
	return fun(v,m,sum+v[z-1],z-1)||fun(v,m,sum,z-1);
}
int main(){
	int n,m;
	cout<<"enter your vector size: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter vector elements: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<"enter your divisible number: "<<ends;
	cin>>m;
	sort(v.begin(),v.end());
	if(fun(v,m,0,n)){
		cout<<"True"<<endl;
	}
	else{
		cout<<"False"<<endl;
	}
}
*/

// using dynamic programming 

#include<bits/stdc++.h>
using namespace std;

bool fun(vector<int>v,int m,int sum,int N,int idx,vector<vector<int>>&dp){
	if (idx == N){
        if (sum && sum % m == 0){
            return true;
        }
        return false;
    }
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    dp[idx][sum]=fun(v,m,sum+v[idx],N,idx+1,dp)||fun(v,m,sum+v[idx],N,idx+1,dp);
    return dp[idx][sum];
	}
int main(){
	int n,m,sum=0;
	cout<<"enter size of the array: "<<ends;
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter array elements: "<<endl;
	for(int i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	cout<<"enter your divisible : ";
	cin>>m;
	vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	if(fun(v,m,sum,n,0,dp)){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}
	return 0;
}
