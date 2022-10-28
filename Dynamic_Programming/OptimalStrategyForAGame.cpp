// Optimal strategy for a game

#include<bits/stdc++.h>
using namespace std;
int sol(vector<int>arr,int i,int j,int sum){
	if(j==i+1) return max(arr[i],arr[j]);
	return max(sum-sol(arr,i+1,j,sum-arr[i]),sum-sol(arr,i,j-1,sum-arr[j]));
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>arr(n,-1);
	cout<<"enter the array elements: "<<endl;
	for(int i=0;i<n;i++) cin>>arr[i];
	int sum=0;
	for(int i=0;i<n;i++) sum+=arr[i];
	cout<<"the final solution is : "<<sol(arr,0,n-1,sum);
	return 0;
}
