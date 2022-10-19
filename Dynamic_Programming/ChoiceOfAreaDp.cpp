#include<bits/stdc++.h>
using namespace std;
struct area{
	int a,b;
	area(int a1,int b1){
		a=a1;
		b=b1;
	}
};
int maxiser(int a,int b,area X,area Y,area Z,int last,map<pair<int,int>,int>&dp){
	if(a<=0||b<=0) return 0;
	pair<int,int>cur=make_pair(a,b);
	if(dp.find(cur)!=dp.end()){
		return dp[cur];
	}
	int temp;
	switch(last){
		case 1:
			temp=1+max(maxiser(a+Y.a,b+Y.b,X,Y,Z,2,dp),maxiser(a+Z.a,b+Z.b,X,Y,Z,3,dp));
			break;
		case 2:
			temp=1+max(maxiser(a+X.a,b+X.b,X,Y,Z,1,dp),maxiser(a+Z.a,b+Z.b,X,Y,Z,3,dp));
			break;
		case 3:
			temp=1+max(maxiser(a+X.a,b+X.b,X,Y,Z,1,dp),maxiser(a+Y.a,b+Y.b,X,Y,Z,2,dp));
			break;
	}
	dp[cur]=temp;
	return temp;
}
int maxserv(int a,int b,area X,area Y,area Z){
	if(a<=0||b<=0) return 0;
	map<pair<int,int>,int>dp;
	return max(maxiser(a+X.a,b+X.b,X,Y,Z,1,dp),max(maxiser(a+Y.a,b+Y.b,X,Y,Z,2,dp),maxiser(a+Z.a,b+Z.b,X,Y,Z,3,dp)));
}

int main(){
	area X(3,2);
	area Y(-5,-10);
	area Z(-20,5);
	int a=20,b=8;
	cout<<"the maximum servival time is : "<<maxserv(20,8,X,Y,Z)<<endl;
	return 0;
}
