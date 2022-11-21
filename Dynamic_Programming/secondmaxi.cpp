// second highest number

#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>arr){
	int prev=0,prst=INT_MIN;
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++){
		if(arr[i]>prst){
			prev=prst;
			prst=arr[i];
		}
	}
	return prev;
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>arr(n,-1);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	cout<<"the second maxi is: "<<funans(arr)<<endl;
	return 0;
}
