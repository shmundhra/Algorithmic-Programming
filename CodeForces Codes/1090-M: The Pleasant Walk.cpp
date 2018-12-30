//https://codeforces.com/contest/1090/problem/M

#include <bits/stdc++.h>
using namespace std;
 
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pll pair < ll , ll > 
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end() 

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
 
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
 
using namespace std;
/**************************************************************************/
int main()
{
	ll n, k, i, j, a[100001], ans;
	cin>>n>>k;
	fo(i,n)cin>>a[i];
	i = 0;
	while(i<n)
	{
		ll temp = 1;
		while(i<n-1 and a[i]!=a[i+1])temp++,i++;
		ans = max(ans, temp);
		i++;
	}
	cout<<ans;
}