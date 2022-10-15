//edit string distance;

//simple recursion solution

/*
#include<bits/stdc++.h>
using namespace std;
int edit(string s1,string s2,int m,int n){
	if(m==0) return n;
	if(n==0) return m;
	if(s1[m-1]==s2[n-1]){
		return edit(s1,s2,m-1,n-1);
	}
	return 1+min(edit(s1,s2,m-1,n),min(edit(s1,s2,m,n-1),edit(s1,s2,m-1,n-1)));
}
int main(){
	string s1,s2;
	cout<<"enter your first string: ";
	cin>>s1;
	cout<<"enter your second string: ";
	cin>>s2;
	cout<<"the output is: "<<edit(s1,s2,s1.size(),s2.size());
	return 0;
}
*/

//using dynamic programming

#include<bits/stdc++.h>
using namespace std;
int edit(string s1,string s2){
	int m=s1.size(),n=s2.size();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++) dp[i][0]=i;
	for(int i=0;i<=n;i++) dp[0][i]=i;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
			}
		}
	}
	return dp[m][n];
	
}
int main(){
	string s1,s2;
	cout<<"enter the first string: ";
	cin>>s1;
	cout<<"enter the second string: ";
	cin>>s2;
	cout<<"output is: "<<edit(s1,s2);
	return 0;
}
