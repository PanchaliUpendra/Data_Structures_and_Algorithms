//Maximum Cuts

//using simple recursion in C++

/*
#include<bits/stdc++.h>
using namespace std;
int fun(int n,int a,int b,int c){
	if(n<0) return -1;
	if(n==0) return 0;
	int res=max(fun(n-a,a,b,c),max(fun(n-b,a,b,c),fun(n-c,a,b,c)));
	if(res==-1) return res;
	return res+1;
}
int  main(){
	int n;
	cout<<"enter the length of the rod: ";
	cin>>n;
	int a,b,c;
	cout<<"enter the value of a: ";
	cin>>a;
	cout<<"enter the value of b: ";
	cin>>b;
	cout<<"enter the value of c: ";
	cin>>c;
	cout<<"the final output is: "<<fun(n,a,b,c)<<endl;
	return 0;
}
*/

// maximum cuts using tabulation in dp

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c;
	cout<<"enter the length of the rod: ";
	cin>>n;
	cout<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	cout<<"c: ";
	cin>>c;
	
	int dp[n+1];
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=-1;
		if(i-a>=0) dp[i]=max(dp[i],dp[i-a]);
		if(i-b>=0) dp[i]=max(dp[i],dp[i-b]);
		if(i-c>=0) dp[i]=max(dp[i],dp[i-c]);
		if(dp[i]!=-1){
			dp[i]++;
		}
	}
	cout<<"the final output is : "<<dp[n];
	return 0;
}
