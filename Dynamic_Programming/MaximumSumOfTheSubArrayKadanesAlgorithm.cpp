// maximum sum of the subarray using C++

/*
kadane's algorithm:-
is to maintain  a variable  "max_ending_here" that stores the maximum sum continuous subarray ending
here at current index.and a variable "max_so_far" stores the maximum sum of continuous subarray 
find so far every time there is a +ve sum value  in "max_ending_here" compare it with "max_so_far"
 and update max_so_far ,if it is greater than max_so_far
 */



#include<bits/stdc++.h>
using namespace std;
int funans(vector<int>arr,int n){
	int max_so_far=INT_MIN,max_end_here=0;
	for(int i=0;i<n;i++){
		max_end_here+=arr[i];
		if(max_so_far<max_end_here){
			max_so_far=max_end_here;
		}
		if(max_end_here<0){
			max_end_here=0;
		}
	}
	return max_so_far;
	
}
int main(){
	int n;
	cout<<"enter the size of an array: ";
	cin>>n;
	vector<int>arr(n,-1);
	cout<<"enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"the maximum sum of subarray is: "<<funans(arr,n)<<endl;
}

