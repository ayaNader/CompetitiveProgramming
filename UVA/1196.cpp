#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>>v;
int dp[10005][105][105];
int go(int ind,int l,int m){
	if(ind==n)
		return 0;
	if(dp[ind][l][m]!=-1)
		return dp[ind][l][m];
	int ret=0;
	if(l>=v[ind].first&&m>=v[ind].second)
		ret=max(ret,go(ind+1,v[ind].first,v[ind].second)+1);
	ret=max(ret,go(ind+1,l,m));
	return dp[ind][l][m]=ret;
}
int main(){
	while(cin>>n){
		if(n==0)
			break;
		v.clear();
		v.resize(n);
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
		sort(v.rbegin(),v.rend());
		cout<<go(0,104,104)<<endl;
	}
	cout<<"*\n";
	return 0;
}
