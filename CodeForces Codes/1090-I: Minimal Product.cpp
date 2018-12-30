//https://codeforces.com/contest/1090/problem/I

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
ll a[10000001], b[10000001];
const ll mod = 1ll<<32;
int main()
{
	fastIO;
	ll t;cin>>t;while(t--)
	{
		ll n, i, j, k, l, r, x, y, z, ans, stat = 0;
		cin>>n>>l>>r>>x>>y>>z>>b[0]>>b[1];
		Fo(i,2,n)b[i] = ((b[i-2]*x + b[i-1]*y + z)%mod+mod)%mod;
		fo(i,n)
		{
			k = ( r - l + 1 ) ;
			a[i] = ((b[i]%k+k)%k) + l;
		}
		ll mn = a[0] ;
		Fo(i,1,n)
		{
			if(mn>=a[i]){mn=a[i];continue;}	
			if(stat==0){ans = mn*a[i];stat = 1;}
			else ans = min(ans, mn*a[i]);
		}
		ll mx = a[n-1];
		for(i=n-2;i>=0;i--)
		{
			if(mx<=a[i]){mx=a[i];continue;}
			if(stat==0){ans = mx*a[i];stat = 1;}
			else ans = min(ans, mx*a[i]);
		}

		if(stat==0)cout<<"IMPOSSIBLE"<<endl;
		else cout<<ans<<endl;
	}

}