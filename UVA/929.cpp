#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>>g;
vector<int>vis;
vector<int>wt;
vector<int>v;

int n,m;

int dijk(){
	priority_queue<pair<int,int>>q;
	q.push(make_pair(-v[0],0));
	while(!q.empty()){
		int cst=-q.top().first;
		int nd=q.top().second;
		q.pop();
		vis[nd]=1;
		if(nd==n*m-1)
			return cst;
		for(int i=0;i<g[nd].size();i++){
			int child=g[nd][i];
			if(!vis[child]){
				if(cst+v[child]<wt[child]){
					wt[child]=cst+v[child];
					q.push(make_pair(-wt[child],child));
				}
			}
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		v.clear();
		v.resize(n*m);
		wt.clear();
		wt.resize(n*m,1e9);
		vis.clear();
		vis.resize(n*m);
		g.clear();
		g.resize(n*m);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>v[i*m+j];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i+1<n)g[i*m+j].push_back((i+1)*m+j);
				if(j+1<m)g[i*m+j].push_back(i*m+j+1);
				if(i-1>=0)g[i*m+j].push_back((i-1)*m+j);
				if(j-1>=0)g[i*m+j].push_back(i*m+j-1);
			}
		}
		cout<<dijk()<<"\n";
	}
	return 0;
}
