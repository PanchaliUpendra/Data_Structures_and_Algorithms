
//Minimum Jumps To Reach The End

//simple recursion solution using C++

/*


#include<bits/stdc++.h>
using namespace std;


int minoper(vector<int>&arr,int n,int i){
	if(i>=n) return -1;
	if(i==n-1) return 0;
	int mini=INT_MAX;
	for(int j=1;j<=arr[i];j++){
		int x=minoper(arr,n,i+j);
		if(x!=-1){
			mini=min(mini,x+1);
		}
	}
	return mini;
}


int main(){
	int n;
	cout<<"enter the array size: "<<endl;
	cin>>n;
	vector<int>arr(n,-1);
	cout<<"enter your array elements: "<<endl;
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"the no.of min operations are: "<<minoper(arr,n,0);
	return 0;
}

*/


//second method of recursion from back side;
/*
#include<bits/stdc++.h>
using namespace std;

int minfun(vector<int>arr,int n){
	if(n==1) return 0;
	int res=INT_MAX;
	for(int i=0;i<=n-2;i++){
		if(i+arr[i]>=n-1){
			int sub_res=minfun(arr,i+1);
			if(sub_res!=INT_MAX){
				res=min(res,sub_res+1);
			}
		}
	}
	return res;
}

int main(){
	int n;
	cout<<"enter the size of the array: "<<endl;
	cin>>n;
	vector<int>arr(n,-1);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"the min no.of ways are: "<<minfun(arr,n)<<endl;
	return 0;
}
*/

//using dynamic programming in C++

#include<bits/stdc++.h>
using namespace std;

int minfun(vector<int>arr,int n){
	int dp[n];
	dp[0]=0;
	for(int i=1;i<n;i++) dp[i]=INT_MAX;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]+j>=i){
				if(dp[j]!=INT_MAX){
					dp[i]=min(dp[i],dp[j]+1);
				}
			}
		}
	}
	return dp[n-1];
}

int main(){
	int n;
	cout<<"enter the size of the array: "<<endl;
	cin>>n;
	vector<int>arr(n,-1);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"the min no.of ways are: "<<minfun(arr,n)<<endl;
	return 0;
}

