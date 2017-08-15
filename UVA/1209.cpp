/*
   idea:
   - getting prev 10 permutations and next 10 then calculating min distance between two consectutive letters
   - maximizing the result
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
	string s1;
	while(cin>>s1){
		string s2=s1;
		vector<string>v;
		v.push_back(s1);
		int cnt=0;
		do
		{
			if(!cnt){cnt++;continue;}
			v.push_back(s1);
			if(cnt==10)break;
			cnt++;
		}while(next_permutation(all(s1)));
		cnt=0;
		do
		{
			if(!cnt){cnt++;continue;}
			v.push_back(s2);
			if(cnt==10)break;
			cnt++;
		}while(prev_permutation(all(s2)));
		sort(all(v));
		int mx=-1;
		string ans;
		rep(i,0,v.size()){
			int tmp=1000000;
			rep(j,1,v[i].size()){
				tmp=min(tmp,abs(v[i][j]-v[i][j-1]));
			}
			if(tmp>mx)mx=tmp,ans=v[i];
		}
		cout<<ans<<mx<<endl;
	}

	return 0;
}
