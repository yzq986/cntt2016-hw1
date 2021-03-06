#line 2 "MagicalHats.cpp"  
#include <bits/stdc++.h> 

using namespace std;  

#define ui unsigned
#define ll long long

#define pii std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second

#define SZ(x) (int)(x).size()
#define pb push_back

template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}
template<class T>inline void chkmin(T &x, const T &y) {if(x > y) x = y;}

const int N = 13;
const int S = 1600000;
const int INF = 1e9;

class MagicalHats {  
public:
	int n, m, h, cn, step;
	std::vector<pii> pos;
	std::vector<int> c;
	bool ok[S + 9], vis[S + 9];
	int f[S + 9];
	int pw[N + 9];
	// trans base 2 to base 3
	int t23(const pii p) {
		int ret = 0;
		for(int i = h - 1; i >= 0; --i) {
			ret *= 3;
			if(p.fi >> i & 1)
				ret += (p.se >> i & 1) + 1;
		}
		return ret;
	}
	// check if valid
	bool check(int s) {
		std::bitset<N + 9> r, c;
		for(int i = 0; i < h; ++i)
			if(!(s >> i & 1)) r[pos[i].fi] = 1 - r[pos[i].fi], c[pos[i].se] = 1 - c[pos[i].se];
		for(int i = 0; i < n; ++i) if(r[i]) return false;
		for(int i = 0; i < m; ++i) if(c[i]) return false;
		return true;
	}
	// get ok[]
	bool getok(int s) {
		if(vis[s]) return ok[s];
		vis[s] = true;
		bool &val = ok[s];
		for(int i = 0; i < h; ++i) {
			int x = s % pw[i + 1] / pw[i];
			if(!x) val |= getok(s + pw[i]) | getok(s + 2 * pw[i]);
		}
		return val;
	}
	// dp
	int dp(int s) {
		if(!ok[s]) return -INF;
		if(f[s] >= 0) return f[s];
		int d[N + 9] = {0};
		for(int i = 0; i < h; ++i) d[i] = s % pw[i + 1] / pw[i];
		int cnt = 0;
		for(int i = 0; i < h; ++i)
			cnt += d[i] > 0;
		if(cnt == step) {
			int cnt2 = 0, &ret = f[s];
			ret = 0;
			for(int i = 0; i < h; ++i)
				if(d[i] == 2)
					ret += c[cnt2++];
			return ret;
		}
		int &v = f[s];
		for(int i = 0; i < h; ++i)
			if(s % pw[i + 1] < pw[i]) {
				int x = dp(s + pw[i]), y = dp(s + 2 * pw[i]);
				if(x >= 0 && y >= 0) chkmax(v, std::min(x, y));
				else if(x >= 0) chkmax(v, x);
				else if(y >= 0) chkmax(v, y);
			}
		return v;
	}
	int findMaximumReward(vector <string> g, vector <int> _c, int num) {
		// init
		pos.clear();
		std::sort(_c.begin(), _c.end());

		// get 'H'
		n = SZ(g), m = SZ(g[0]);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(g[i][j] == 'H')
					pos.pb(mp(i, j));
		h = SZ(pos), cn = SZ(_c), step = num, c = _c;

		// init pw3
		pw[0] = 1;
		for(int i = 1; i <= h; ++i) pw[i] = pw[i - 1] * 3;

		// get ok[]
		memset(vis, false, sizeof vis);
		memset(ok, false, sizeof ok);
		for(int i = 0; i < (1 << h); ++i)
			if(__builtin_popcount(i) == cn)
				if(check(i)) {
					int s = t23(mp((1 << h) - 1, i));
					ok[s] = vis[s] = true;
				}
		getok(0);
		
		// dp f[]
		std::fill(f, f + pw[h], -INF);
		int ans = dp(0);
		if(ans < 0) return -1;
		else return ans;
	}  
};  
