                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         // BEGIN CUT HERE

// END CUT HERE
//#line 5 "WolfDelaymasterHard.cpp"
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
#define mo 1000000007
using namespace std;
char st[2100000];
int sumw[2100000],sumo[2100000],/*nextw[2100000],*/nexto[2100000],/*lstw[2100000],lsto[2100000],*/add[2100000];
int f[2100000],sumf[2100000];
int getsumw(int l,int r){return sumw[r]-sumw[l-1];}
int getsumo(int l,int r){return sumo[r]-sumo[l-1];}
int leg(int x)
{
	if (x&1) return x-1;
	return x;
}
int upleg(int x)
{
	if (x&1) return x+1;
	return x;
}
class WolfDelaymasterHard
{
        public:
        int countWords(int N, int wlen, int w0, int wmul, int wadd, int olen, int o0, int omul, int oadd)
        {
			for (int i=1;i<=N;i++) st[i]='?';
			long long x = w0;
			for(int i=0;i<wlen;i++)
			{
				st[x+1] = 'w';
				x = (x * wmul + wadd) % N;
			}
			x = o0;
			for(int i=0;i<olen;i++)
			{
				st[x+1] = 'o';
				x = (x * omul + oadd) % N;
			}
			
			int n=N;
			for (int i=1;i<=n;i++)
			{
				sumw[i]=sumw[i-1]+(st[i]=='w');
				sumo[i]=sumo[i-1]+(st[i]=='o');
			}
			/*nextw[n]=*/nexto[n]=n+1;
			for (int i=n-1;i>=0;i--)
			{
				//if (st[i+1]=='w') nextw[i]=i+1;else nextw[i]=nextw[i+1];
				if (st[i+1]=='o') nexto[i]=i+1;else nexto[i]=nexto[i+1];
			}
			/*lstw[1]=lsto[1]=0;
			for (int i=2;i<=n+1;i++)
			{
				if (st[i-1]=='w') lstw[i]=i-1;else lstw[i]=lstw[i-1];
				if (st[i-1]=='o') lsto[i]=i-1;else lsto[i]=lsto[i-1];
			}*/
			f[0]=sumf[0]=1;//return 0;
			int lstw=0,lsto=0;
			for (int i=0;i<=n;i+=2)
			{//cout<<i<<endl;
				if (i==0) {}
				else if (st[i]=='w') f[i]=0;
				else if (lstw==lsto) f[i]=0;
				else if (lstw>lsto)
				{
					int minlen=upleg(i-lstw+1),maxlen=min(2*(i-lstw),leg(i-lsto));
					if (i-maxlen-2>=0) f[i]=(sumf[i-minlen]-sumf[i-maxlen-2]+mo)%mo;
					else f[i]=sumf[i-minlen];
				}
				else
				{//cout<<i<<" HAHAHAHA\n";
					int no=nexto[lstw],l=no+1,r=0;
					while (r+1!=l)
					{
						int mid=(l+r)>>1,fst=2*mid-1-i;
						if (fst<=0) r=mid;
						else if ((getsumw(fst,mid-1)>=0)&&(getsumo(fst,mid-1)==0)&&(getsumw(mid,i)==0)) l=mid;else r=mid;
					}
					if (l!=no+1) 
					{
						int minlen=max((i-no+1)*2,upleg(i-lstw+1)),maxlen=(i-l+1)*2;
						if (minlen<=maxlen)
						{
							if (i-maxlen-2>=0) f[i]=(sumf[i-minlen]-sumf[i-maxlen-2]+mo)%mo;
							else f[i]=sumf[i-minlen];
						}
					}
				}
				if (i>=2) add[i]=(add[i]+add[i-2])%mo;
				f[i]=(f[i]+add[i])%mo;
				if (i>=2) sumf[i]=(sumf[i-2]+f[i])%mo;else sumf[i]=f[i];
				int l=i,r=n+1;
				while (l+1!=r)
				{
					int mid=(l+r)>>1;
					if (2*mid-i>n) r=mid;
					else if ((getsumw(i+1,mid)==0)&&(getsumo(i+1,mid)==0)&&(getsumw(mid+1,2*mid-i)==0)) l=mid;else r=mid;
				}
				//cout<<i<<' '<<i+2<<' '<<2*l-i<<endl;
				add[i+2]=(add[i+2]+f[i])%mo;
				add[2*l-i+2]=(add[2*l-i+2]-f[i]+mo)%mo;
				
				if (st[i]=='w') lstw=i;
				if (st[i]=='o') lsto=i;//cout<<i<<' '<<lstw<<' '<<lsto<<endl;
				if (st[i+1]=='w') lstw=i+1;
				if (st[i+1]=='o') lsto=i+1;
			}
			/*for (int i=1;i<=n;i++) cout<<i<<' '<<f[i]<<' '<<sumf[i]<<endl;
			g[0]=1;
			for (int i=2;i<=n;i+=2)
			{
				for (int j=1;j<i;j+=2) if ((getsumo(j,(i+j)/2)==0)&&(getsumw((i+j)/2+1,i)==0)) g[i]+=g[j-1];
			}*/
			
			return f[n];
				
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; int Arg4 = 2; int Arg5 = 0; int Arg6 = 6; int Arg7 = 7; int Arg8 = 1; int Arg9 = 6; verify_case(0, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 19; int Arg2 = 12; int Arg3 = 9; int Arg4 = 15; int Arg5 = 1; int Arg6 = 8; int Arg7 = 11; int Arg8 = 1; int Arg9 = 26; verify_case(1, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 24; int Arg2 = 34; int Arg3 = 5; int Arg4 = 11; int Arg5 = 33; int Arg6 = 35; int Arg7 = 23; int Arg8 = 27; int Arg9 = 296; verify_case(2, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 60; int Arg1 = 35; int Arg2 = 8; int Arg3 = 55; int Arg4 = 3; int Arg5 = 11; int Arg6 = 20; int Arg7 = 9; int Arg8 = 29; int Arg9 = 10058904; verify_case(3, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 2000; int Arg1 = 183; int Arg2 = 994; int Arg3 = 862; int Arg4 = 468; int Arg5 = 148; int Arg6 = 433; int Arg7 = 1247; int Arg8 = 1989; int Arg9 = 532199331; verify_case(4, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 2000000; int Arg1 = 419443; int Arg2 = 1305303; int Arg3 = 1761823; int Arg4 = 1007025; int Arg5 = 874640; int Arg6 = 1516339; int Arg7 = 229519; int Arg8 = 1473199; int Arg9 = 861766906; verify_case(5, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_6() { int Arg0 = 8; int Arg1 = 6; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 3; int Arg6 = 3; int Arg7 = 6; int Arg8 = 1; int Arg9 = 0; verify_case(6, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        WolfDelaymasterHard ___test;
        ___test.run_test(3);
        return 0;
}
// END CUT HERE