#include <bits/stdc++.h>

using namespace std;

class AlphabetCount {
public:
	vector<string>v;
	int len;
	int ax[8]={1,0,-1,0,1,-1,1,-1};
	int ay[8]={0,1,0,-1,1,-1,-1,1};
	int dp[50][50][26];
	int go(int x,int y,char c,int cnt){
		if(v[x][y]!=c)
			return 0;
		if(cnt==len)
			return 1;
		if(dp[x][y][c-'A']!=-1)
			return dp[x][y][c-'A'];
		int ret=0;
		for(int i=0;i<8;i++){
			if(x+ax[i]>=0&&x+ax[i]<v.size()&&y+ay[i]>=0&&y+ay[i]<v[0].size())
				ret+=go(x+ax[i],y+ay[i],c+1,cnt+1);
			if(ret>1e9)
				ret=1e9;
		}
		return dp[x][y][c-'A']=ret;
	}
	int count(vector <string> grid, int length) {
		v=grid;
		len=length;
		int res=0;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<grid.size();i++){
			for(int j=0;j<v[i].size();j++){
				if(v[i][j]=='A')
					res+=go(i,j,'A',1);
				if(res>1e9)
					res=1e9;
			}
		}
		return res;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	AlphabetCount *obj;
	int answer;
	obj = new AlphabetCount();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <string> p0;
	int p1;
	int p2;

	{
		// ----- test 0 -----
		string t0[] = {"ABC","CBZ","CZC","BZZ","ZAA"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 3;
		p2 = 7;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = {"AAAA","AAAA","AAAA"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
		p2 = 12;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = {"ABAB","BABA","ABAB","BABA"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 2;
		p2 = 24;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = {"HIJKLMNOPQZZZONMLKHIDZYQR","GYXWVUTSRASTZZPSTUJGECPXS","FZABCDEFARQPUQRAAAVWFBOWT","EONMJIHGAJMNOVAAAAAYXANUV","DCBLKDEFIEKLEDWAAAZFGHMLK","UVAZYBCGHFDFCAYXNPQZEDIJA","TSWXAKLZGCZBGZIJOMZRUTCBZ","RQPONMJIHBAZZHZZKLZZSVWXY"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 26;
		p2 = 7;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		string t0[] = {"CZC","ZBZ","AZA"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 3;
		p2 = 4;
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		string t0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ","ABCDEFGHIJKLMNOPQRSTUVWXYZ","ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 26;
		p2 = 1000000000;
		all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 6 -----
		string t0[] = {"BDBCBACABDDCCADCBDDCBDDDBCCCCABACADDDCCCBADDDBADCA","DCBBBACBDBACCADABCCAABACDBADBCBBABACBCADADCBDABBBD"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 4;
		p2 = 20;
		all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
