
//simple recursion using C++

/*
#include<bits/stdc++.h>
using namespace std;
int mini=INT_MAX;
int fun(int sum,vector<int> v,int n){
	if(sum==0) return 0;
	int res=INT_MAX;
	for(int i=0;i<n;i++){
		if(v[i]<=sum){
			int subres=fun(sum-v[i],v,n);
			if(subres!=INT_MAX){
				res=min(res,subres+1);
			}
		}
	}
	return res;
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter the values of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	int sum;
	cout<<"enter your sum: ";
	cin>>sum;
	sort(v.rbegin(),v.rend());
	vector<int>dp(sum+1,-1);
	cout<<"the minimum no.of coins to make a value: "<<fun(sum,v,n)<<endl;
	return 0;
}
*/

// using dynamic programming in C++

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	int sum;
	cout<<"enter the sum : ";
	cin>>sum;
	
	// using tabulation in dynamic programming using C++
	int dp[sum+1];
	dp[0]=0;
	for(int i=1;i<=sum;i++) dp[i]=INT_MAX;
	for(int i=1;i<=sum;i++){
		for(int j=0;j<n;j++){
			if(v[j]<=i){
				int subres=dp[i-v[j]];
				if(subres!=INT_MAX){
				 dp[i]=min(dp[i],subres+1);	
				}
			}
		}
	}
	cout<<"the min no.of coins are: "<<dp[sum];
	
	return 0;
}
