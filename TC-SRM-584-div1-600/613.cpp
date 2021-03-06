                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            // BEGIN CUT HERE

// END CUT HERE
//#line 5 "Excavations.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
vector <int> vec[55];
bool bo[55];
long long c[55][55];
long long f[55][55][2];
map<int,int> mp;
class Excavations
{
        public:
        long long count(vector <int> kind, vector <int> depth, vector <int> found, int K)
        {
        	mp.clear();
        	for (int i=0;i<depth.size();i++) mp[depth[i]]=0;
        	int dep=0;
			for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++dep;
			for (int i=0;i<depth.size();i++) depth[i]=mp[depth[i]];
        
        	mp.clear();
			for (int i=0;i<kind.size();i++) mp[kind[i]]=0;
			int tp=0;
			for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++tp;
			for (int i=0;i<kind.size();i++) vec[mp[kind[i]]].push_back(depth[i]);
			for (int i=0;i<found.size();i++) bo[mp[found[i]]]=true;
			for (int i=1;i<=tp;i++) sort(vec[i].begin(),vec[i].end());
			
			c[0][0]=1;
			for (int i=1;i<=50;i++)
			{
				c[i][0]=1;
				for (int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
			
			long long ans=0;
			for (int maxd=0;maxd<=dep;maxd++)
			{
				memset(f,0,sizeof(f));
				f[0][0][0]=1;
				for (int i=0;i<=tp;i++)
				for (int j=0;j<=K;j++)
				for (int d=0;d<=1;d++)
				{
					//cout<<i<<' '<<j<<' '<<d<<endl;
					if ((i==tp)&&(d==1)&&(j==K))
					{
						ans+=f[i][j][d];
						//cout<<maxd<<' '<<i<<' '<<j<<' '<<d<<' '<<f[i][j][d]<<endl;
					}
					else if ((i==tp)&&(maxd==dep)&&(j==K))
					{
						ans+=f[i][j][d];
						//cout<<maxd<<' '<<i<<' '<<j<<' '<<d<<' '<<f[i][j][d]<<endl;
					}
					else if ((i!=tp)&&(f[i][j][d]))
					{
						int now=upper_bound(vec[i+1].begin(),vec[i+1].end(),maxd)-vec[i+1].begin();
						int up=upper_bound(vec[i+1].begin(),vec[i+1].end(),maxd+1)-vec[i+1].begin()-now;
						int can=now,cant=vec[i+1].size()-now;
						for (int c1=(bo[i+1]?1:0);c1<=(bo[i+1]?can:0);c1++)
						for (int c2=0;c2<=cant;c2++)
						{
							if (bo[i+1]) f[i+1][j+c1+c2][d]+=f[i][j][d]*c[can][c1]*c[cant][c2];
							else if (d) f[i+1][j+c1+c2][1]+=f[i][j][d]*c[can][c1]*c[cant][c2];
							else
							{
								f[i+1][j+c1+c2][1]+=f[i][j][d]*c[can][c1]*(c[cant][c2]-c[cant-up][c2]);
								f[i+1][j+c1+c2][0]+=f[i][j][d]*c[can][c1]*c[cant-up][c2];
							}
						}
					}
				}
			}
			return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 3LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 4LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; long long Arg4 = 0LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 2, 3, 1, 3, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; long long Arg4 = 35LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 18; long long Arg4 = 9075135300LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Excavations ___test;
        ___test.run_test(4);
        return 0;
}
// END CUT HERE