/*
   idea:
   - for n=0 any correct output such as that in the example
   - n=1 i found that when first two numbers are equa and second two numbers are 3*the first the solution will always be correct
   - n=4 just checking
   - n=2 looping through all possible values and then calculating the last depending on where its position could be
   - n=3 looping through all possible values and checking
*/


#include <bits/stdc++.h>

using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define repe(i,x,n) for(int i=x;i<=n;i++)
#define repn(i,x,n) for(int i=x;i>=n;i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define mod 1000000007

typedef long long ll;

const double PI=3.14159265;

double sum(vector<double>x){
	int res=0;
	rep(i,0,x.size())
	res+=x[i];
	return res;
}

int check(double x,double y,double z){
	vector<double>v(3);
	v[0]=x,v[1]=y,v[2]=z;
	sort(all(v));

	//1st
	double tmp=v[2]-(v[0]+v[1])/2;
	if(tmp==(int)tmp&&(tmp<=v[0])&&tmp>=1&&tmp<=1000000&&(sum(v)+tmp)/4==(v[0]+v[1])/2)return tmp;

	//2nd & 3rd
	tmp=2*(v[2]-v[0])-v[1];
	if(tmp==(int)tmp&&((tmp>=v[0]&&tmp<=v[1])||(tmp>=v[1]&&tmp<=v[2]))&&tmp>=1&&tmp<=1000000&&(sum(v)+tmp)/4==(v[2]-v[0]))return tmp;

	//4th
	tmp=v[0]+(v[1]+v[2])/2;
	if(tmp==(int)tmp&&(tmp>=v[2])&&tmp>=1&&tmp<=1000000&&(sum(v)+tmp)/4==(v[1]+v[2])/2)return tmp;

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0){
			cout<<"YES"<<endl<<1<<endl<<1<<endl<<3<<endl<<3<<endl;
			return 0;
		}
		else if(n==1){
			int x;
			cin>>x;
			cout<<"YES"<<endl<<x<<endl<<3*x<<endl<<3*x<<endl;
			return 0;
		}
		else if(n==2){
			int a,b; cin>>a>>b;
			repe(i,1,1000000){
				int tmp=check(a,b,i);
				if(tmp!=-1){
					cout<<"YES"<<endl<<i<<endl<<tmp<<endl;
					return 0;
				}
			}
		}
		else if(n==3){
			vector<double>x(3);int a,b,c; cin>>a>>b>>c;
			repe(i,1,1000000){
				x[0]=a,x[1]=b,x[2]=c;
				sort(all(x));
				//1st
				double tmp=(sum(x)+i)/4;
				if((i<=x[0]&&tmp==x[2]-i&&(x[0]+x[1])/2==tmp)|| //1st
					(((i>=x[0]&&i<=x[1])||(i>=x[1]&&i<=x[2]))&&tmp==x[2]-x[0]&&(i+x[1])/2==tmp)|| //2nd && 3rd
					(i>=x[2]&&tmp==i-x[0]&&tmp==(x[1]+x[2])/2)){ //4th
					cout<<"YES"<<endl<<i<<endl;
					return 0;
				}
			}
		}
		else if(n==4){
			vector<double>x(4); cin>>x[0]>>x[1]>>x[2]>>x[3];
			sort(all(x));
			double tmp=(x[1]+x[2])/2;
			if(sum(x)/4==tmp&&tmp==x[3]-x[0]){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		cout<<"NO"<<endl;
	}

	return 0;
}
