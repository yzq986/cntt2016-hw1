                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomPaintingOnABoard.cpp"
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
int a[55][55],sum[55],ls[55],v[5500],f[5500];
	/*&*/
class RandomPaintingOnABoard
{
        public:
        double expectedSteps(vector <string> vec)
        {
			int n=vec.size(),m=vec[0].size(),ss=0;
			for (int i=0;i<min(n,m);i++)
			for (int j=0;j<max(n,m);j++)
			{
				a[i][j]=(n<=m)?(vec[i][j]-48):(vec[j][i]-48);
				ss+=a[i][j];
				sum[j]+=a[i][j];
			}cout<<ss<<endl;
			if (n>m) swap(n,m);
			v[0]=-1;double ans=0;
			for (int i=0;i<(1<<n);i++)
			{
				if (i&1) v[i]=-v[i>>1];else v[i]=v[i>>1];
				for (int j=0;j<m;j++) ls[j]=sum[j];
				int t=0;
				for (int j=0;j<n;j++) if ((i>>j)&1)
				for (int k=0;k<m;k++) {ls[k]-=a[j][k];t+=a[j][k];}
				memset(f,0,sizeof(f));int r=1;f[0]=1;
				
				for (int j=0;j<m;j++)
				{
					r+=ls[j];
					for (int k=r-1;k>=ls[j];k--) f[k]-=f[k-ls[j]];
				}
				for (int j=0;j<r;j++) if (t+j) ans+=(double)v[i]*f[j]*ss/(t+j);
			}
			
			return ans;	
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(0, Arg1, expectedSteps(Arg0)); }
	void test_case_1() { string Arr0[] = {"11",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.6666666666666665; verify_case(1, Arg1, expectedSteps(Arg0)); }
	void test_case_2() { string Arr0[] = {"11",
 "12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.9166666666666665; verify_case(2, Arg1, expectedSteps(Arg0)); }
	void test_case_3() { string Arr0[] = {"0976",
 "1701",
 "7119"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 11.214334077031307; verify_case(3, Arg1, expectedSteps(Arg0)); }
	void test_case_4() { string Arr0[] = {"000000000000001000000",
 "888999988889890999988",
 "988889988899980889999",
 "889898998889980999898",
 "988889999989880899999",
 "998888998988990989998",
 "998988999898990889899"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1028.7662876159634; verify_case(4, Arg1, expectedSteps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RandomPaintingOnABoard ___test;
        ___test.run_test(4);
        return 0;
}
// END CUT HERE