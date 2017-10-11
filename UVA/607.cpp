#include<bits/stdc++.h>
using namespace std;

int n,L,C;
vector<int>v;

int calcDI(int t){
	if(t==0)
		return 0;
	if(t>=1&&t<=10)
		return -C;
	return (t-10)*(t-10);
}
const int def=1000000;
pair<int,int> dp[1005][505];
pair<int,int> go(int ind,int lft){
	if(ind==n)
		return make_pair(1,calcDI(lft));
	if(dp[ind][lft]!=make_pair(def,def))
		return dp[ind][lft];
	pair<int,int> ret=make_pair(1e5,1e9);
	if(lft>=v[ind])
		ret=min(ret,go(ind+1,lft-v[ind]));
	pair<int,int>tmp=go(ind+1,L-v[ind]);
	tmp.first+=1,tmp.second+=calcDI(lft);
	ret=min(ret,tmp);
	return dp[ind][lft]=ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt=1;
	bool ex=false;
	while(cin>>n){
		if(n==0)
			return 0;
		if(ex)
			cout<<"\n";
		cin>>L>>C;
		v.resize(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		for(int i=0;i<1005;i++)
			for(int j=0;j<505;j++)
				dp[i][j].first=dp[i][j].second=def;
		pair<int,int>res=go(0,L);
		cout<<"Case "<<cnt<<":\nMinimum number of lectures: "<<res.first;
		cout<<"\nTotal dissatisfaction index: "<<res.second<<"\n";
		cnt++;
		ex=true;
	}
	return 0;
}
