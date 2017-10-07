#include<iostream>
#include<cstring>

using namespace std;

int m,n;
int p[105],f[105];
int dp[15005][105];
int go(int cursum,int indx){
	if(indx==n){
		if(cursum<=m||(cursum>2000&&cursum<=m+200))		
			return 0;

		return -20000;
	}
	if(dp[cursum][indx]!=-1)
		return dp[cursum][indx];
	int ret=0;
	int tmp=-1;
	if(cursum+p[indx]<=m+200)
		tmp=go(cursum+p[indx],indx+1)+f[indx];
	ret=go(cursum,indx+1);
	if(tmp>=0||ret>=0)
		ret=max(ret,tmp);
	return dp[cursum][indx]=ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	while(cin>>m>>n){
		memset(p,0,sizeof p);
		memset(f,0,sizeof f);
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++)
			cin>>p[i]>>f[i];
		cout<<go(0,0)<<endl;
	}
}
