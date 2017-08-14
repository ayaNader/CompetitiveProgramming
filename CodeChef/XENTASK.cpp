/* 
   idea:
   - very simple brute force just trying both possible cases
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
		vector<int>x(n);
		vector<int>y(n);
		rep(i,0,n)cin>>x[i];
		rep(i,0,n)cin>>y[i];
		int ans1=0;
		rep(i,0,n){
			if(i%2)ans1+=x[i];
			else ans1+=y[i];
		}
		int ans2=0;
		rep(i,0,n){
			if(i%2)ans2+=y[i];
			else ans2+=x[i];
		}
		cout<<min(ans1,ans2)<<endl;
	}
 
	return 0;
}
