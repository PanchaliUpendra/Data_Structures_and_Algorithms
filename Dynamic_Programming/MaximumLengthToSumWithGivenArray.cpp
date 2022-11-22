// maximum length to sum with given array

#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>v,int n,int sum){
	if(sum==0) return 0;
	int maxi=INT_MIN,x;
	for(int i=n;i>=0;i--){
		if(sum-v[i]>=0){
			x=funans(v,i,sum-v[i]);
			if(x!=INT_MIN){
				maxi=max(maxi,x);
			}
		}
	}
	return maxi+1;
	
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	for(int i=0;i<n;i++) cin>>v[i];
	int ans=funans(v,n-1,n);
	if(ans!=INT_MIN){
		cout<<"the maximum no.of partitions are: "<<ans<<endl;
	}else{
		cout<<"sum is not possible: "<<endl;
	}
	return 0;
}
