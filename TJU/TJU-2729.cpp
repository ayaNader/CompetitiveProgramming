/*
  idea:
  - looping through all nodes and getting total number of nodes connected to it seperatly 
  - that's done by getting total nodes for each child and then the number of left nodes from the parent
  - getting max number of nodes for each component of each node and then getting the min among all
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >tree;
vector<vector<int> >comp;
vector<int>mxs;
int n;

int dfs(int nd,int par){
	int mx=0;
	for(int i=0;i<tree[nd].size();i++){
		int child=tree[nd][i];
		if(child!=par){
			comp[nd].push_back(dfs(child,nd)+1);
			mx+=comp[nd][comp[nd].size()-1];
		}
	}
	return mx;
}

int main(){
	cin>>n;
	tree.resize(n+1);
	comp.resize(n+1);
	mxs.resize(n+1);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=0;j<comp[i].size();j++){
			mxs[i]=max(mxs[i],comp[i][j]);
			tmp+=comp[i][j];
		}
		mxs[i]=max(mxs[i],n-tmp-1);
	}
	vector<int>res;
	int mi=1e9;
	for(int i=1;i<=n;i++){
		if(mxs[i]<mi){
			res.clear();
			res.push_back(i);
			mi=mxs[i];
		}
		else if(mxs[i]==mi){
			res.push_back(i);
		}
	}
	cout<<res[0];
	for(int i=1;i<res.size();i++)
		cout<<" "<<res[i];
	cout<<endl;
	return 0;
}
