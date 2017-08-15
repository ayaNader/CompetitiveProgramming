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
	string s;
	while(cin>>s){
		vector<char>v1(s.length()),v2(s.length());
		rep(i,0,s.length())v1[i]=v2[i]=s[i];
		vector<string>v;
		v.push_back(s);
		int cnt=0;
		do
		{
			if(!cnt){cnt++;continue;}
			string tmp="";
			rep(i,0,v1.size())tmp+=v1[i];
			v.push_back(tmp);
			if(cnt==10)break;
			cnt++;
		}while(next_permutation(all(v1)));
		cnt=0;
		do
		{
			if(!cnt){cnt++;continue;}
			string tmp="";
			rep(i,0,v2.size())tmp+=v2[i];
			v.push_back(tmp);
			if(cnt==10)break;
			cnt++;
		}while(prev_permutation(all(v2)));
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
