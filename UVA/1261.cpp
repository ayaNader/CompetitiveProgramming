/*
   idea:
   -trying to start with a different set of letters recursively
*/
#include<bits/stdc++.h>
using namespace std;

bool go(string s){
	if(s.empty())
		return true;
	for(short i=0;i<s.length();i++){
		short j=i;
		while(j<s.length()&&s[i]==s[j])j++;
		if(j-i>=2){
			string tmp=s;
			tmp.erase(i,j-i);
			if(go(tmp))
				return true;
		}
		i=j-1;
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(go(s))
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
