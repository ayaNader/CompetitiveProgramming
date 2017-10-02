#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll stl(string s){
	ll ret=0;
	for(int i=0;i<s.length();i++){
		ret*=10;
		ret+=(s[i]-48);
	}
	return ret;
}

string lts(ll n){
	string ret="";
	while(n){
		ll tmp=n%10;
		char c=tmp+48;
		ret=c+ret;
		n/=10ll;
	}
	return ret;
}
ll coeff[55][55];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int tst=1;tst<=t;tst++){
		string s;
		cin>>s;
		string tmpn="";
		string s1="";
		string s2="";
		int ind=1;
		while(s[ind]!='+')s1+=s[ind],ind++;
		ind++;
		while(s[ind]!=')')s2+=s[ind],ind++;
		ind+=2;
		while(ind<s.length())tmpn+=s[ind],ind++;
		int n=stl(tmpn);
		vector<string>res(n+1);
		int pw1=n;
		int pw2=0;
		for(int i=0;i<res.size();i++){
			if(i<res.size()-1){
				res[i]+=s1;
			}
			if(pw1>1){
				res[i]+='^';
				res[i]+=lts(pw1);
			}
			if(i>0){
				if(i<res.size()-1)res[i]+='*';
				res[i]+=s2;
			}
			if(pw2>1){
				res[i]+='^';
				res[i]+=lts(pw2);
			}
			pw1--;
			pw2++;
		}
		for(int i=0;i<55;i++){
			coeff[i][0]=1;
			coeff[i][i]=1;
			for(int j=1;j<i;j++)
				coeff[i][j]=coeff[i-1][j-1]+coeff[i-1][j];
		}
		for(int i=0;i<res.size();i++)
			if(coeff[n][i]>1)
				res[i]=lts(coeff[n][i])+'*'+res[i];
		cout<<"Case "<<tst<<": ";
		string tmp=res[0];
		for(int i=1;i<res.size();i++)tmp+="+"+res[i];
		cout<<tmp<<"\n";
	}
	return 0;
}
