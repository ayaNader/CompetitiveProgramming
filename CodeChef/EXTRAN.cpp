/*
   idea:
   - first thought of checking each two next to each other..but it wouldn't have been enough to decide which is the different number
   - so i started checking every three consectutive numbers and the result is the number to the left/right whose 
   difference with the middle number is more than 1 or equal 0
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>v(n);
		rep(i,0,n)cin>>v[i];
		sort(all(v));
		int ans=0;
		rep(i,1,n-1){
			if(v[i]-v[i-1]==1&&v[i+1]-v[i]==1)continue;
			if(v[i]-v[i-1]==0||v[i]-v[i-1]>1)ans=v[i-1];
			else ans=v[i+1];
			break;
		}
		cout<<ans<<endl;
	}
 
	return 0;
}
