//Size of The Subarray With Maximum Sum

//first find the maximum sum;
/*
#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>&arr,int i,int sum,int n){
	if(i==n) return 0;
	return max(arr[i]+funans(arr,i+1,sum+arr[i],n),funans(arr,i+1,sum,n));
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	cout<<"enter the elements of the array: "<<endl;
	vector<int>arr(n,-1);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"the maximum sum is: "<<funans(arr,0,0,n);
	
	return 0;
}
*/

//by using the priority queue

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"enter the value of n: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter the array elements: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	priority_queue<int>q;
	for(auto x:v) q.push(x);
	int maxi=INT_MIN;
	int sum=0;
	while(!q.empty()){
		maxi=max(maxi,sum+q.top());
		sum=maxi;
		q.pop();
	}
	cout<<"the maximum sum is: "<<maxi<<endl;
	return 0;
}
