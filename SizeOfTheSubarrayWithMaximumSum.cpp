//Size of The Subarray With Maximum Sum

#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>v,int n){
	int max_so_far=INT_MIN, max_end_here=0;
	int start=0,end=0,s=0;
	for(int i=0;i<n;i++){
		max_end_here+=v[i];
		if(max_so_far<max_end_here){
			max_so_far=max_end_here;
			start=s;
			end=i;
		}
		if(max_end_here<0){
			max_end_here=0;
			start=i+1;
		}
	}
	return (end-start+1);
}
int main(){
	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<"the length of the subarray of maximum sum is: "<<funans(v,n)<<endl;
	return 0;
}
