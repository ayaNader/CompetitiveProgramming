/*
  idea:
  - trying all possible combinations of guitars
  - calculating number of songs that will be played with each combination
  - taking all combinations with equal max number of songs
  - taking the combination which has least number of guitars then lexicographically first
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string>v;
vector<set<string>>comb;
int x;
void filll(int n){
	x=(1<<n)-1;
	comb.resize(1<<n);
	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++){
			if((1<<j)&i){
				comb[i].insert(v[j]);
			}
		}
	}
}
class GuitarConcert {
public:
	vector <string> buyGuitars(vector <string> guitarNames, vector <string> guitarSongs) {
		v.clear();
		comb.clear();
		v=guitarNames;
		int n=guitarNames.size();
		filll(n);
		int sng=guitarSongs[0].size();
		map<string,int>ind;
		for(int i=0;i<guitarNames.size();i++){
			ind[guitarNames[i]]=i;
		}
		int mx=0;
		set<set<string>>res;
		for(int i=1;i<=x;i++){
			set<int>ss;
			for(set<string>::iterator it=comb[i].begin();it!=comb[i].end();it++){
				for(int s=0;s<sng;s++){
					if(guitarSongs[ind[*it]][s]=='Y'){
						ss.insert(s);
					}
				}
			}
			if(ss.size()>mx){
				mx=ss.size();
				res.clear();
				res.insert(comb[i]);
			}
			else if(ss.size()==mx)
				res.insert(comb[i]);
		}
		set<set<string>>tmp;
		int mi=2000000;
		for(set<set<string>>::iterator it=res.begin();it!=res.end();it++){
			if(it->size()<mi){
				tmp.clear();
				tmp.insert(*it);
				mi=it->size();
			}
			else if(it->size()==mi)
				tmp.insert(*it);
		}
		set<string>tmp2=*tmp.begin();
		vector<string>ret;
		for(set<string>::iterator it=tmp2.begin();it!=tmp2.end();it++){
			ret.push_back(*it);
		}
		if(mx==0)ret.clear();
		return ret;
	}
};
