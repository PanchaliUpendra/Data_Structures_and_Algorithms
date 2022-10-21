
//Newman - Conway Sequence

/*

Newman-Conway sequence is the one that generates the following integer sequence
112234445677..

in mathematical terms , the sequence P(n) of Newton-conway numbers is defined by the 
recurrence relation

P(n)=P(P(n-1))+P(n-P(n-1))

P(1)=1,P(2)=1

*/

//simple recursion solution using C++

/*
#include<bits/stdc++.h>
using namespace std;
int sequence(int n){
	if(n==1||n==2) return 1;
	return sequence(sequence(n-1))+sequence(n-sequence(n-1));
}
int main(){
	int n;
	cout<<"enter the value of n: ";
	cin>>n;
	cout<<"the sequence of n is: "<<sequence(n)<<endl;
	return 0;
}
*/
//using dynamic Programming in C++
#include<bits/stdc++.h>
using namespace std;
int sequence(int n){
	int f[n+1];
	f[0]=1;
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=n;i++){
		f[i]=f[f[i-1]]+f[i-f[i-1]];
	}
	return f[n];
}
int main(){
	int n;
	cout<<"enter the value of n: ";
	cin>>n;
	cout<<"the sequence of n is: "<<sequence(n)<<endl;
	return 0;
}

