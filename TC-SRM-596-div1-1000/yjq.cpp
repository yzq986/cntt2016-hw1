#include<bits/stdc++.h>
using namespace std;typedef long long LL;class SparseFactorial{public:void solve(int p,int c,int s,vector<LL>&res){res.clear();res.resize(s);for(int k=0;k<p*c;k++){LL K=LL(k)*k;int v=K%s;for(int i=K%p;i<s;i+=p){if(res[i]>0)continue;int j=(i-v+s)%s;if(j==0)res[i]=-c;else while(j%p==0)j/=p,--res[i];if(res[i]<=-c)res[i]=K+1;}}for(int i=0;i<s;i++)if(res[i]<=0LL)res[i]=1e13;}LL getCount(LL l,LL r,LL m){int n=m;LL ret=0LL,low;vector<LL>ans[3];ans[0].push_back(0);for(int i=2,cur=1;n!=1;i++)if(n%i==0LL){n/=i;int p(i),s(i),c(1);for(p=i,s=i,c=1;n%i==0;++c,n/=i,s*=i);solve(p,c,s,ans[1]);ans[2].resize(cur*s);for(int j=0;j<cur*s;++j)ans[2][j]=max(ans[0][j%cur],ans[1][j%s]);ans[0].swap(ans[2]),cur*=s;}l--;for(int i=0;i<m;i++){low=ans[0][i]/m*m+i;if(low<ans[0][i])low+=m;if(r>=low)ret+=(r-low)/m+1;if(l>=low)ret-=(l-low)/m+1;}return ret;}} sol ;

int main() { 
		cout << sol.getCount(4LL ,8LL ,6LL) << endl ; 
}
