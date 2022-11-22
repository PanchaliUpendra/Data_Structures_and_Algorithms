//Minimum steps to minimize n as per given condition
#include<bits/stdc++.h>
using namespace std;
int funans(int n,vector<int>&memo){
	if(n==1){
		memo[n]=0;
		return memo[n];
	}
	if(memo[n]!=-1) return memo[n];
	int res=funans(n-1,memo);
	if(n%2==0) res=min(res,funans(n/2,memo));
	if(n%3==0) res=min(res,funans(n/3,memo));
	memo[n]=1+res;
	return memo[n];
	
}
int main(){
	int n;
	cout<<"enter the value of n: ";
	cin>>n;
	vector<int>memo(n+1,-1);
	cout<<"the minimum stps are: "<<funans(n,memo)<<endl;
	return 0;
}
