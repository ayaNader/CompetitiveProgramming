#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0);
	string s;
	while(cin>>s){
		if(s=="end")
			break;
		string ans="valid";
		int x=0,o=0;
		for(int i=0;i<9;i++){
			if(s[i]=='X')x++;
			else if(s[i]=='O')o++;
		}
		if(x-o>1||o>x)
			ans="invalid";
		if(ans=="valid"){
			int cntx=0,cnto=0;
			int row=0,col=0,dia=0;
			if(s[0]!='.'&&s[0]==s[1]&&s[1]==s[2])
				row++,s[0]=='X'?cntx++:cnto++;
			if(s[3]!='.'&&s[3]==s[4]&&s[4]==s[5])
				row++,s[3]=='X'?cntx++:cnto++;
			if(s[6]!='.'&&s[6]==s[7]&&s[7]==s[8])
				row++,s[6]=='X'?cntx++:cnto++;
			if(s[0]!='.'&&s[0]==s[3]&&s[3]==s[6])
				col++,s[0]=='X'?cntx++:cnto++;
			if(s[1]!='.'&&s[1]==s[4]&&s[4]==s[7])
				col++,s[1]=='X'?cntx++:cnto++;
			if(s[2]!='.'&&s[2]==s[5]&&s[5]==s[8])
				col++,s[2]=='X'?cntx++:cnto++;
			if(s[0]!='.'&&s[0]==s[4]&&s[4]==s[8])
				dia++,s[0]=='X'?cntx++:cnto++;
			if(s[2]!='.'&&s[2]==s[4]&&s[4]==s[6])
				dia++,s[2]=='X'?cntx++:cnto++;
			if((cntx&&cnto)||(cnto&&(col>1||row>1))||(cntx&&(col>1||row>1))||(cnto&&x>o)||
					(cntx&&x==o)||(!cntx&&!cnto&&(x!=5||o!=4)))
				ans="invalid";

		}
		cout<<ans<<"\n";
	}
	return 0;
}
