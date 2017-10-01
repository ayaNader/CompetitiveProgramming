/*
  idea:
  - craeting a graph where cells are the nodes and edges are the possible moves
  - using dfs iterating until a deadend...if not all cells are visited then unvisiting the current node and removing it from the result
  - that's done until either a path is found or no answer is valid
*/
#include <bits/stdc++.h>
using namespace std;

bool allvis(vector<int>v){
	for(int i=0;i<v.size();i++)
		if(v[i]==0)
			return false;
	return true;
}
vector<vector<int>>grph;
vector<int>vis;

vector<int>tmp;
bool dfs(int nd){
	vis[nd]=1;
	tmp.push_back(nd);
	for(int i=0;i<grph[nd].size();i++){
		int child=grph[nd][i];
		if(!vis[child]){
			if(dfs(child))
				return true;
		}
	}
	if(allvis(vis)){
		return true;
	}
	vis[nd]=0;
	tmp.pop_back();
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		grph.clear();
		int n,m;
		cin>>n>>m;
		grph.resize(n*m);
		vis.resize(n*m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int ind=i*m+j;
				if(j-2>=0){
					if(i-1>=0)grph[ind].push_back((i-1)*m+(j-2));
					if(i+1<n)grph[ind].push_back((i+1)*m+(j-2));
				}
				if(j-1>=0){
					if(i-2>=0)grph[ind].push_back((i-2)*m+(j-1));
					if(i+2<n)grph[ind].push_back((i+2)*m+(j-1));
				}
				if(j+1<m){
					if(i-2>=0)grph[ind].push_back((i-2)*m+(j+1));
					if(i+2<n)grph[ind].push_back((i+2)*m+(j+1));
				}
				if(j+2<m){
					if(i-1>=0)grph[ind].push_back((i-1)*m+(j+2));
					if(i+1<n)grph[ind].push_back((i+1)*m+(j+2));
				}
			}
		}
		for(int j=0;j<m;j++){
			bool brk=false;
			for(int i=0;i<n;i++){
				vis.clear();
				vis.resize(n*m);
				tmp.clear();
				if(dfs(i*m+j)){
					brk=true;
					break;
				}
			}
			if(brk)
				break;
		}
		if(tmp.size()!=n*m)
			cout<<-1<<endl;
		else{
			string res="";
			for(int i=0;i<tmp.size();i++){
				int r=tmp[i]/m;
				int c=tmp[i]%m;
				char ch='A'+c;
				char nu='1'+r;
				res+=ch;
				res+=nu;
			}
			cout<<res<<endl;
		}
	}
	return 0;
}
