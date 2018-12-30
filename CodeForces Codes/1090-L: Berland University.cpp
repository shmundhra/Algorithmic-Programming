//https://codeforces.com/contest/1090/problem/L

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
	ll t, n, a, b, k, i, j, cla = 0, ans = 0;
	cin>>t>>n>>a>>b>>k;
	ll st = 0, ed = t, md;
	while(st<=ed)
	{
		md = st + ( ed - st ) / 2;
		ll a1 = min(a, md), b1 = min(b, md), cla;
		cla = ((n+1)/2) * a1 + (n/2) * b1;
		if(cla>=k*md)
		{
			ans = md;
			st = md + 1;
		}
		else ed = md - 1;
	}
	cout<<ans;

}