/*
  idea:
  - creating a graph where nodes are the points and edges are the valid distances between any two points
  - using dijkstra finding the shortest path between the start and end and checking if its <= the given constraint 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<pair<int,double>>>g;
vector<double>wt;
vector<int>vis;
double d;

bool dij(int frm,int to){
	priority_queue<pair<double,int>>q;
	q.push(make_pair(0.0,frm));
	while(!q.empty()){
		double c=-q.top().first;
		int nd=q.top().second;
		q.pop();
		vis[nd]=1;
		if(nd==to){
			if(c>d)
				return false;
			return true;
		}
		for(int i=0;i<g[nd].size();i++){
			int child=g[nd][i].first;
			double cst=g[nd][i].second;
			if(!vis[child]){
				if(cst+c<wt[child]){
					wt[child]=c+cst;
					q.push(make_pair(-wt[child],child));
				}
			}
		}
	}
	return false;
}
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
	//	cin.tie(0);
	string s;
	while(cin>>s){
		if(s=="*")
			break;
		int w=stl(s);
		int h;
		cin>>h;
		int pnts;
		cin>>pnts;
		vector<pair<double,double>>v(pnts+2);
		v[0].first=v[0].second=0.0;
		v[pnts+1].first=w;
		v[pnts+1].second=h;
		for(int i=1;i<=pnts;i++)
			cin>>v[i].first>>v[i].second;
		g.clear();
		g.resize(pnts+2);
		vis.clear();
		vis.resize(pnts+2);
		wt.clear();
		wt.resize(pnts+2,1e18);
		wt[0]=0.0;
		for(int i=0;i<=pnts+1;i++){
			for(int j=i+1;j<=pnts+1;j++){
				double dis=sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+
						(v[i].second-v[j].second)*(v[i].second-v[j].second));
				if(dis<=1.5){
					g[i].push_back(make_pair(j,dis));
					g[j].push_back(make_pair(i,dis));
				}
			}
		}
		cin>>d;
		if(dij(0,pnts+1))
			cout<<"I am lucky!"<<endl;
		else
			cout<<"Boom!"<<endl;
	}

	return 0;
}
