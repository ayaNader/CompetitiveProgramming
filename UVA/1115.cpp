/*
  idea:
  - binary seacrching for the level and each time calculating all capacities below or on this level
*/
#include <bits/stdc++.h>

using namespace std;

vector<double>base,height,width,depth;
int n;
double calc(double lvl){
	double ret=0;
	for(int i=0;i<n;i++){
		if(base[i]+height[i]<=lvl)
			ret+=(height[i]*width[i]*depth[i]);
		else if(base[i]<lvl)
			ret+=((lvl-base[i])*width[i]*depth[i]);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	bool put=false;
	while(t--){
		if(put)
			cout<<"\n";
		cin>>n;
		base.clear();
		height.clear();
		width.clear();
		depth.clear();
		base.resize(n);
		height.resize(n);
		width.resize(n);
		depth.resize(n);
		double total=0;
		double lim=0;
		for(int i=0;i<n;i++){
			cin>>base[i]>>height[i]>>width[i]>>depth[i];
			total+=(height[i]*width[i]*depth[i]);
			if(base[i]+height[i]>lim)
				lim=base[i]+height[i];
		}
		double cap;
		cin>>cap;
		if(cap>total)
			cout<<"OVERFLOW\n";
		else{
			double res=0;
			double s=0,e=lim;
			for(int i=0;i<100;i++){
				double lvl=(s+e)/2;
				double tmp=calc(lvl);
				if(tmp<cap)
					s=lvl+1;
				else if(tmp>=cap){
					e=lvl-1;
					res=lvl;
				}
			}
			res*=100;
			res=trunc(res);
			res/=100;
			cout<<fixed<<setprecision(2)<<res<<"\n";
		}
		put=true;
	}
	return 0;
}
