/*
   idea:
   - assuming position of each string and doing calculations given the specified positions (getting all possible postions with permutation)
   - iterating through top string from 1 to 9 to find intersection with left string
   - iterating starting from the index after the first intersection till the end (till index 10 since 11 is not valid) 
   to find intersection with bottom string
   - from the prev the height can be found which is the absolute difference between the two indices in the left string intersecting 
   the top and bottom strings
   - then iterating through the last string (right side) from 1 till 10-height and finding the two left intersections between the right 
   side with the top and bottom strings
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

int calc(vector<string>s){
	int res=0;
	for(int i=1;i<=9;i++){
		int f=s[1].find(s[0][i],1);
		while(f!=-1&&f<=9){
			for(int j=f+1;j<=10;j++){
				int ff=s[2].find(s[1][j],1);
				while(ff!=-1&&ff<=9){
					int hgt=j-f;
					for(int k=1;k+i<=10&&k+ff<=10;k++){
						for(int d=1;d<11-hgt;d++){
							if(s[3][d]==s[0][i+k]&&s[3][d+hgt]==s[2][ff+k]){
								res=max(res,(hgt-1)*(k-1));
							}
						}
					}
					ff=s[2].find(s[1][j],ff+1);
				}
			}
			f=s[1].find(s[0][i],f+1);
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);

	vector<string> s(4);
	while(cin>>s[0]){
		if(s[0]=="Q")break;
		cin>>s[1]>>s[2]>>s[3];
		sort(all(s));
		int res=0;
		do{
			res=max(res,calc(s));
		}while(next_permutation(all(s)));
		cout<<res<<endl;
	}

	return 0;
}
