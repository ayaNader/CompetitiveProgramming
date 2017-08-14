/*
    idea:
    - first of all i want the first number to be less than or equal to the second
    - the result will be the difference between the results of the larger naumber and the results of the number before the smaller number
    i.e. 44 497 -> res(497)-res(43)
    - for each number loop through each digit index and count for each number all possible values for that number
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

ll mypow(ll b,ll p){
	if(!p)return 1;
	ll res=mypow(b,p/2);
	res*=res;
	if(p%2)res*=b;
	return res;
}

int stl(string s){
	int res=0;
	rep(i,0,s.length()){
		res*=10;
		res+=(s[i]-48);
	}
	return res;
}

string lts(int n){
	string s="";
	while(n){
		char c=(n%10)+48;
		n/=10;
		s=c+s;
	}
	return s;
}

vector<ll> solve(string x){
	vector<ll>res(10);
	int mul=mypow(10,x.length()-1);
	rep(i,0,x.length()){
		rep(j,0,10){
			if(!i){
				if(!j)continue;
				if(j<x[i]-48)res[j]+=mul;
				else if(j==x[i]-48){
					res[j]+=stl(x.substr(i+1,x.length()-i-1))+1;
				}
				else break;
			}
			else{
				int prev=stl(x.substr(0,i));
				int nxt=-1;
				if(i+1<x.length())nxt=stl(x.substr(i+1,x.length()-i-1));
				if(!j){
					if(j<x[i]-48)res[j]+=(prev*mul);
					else if(j==x[i]-48){
						res[j]+=((prev-1)*mul);
						if(nxt!=-1)res[j]+=nxt+1;
						else res[j]++;
					}
				}
				else if(j<x[i]-48){
					res[j]+=((prev+1)*mul);
				}
				else if(j==x[i]-48){
					res[j]+=((prev)*mul);
					if(nxt!=-1)res[j]+=nxt+1;
					else res[j]++;
				}
				else{
					res[j]+=(prev*mul);
				}
			}
		}
		mul/=10;
	}
	return res;
}

vector<ll> fnl(string a,string b){
	int tmp=stl(a);tmp--;
	a=lts(tmp);
	vector<ll>x=solve(a);
	vector<ll>y=solve(b);
	vector<ll>z(x.size());
	rep(i,0,z.size()){
		z[i]=y[i]-x[i];
	}
	//rep(i,0,x.size())cout<<x[i]<<" ";cout<<endl;
	//rep(i,0,y.size())cout<<y[i]<<" ";cout<<endl;
	return z;
}

int main()
{
	ios::sync_with_stdio(false);
	string a,b;
	while(cin>>a>>b){
		int tmpa=stl(a);
		int tmpb=stl(b);
		if(tmpa>tmpb)swap(a,b);
		if(a=="0"&&b=="0")break;
		vector<ll>res=fnl(a,b);
		cout<<res[0];
		rep(i,1,res.size())cout<<" "<<res[i];cout<<endl;
	}

	return 0;
}
