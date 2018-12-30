//https://codeforces.com/gym/101875/problem/L

#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
/**************************************************************************/
vector < ll > graph[100001];
ll lvl[100001];
void dfs(ll node,ll parent)
{
	ll ans = 0;
	for(auto x:graph[node])
	{
		if(x==parent)continue;
		dfs(x,node);
		ans = max(ans, lvl[x]);
	}
	lvl[node] = 1 + ans;
}
int main()
{
	fastIO;
	ll t,n,i,j,k,root;
	fo(i,100001)graph[i].clear();
	cin>>n>>root;
	fo(i,n-1)
	{
		cin>>j>>k;
		graph[j].pb(k);
		graph[k].pb(j);
	}
	//Fo(i,1,n+1)cout<<lvl[i]<<" ";cout<<endl;
	if(root>n)cout<<1;
	else {dfs(root,0);cout<<lvl[root];}

}

/*************************************************************************/