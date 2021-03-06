#line 2 "RotatingBot.cpp"  
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

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int maxX, maxY, minX, minY;

class RotatingBot {  
public:
	bool ok(int x, int y) {
		return x >= minX && x <= maxX && y >= minY && y <= maxY;
	}
	bool go(const std::vector<int> moves) {
		std::set<pii> s;
		int x = 0, y = 0;
		s.insert(mp(x, y));
		int d = 0;
		for(int i = 0; i < SZ(moves); ++i) {
			int t = 0;
			// move step by step
			while(!s.count(mp(x + dx[d], y + dy[d])) && ok(x + dx[d], y + dy[d])) {
				x += dx[d], y += dy[d], s.insert(mp(x, y)), t++;
			}
			d = (d + 1) % 4;
			// check "If the rotation left did not help, the robot terminates the execution of this program"
			if(s.count(mp(x + dx[d], y + dy[d])) || !ok(x + dx[d], y + dy[d])) {
				if(i < SZ(moves) - 1) return false;
			}
			// check if walk enough steps
			if(i < SZ(moves) - 1) {
				if(t != moves[i]) return false;
			}
			// check if overflowed
			else {
				if(moves[i] > t) return false;
			}
		}
		return true;
	}
	int minArea(vector <int> moves) {
		// get the range of grid
		maxX = minX = maxY = minY = 0;
		int x = 0, y = 0;
		for(int i = 0; i < SZ(moves); ++i) {
			x += moves[i] * dx[i % 4];
			y += moves[i] * dy[i % 4];
			chkmax(maxX, x), chkmin(minX, x);
			chkmax(maxY, y), chkmin(minY, y);
		}
		// simulate the steps to check if valid
		if(go(moves)) return (maxX - minX + 1) * (maxY - minY + 1);
		else return -1;
	}    
};  
