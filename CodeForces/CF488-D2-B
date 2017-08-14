/*
   idea:
   - calculating the total number of rows completely asked
   - similarly total number of full cycles 1->n->2 (ex.1,2,3,4,3,2)
   - min number would be total cycles,max would be total cycles*2
   - remainder of rows not in a complete cycle could be iterated through since max n=100 so iterations won't exceed 200
   - from the previous i can get values of total asked questions for each row excluding the remainder of questions not in a complete row
   - if y is <= remainder of questions not in complete row then if sergi is in the row which is currently being filled 
   then his value is that of the row's+1...else jut the value of the row
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define repe(i,x,n) for(int i=x;i<=n;i++)
#define repn(i,x,n) for(int i=x;i>=n;i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define mod 1000000007

typedef long long ll;

const double PI=3.14159265;

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	ll k;
	int x,y;
	while(cin>>n>>m>>k>>x>>y){
		/*if(k<m){
			cout<<"1 0 ";
			if(y<=k)cout<<1<<endl;
			else cout<<0<<endl;
			continue;
		}
		else if(k==m){
			cout<<"1 1 1"<<endl;
			continue;
		}*/
		x--;
		ll rnds=k/m;
		ll cycl=rnds/(n>2?2*n-2:n);
		ll mx,mn,ss;
		mn=cycl;
		mx=n>2?cycl*2:cycl;
		vector<ll>v(n,mx);
		v[0]=v[n-1]=mn;
		ll lft=rnds%(n>2?2*n-2:n);
		int i=0;
		bool dn=true;
		while(lft){
			v[i]++;
			lft--;
			if(dn&&i==n-1)dn=false;
			else if(!dn&&i==0)dn=true;
			if(dn)i++;
			else i--;
		}
		//rep(i,0,v.size())cout<<v[i]<<endl;
		mn=*min_element(all(v));
		mx=*max_element(all(v));
		if(k%m)mx=max(mx,v[i]+1);
		if(x==i){
			if(k%m&&y<=k%m)ss=v[i]+1;
			else ss=v[i];
		}
		else
			ss=v[x];
		cout<<mx<<" "<<mn<<" "<<ss<<endl;
	}

	return 0;
}
