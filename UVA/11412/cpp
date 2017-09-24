/*
  idea:
  - trying all possible strings that migt=ht be the final result and checking for each the correctness of 
  the conditions with the given two guesses
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n1,n2;
vector<string>fnl;

bool check(string s,string c){
	set<char>tmp1,tmp2;
	for(int i=0;i<4;i++){
		if(s[i]==c[i])
			tmp1.insert(s[i]);
	}
	if(tmp1.size()!=n1)
		return false;
	for(int i=0;i<4;i++){
		int f=c.find(s[i]);
		if(f!=-1&&f!=i)
			tmp2.insert(s[i]);
	}
	if(tmp2.size()!=n2)
		return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	char arr[]={'R','G','B','Y','O','V'};
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			for(int k=0;k<6;k++)
				for(int m=0;m<6;m++){
					if(i!=j&&i!=k&&i!=m&&j!=k&&j!=m&&k!=m){
						string tmp="";
						tmp+=arr[i];
						tmp+=arr[j];
						tmp+=arr[k];
						tmp+=arr[m];
						fnl.push_back(tmp);
					}

				}
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		pair<int,int>p1,p2;
		string ans="Cheat";
		cin>>s1>>p1.first>>p1.second;
		cin>>s2>>p2.first>>p2.second;
		for(int i=0;i<fnl.size();i++){
			n1=p1.first,n2=p1.second;
			if(check(fnl[i],s1)){
				n1=p2.first,n2=p2.second;
				if(check(fnl[i],s2)){
					ans="Possible";
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
