//Minimum number of jumps to reach end

//simple recursion using C++
/*
#include <bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n)
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
 
    return res;
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}*/
//using dynamic programming in c++

#include<bits/stdc++.h>
using namespace std;
int minjumps(vector<int>v,int n){
	int dp[n];
	dp[0]=0;
	for(int i=1;i<n;i++) dp[i]=INT_MAX;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(v[j]+j>=i){
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
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int>v(n,-1);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<"the mini no.of ways are: "<<minjumps(v,n)<<endl;
	return 0;
}
