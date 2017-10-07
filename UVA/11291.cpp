#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll stl(string s){
	ll ret=0;
	bool neg=false;
	if(s[0]=='-')
		neg=true,s.erase(0,1);
	for(int i=0;i<s.length();i++){
		ret*=10ll;
		ret+=(s[i]-48);
	}
	if(neg)
		ret*=-1;
	return ret;
}
ll mypow(ll b,ll p){
	if(p==0)
		return 1ll;
	ll res=mypow(b,p/2ll);
	res*=res;
	if(p%2ll)
		res*=b;
	return res;
}
double conv(string s){
	bool neg=false;
	if(s[0]=='-'){
		neg=true;
		s.erase(0,1);
	}
	double ret=0;
	int i=0;
	while(i<s.length()&&s[i]!='.'){
		ret*=10;
		ret+=(s[i]-48);
		i++;
	}
	double tmp=0;
	if(s[i]=='.'&&i+1<s.length()){
		tmp=stl(s.substr(i+1,s.length()-i-1));
		int dig=(tmp?log10(tmp)+1:1);
		double tmp2=mypow(10,dig);
		tmp/=tmp2;
	}
	ret+=tmp;
	if(neg)
		ret*=-1;
	return ret;
}
int main(){
	string s;
	while(getline(cin,s)){
		if(s=="()")
			return 0;
		if(s.find('(')==-1){
			double res=conv(s);
			cout<<fixed<<setprecision(2)<<res<<endl;
		}
		else{
			s.erase(0,1);
			s.pop_back();
			int f=s.find(' ');
			double p=conv(s.substr(0,f));
			s.erase(0,f+1);
			f=s.find(' ');
			double val1=conv(s.substr(0,f));
			s.erase(0,f+1);
			double val2=conv(s);
			double tmp=val1;
			val1=val1+val2;
			val2=tmp-val2;
			double res=p*val1+(1.0-p)*val2;
			cout<<fixed<<setprecision(2)<<res<<endl;
		}
	}
}
