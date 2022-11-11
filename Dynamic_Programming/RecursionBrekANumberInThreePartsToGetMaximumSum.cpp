//Recursively break a number in 3 parts to get maximum sum


//simple recursion using C++
/*
#include<bits/stdc++.h>
using namespace std;
int funans(int sum){
	if(sum==0||sum==1) return sum;
	return max(funans(sum/2)+funans(sum/3)+funans(sum/4),sum);
}
int main(){
	int n;
	cout<<"enter your number: ";
	cin>>n;
	cout<<"the maximum sum is: "<<funans(n)<<endl;
	return 0;
}
*/

//using tabulation using C++

#include<bits/stdc++.h>
using namespace std;
int funans(int sum){
	vector<int>dp(sum+1,-1);
	dp[0]=0,dp[1]=1;
	for(int i=2;i<=sum;i++){
		dp[i]=max(dp[i/2]+dp[i/3]+dp[i/4],i);
	}
	return dp[sum];
}
int main(){
	int n;
	cout<<"enter your number: ";
	cin>>n;
	cout<<"the maximum sum is: "<<funans(n)<<endl;
	return 0;
}
