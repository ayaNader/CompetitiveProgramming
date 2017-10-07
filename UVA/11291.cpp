#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll stl(string s){
	ll ret=0;
	for(int i=0;i<s.length();i++){
		ret*=10ll;
		ret+=(s[i]-48);
	}
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
ld conv(string s){
	bool neg=false;
	if(s[0]=='-'){
		neg=true;
		s.erase(0,1);
	}
	int f=s.find('.');
	ld ret=0;
	if(f==-1)
		ret=stl(s.substr(0,s.length()));
	else
		ret=stl(s.substr(0,f));
	ld tmp=0;
	if(f!=-1)
		tmp=stl(s.substr(f+1,s.length()-f-1));
	int dig=s.substr(f+1,s.length()-f-1).length();
	ld tmp2=mypow(10ll,dig);
	tmp/=tmp2;
	ret+=tmp;
	if(neg)
		ret*=-1;
	return ret;
}
int main(){
	string s;
	while(cin>>s){
		if(s=="()")
			return 0;
		if(s[0]!='('){
			ld res=conv(s);
			cout<<fixed<<setprecision(2)<<res<<endl;
		}
		else{
			s.erase(0,1);
			ld p=conv(s);
			cin>>s;
			ld val1=conv(s);
			cin>>s;
			s.pop_back();
			ld val2=conv(s);
			ld a=val1+val2;
			ld b=val1-val2;
			ld res=p*a+(1.0-p)*b;
			cout<<fixed<<setprecision(2)<<res<<endl;
		}
	}
}
