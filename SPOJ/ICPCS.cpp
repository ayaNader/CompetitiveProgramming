#include<bits/stdc++.h>
using namespace std;

int tp[105];
int fa[105];
int solved[105];

int t,p;
int stl(string s){
	int ret=0;
	for(int i=0;i<s.length();i++){
		ret*=10;
		ret+=(s[i]-48);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);

	while(cin>>t>>p){
		if(t==0&&p==0)
			return 0;
		memset(solved,0,sizeof solved);
		memset(fa,0,sizeof fa);
		memset(tp,0,sizeof tp);

		for(int i=0;i<t;i++){
			for(int j=0;j<p;j++){
				int a;
				char c;
				string s;
				cin>>a>>c>>s;
				if(s=="-")
					continue;
				tp[i]+=stl(s);
				fa[i]+=a-1;
				solved[i]++;
			}
		}
		vector<pair<pair<int,int>,int>>v(t);
		for(int i=0;i<t;i++){
			v[i].first.first=solved[i];
			v[i].first.second=-(tp[i]+20*fa[i]);
			v[i].second=i;
		}
		sort(v.rbegin(),v.rend());
		bool chng[105][105];
		for(int i=0;i<t-1;i++){
			if(v[i].first.first==v[i+1].first.first){
				int tmp1=-v[i].first.second;
				int tmp2=-v[i+1].first.second;
				if(tmp1<tmp2)
					chng[i][i+1]=0;
				else
					chng[i][i+1]=1;
			}
		}
		int mi=20;
		for(int ep=1;ep<=20;ep++){
			bool val=true;
			for(int i=0;i<t-1;i++){
				if(v[i].first.first==v[i+1].first.first){
					int ind1=v[i].second;
					int ind2=v[i+1].second;
					int tmp1=tp[ind1]+ep*fa[ind1];
					int tmp2=tp[ind2]+ep*fa[ind2];
					if((tmp1<tmp2&&chng[i][i+1]==0)||(tmp1==tmp2&&chng[i][i+1]==1))
						continue;
					val=false;
					break;
				}
			}
			if(!val)
				continue;
			mi=ep;
			break;
		}
		int mx=42;
		bool inf=true;
		for(int ep=3000;ep>=20;ep--){
			bool val=true;
			for(int i=0;i<t-1;i++){
				if(v[i].first.first==v[i+1].first.first){
					int ind1=v[i].second;
					int ind2=v[i+1].second;
					int tmp1=tp[ind1]+ep*fa[ind1];
					int tmp2=tp[ind2]+ep*fa[ind2];
					if((tmp1<tmp2&&chng[i][i+1]==0)||(tmp1==tmp2&&chng[i][i+1]==1))
						continue;
					val=false;
					break;
				}
			}
			if(!val)
				continue;
			inf=false;
			mx=ep;
			break;
		}
		cout<<mi<<" ";
		if(inf||mx==3000)
			cout<<"*\n";
		else
			cout<<mx<<"\n";
	}
}
