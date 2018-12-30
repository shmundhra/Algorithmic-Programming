//https://codeforces.com/gym/101875/problem/A

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
int main()
{
	fastIO;
	ll n,k,i;
	cin>>n>>k;
	i = __gcd(n,k);
	cout<<((n-1)*k-(i-1));
}