//Maximum sum of pairs with specific difference

#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>arr,int n,int k){
	int dp[n];
	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1];
		if(arr[i]-arr[i-1]<k){
			if(i>=2){
				dp[i]=max(dp[i],dp[i-2]+arr[i]+arr[i-1]);
			}
			else{
				dp[i]=max(dp[i],arr[i]+arr[i-1]);
			}
		}
	}
	return dp[n-1];
}
int main(){
	int n;
	cout<<"enter the esize of the array: ";
	cin>>n;
	vector<int>arr(n);
	cout<<"enter the elements of array: "<<endl;
	for(int i=0;i<n;i++) cin>>arr[i];
	int k;
	cout<<"enter the value of k: ";
	cin>>k;
	cout<<"the maximum sum of the disjoint pair's is: "<<funans(arr,n,k)<<endl;
	return 0;
}
