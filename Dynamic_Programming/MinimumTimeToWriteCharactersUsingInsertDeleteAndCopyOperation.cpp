//Minimum time to write characters using insert, delete and copy operation

#include<bits/stdc++.h>
using namespace std;
int funans(int n,int i,int d,int c){
	if(n==1) return i;
	if(n<0) return INT_MAX;
	int x=INT_MAX,y=INT_MAX,z=INT_MAX;
	if(n%2==0){
		x=i+funans(n-1,i,d,c);
		y=c+funans(n/2,i,d,c);
	}
	else{
		 x=i+funans(n-1,i,d,c);

         y=c+i+funans(n/2,i,d,c);

         z=c+d+funans((n+1)/2,i,d,c);
	}
	return min(x,min(y,z));
}
int main(){
	int n;
	cout<<"enter the values of n: ";
	cin>>n;
	int i,d,c;
	cout<<"enter the value of insert: ";
	cin>>i;
	cout<<"enter the value of delete: ";
	cin>>d;
	cout<<"enter the value of copy: ";
	cin>>c;
	cout<<"the minimum time is: "<<funans(n,i,d,c)<<endl;
	return 0;
}
