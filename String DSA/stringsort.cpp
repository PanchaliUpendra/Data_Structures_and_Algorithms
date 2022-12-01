#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	
	unordered_map<char,int>m;
	vector<pair<int,char>>v;
	unordered_map<char,bool>visited;
	unordered_map<int,vector<char>>temp;
	
	for(int i=0;i<str.size();i++) m[str[i]]++;
	
	for(auto x:m){
		v.push_back({x.second,x.first});
	}
	
	sort(v.rbegin(),v.rend());
	string ans="";
	
	for(auto x:v){
		temp[x.first].push_back(x.second);
	}
	for(auto x:v){
		int z=x.first;
		if(!visited[x.second]){
			sort(temp[z].begin(),temp[z].end());
			for(int i=0;i<temp[z].size();i++){
				visited[temp[z][i]]=true;
				for(int j=0;j<z;j++){
					ans+=temp[z][i];
				}
			}
		}
		
	}
	cout<<ans;
	return 0;
	
}
