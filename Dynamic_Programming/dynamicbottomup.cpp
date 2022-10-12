#include<bits/stdc++.h>
using namespace std;

int find_opt(vector<int>pri,int n,vector<int>&r){
	
	
	r[0]=0;
	int q;
	for(int i=1;i<=n;i++){
	  q=INT_MIN;
		for(int j=1;j<=i;j++){
			if(q<pri[j]+r[i-j]){
				q=pri[j]+r[i-j];
			}
		}
		r[i]=q;
	}
	return q;
}
int main(){
	int n;
	cout<<"enter the value of n: "<<ends;
	cin>>n;
	vector<int>price(11,0);
	cout<<"enter the prices of the rod: "<<endl;
	for(int i=1;i<=10;i++){
		int z;
		cin>>z;
		price[i]=z;
	}
	vector<int>r(n+1,INT_MIN);
	int ans=find_opt(price,n,r);
	cout<<"the ans:"<<ans;
	
	return 0;
}
