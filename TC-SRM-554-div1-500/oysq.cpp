#line 2 "TheBrickTowerMediumDivOne.cpp"  
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

const int N = 50;

bool cmp(const pii &p, const pii &q) {
	if(p.fi != q.fi) return p.fi > q.fi;
	else return p.se < q.se;
}

class TheBrickTowerMediumDivOne {  
public:
	vector <int> find(vector <int> h) {
		// ans value must form like decreasing->bottom->increasing (i.e. concave)
		
		int n = SZ(h);
		bool vis[N + 9] = {false};
		
		std::vector<pii> p, q;
		std::vector<int> ret;
		
		// pick lexicographically minimal decreasing sequence
		for(int i = 0; i < n; ++i) p.pb(mp(h[i], i));
		std::sort(p.begin(), p.end(), cmp);
		for(int i = 0; i < n; ++i) {
			int minp = n, pid = -1;
			for(int j = i; j < n; ++j)
				if(p[j].se < minp)
					minp = p[j].se, pid = j;
			if(pid == n - 1) break;// positions of decreasing sequence must < position of bottom in lexicographical order
			vis[pid] = true;
			ret.pb(minp);
			i = pid;
		}

		// pick bottom
		vis[n - 1] = true;
		ret.pb(p[n - 1].se);

		// pick minimal increasing sequence
		for(int i = n - 1; i >= 0; --i)
			if(!vis[i]) q.pb(p[i]);
		std::sort(q.begin(), q.end());
		for(int i = 0; i < SZ(q); ++i) ret.pb(q[i].se);
		
		return ret;
	}    
};  
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                