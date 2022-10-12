//Subset Sum Problem

/*
Given a set of non-negative integers, and a value sum, 
determine if there is a subset of the given set with sum 
equal to given sum. 
*/

// a simple recursion proble using C++ 
//method1:

#include<bits/stdc++.h>
using namespace std;
bool ans=false;
void fun(vector<int>v,int sum,int n){
	if(sum==0){
		ans=true;
		return;
	}
	if(n==0) return;
	if(sum>=v[n-1]){
		fun(v,sum-v[n-1],n-1);
	}else{
		fun(v,sum,n-1);
	}
	return;
}
bool subsetsum(vector<int>v,int sum){
	sort(v.begin(),v.end());
	fun(v,sum,v.size());
	return ans;
}
int main(){
	int n;
	cout<<"enter no.of elements you want: "<<ends;
	cin>>n;
	vector<int>v(n,-1);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int sum;
	cout<<"enter your sum: ";
	cin>>sum;
	if(subsetsum(v,sum)){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}
	return 0;
}
