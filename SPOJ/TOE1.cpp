#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool win(string s){
	if((s[0]!='.'&&s[0]==s[1]&&s[1]==s[2])||
			(s[3]!='.'&&s[3]==s[4]&&s[4]==s[5])||
			(s[6]!='.'&&s[6]==s[7]&&s[7]==s[8]))
		return true;
	if((s[0]!='.'&&s[0]==s[3]&&s[3]==s[6])||
			(s[1]!='.'&&s[1]==s[4]&&s[4]==s[7])||
			(s[2]!='.'&&s[2]==s[5]&&s[5]==s[8]))
		return true;
	if((s[0]!='.'&&s[0]==s[4]&&s[4]==s[8])||
			(s[2]!='.'&&s[2]==s[4]&&s[4]==s[6]))
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		string goal="";
		for(int i=0;i<3;i++){
			string s;
			cin>>s;
			goal+=s;
		}
		string strt=".........";
		string ans="no";
		queue<pair<string,bool>>q;
		q.push(make_pair(strt,1));
		while(q.size()){
			string cur=q.front().first;
			bool turn=q.front().second;
			q.pop();
			if(cur==goal){
				ans="yes";
				break;
			}
			if(win(cur))
				continue;
			for(int i=0;i<9;i++){
				if(cur[i]=='.'){
					cur[i]=turn?'X':'O';
					if(cur[i]==goal[i])
						q.push(make_pair(cur,!turn));
					cur[i]='.';
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
