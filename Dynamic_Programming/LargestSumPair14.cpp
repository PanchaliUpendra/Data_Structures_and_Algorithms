#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>v,int n){
	sort(v.begin(),v.end());
	int maxi=INT_MIN,count,temp;
	for(int i=0;i<n-1;i++){
		count=1;
		temp=v[i];
		for(int j=i+1;j<n;j++){
			if(v[j]%temp==0){
				count=count+1;
				temp=v[j];
			}
		}
		maxi=max(maxi,count);
	}
	return maxi;
}
int main(){
	int n;
	cout<<"enter the size of the array: "<<ends;
	cin>>n;
	vector<int>v(n,-1);
	cout<<"enter "<<n<<" elements of the array: "<<endl;
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<"maxi ans:"<<fun(v,n);
	return 0;
}
