#include <bits/stdc++.h>
using namespace std;

string s,t;
int trans[1005][1005];
int dp[1005][1005];
pair<int,int> op[4];

int go(int sind,int tind){
	if(sind==s.length()&&tind==t.length())
		return 0;
	if(dp[sind][tind]!=-1)
		return dp[sind][tind];
	int ret=1e9;
	if(sind<s.length()&&tind<t.length()&&s[sind]==t[tind]){
		ret=go(sind+1,tind+1);
		trans[sind][tind]=0;
	}
	else if(sind<s.length()&&tind<t.length()&&s[sind]!=t[tind]){
		ret=go(sind+1,tind+1)+1;
		trans[sind][tind]=1;
	}
	int tmp=1e9;
	if(sind<s.length()){
		tmp=go(sind+1,tind)+1;
		if(tmp<ret)
			ret=tmp,trans[sind][tind]=2;
	}
	if(tind<t.length()){
		tmp=go(sind,tind+1)+1;
		if(tmp<ret)
			ret=tmp,trans[sind][tind]=3;
	}
	return dp[sind][tind]=ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s>>t;
	memset(dp,-1,sizeof dp);
	op[0].first=1,op[0].second=1; //no change
	op[1].first=1,op[1].second=1; //replace
	op[2].first=1,op[2].second=0; //delete
	op[3].first=0,op[3].second=1; //insert
	cout<<go(0,0)<<endl;
	int x=0,y=0;
	int d=0,in=0;
	while(x<s.length()||y<t.length()){
		int o=trans[x][y];
		if(o==1)
			cout<<"REPLACE "<<x+1+in-d<<" "<<t[y]<<endl;
		else if(o==2){
			cout<<"DELETE "<<x+1+in-d<<" "<<endl;
			d++;
		}
		else if(o==3){
			cout<<"INSERT "<<x+1+in-d<<" "<<t[y]<<endl;
			in++;
		}
		x+=op[o].first;
		y+=op[o].second;
	}
}
