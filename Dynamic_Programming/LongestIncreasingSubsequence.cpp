// Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std ;

int lis(vector<int>v,int n){
	vector<int>list(n,-1);
	list[0]=1;
	for(int i=1;i<n;i++){
		list[i]=1;
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				list[i]=max(list[i],list[j]+1);
			}
		}
	}
	return *max_element(list.begin(),list.end());
}

int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter the array elements: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<"the output is : "<<lis(v,n);
	return 0;
}
