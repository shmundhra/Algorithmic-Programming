//https://codeforces.com/contest/1090/problem/D

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
	ll n, m, a1[100001], a2[100001], i, j, k, stat=0, x, y;
	map < pair < ll , ll > , ll > mp;
	cin>>n>>m;
	fo(i,m)
	{
		cin>>j>>k;
		mp[{j,k}] = mp[{k,j}] = 1;
	}
	if(n==1)
	{
		cout<<"NO";
		return(0);
	}
	Fo(i,1,n+1)
	{
		if(stat==1)break;
		Fo(j,1,n+1)
		{
			if(i==j)continue;
			if(mp[{i,j}]==0)
			{
				stat = 1;
				x = i;
				y = j;
				break;
			}
		}
	}
	if(stat==0){cout<<"NO";return(0);}
	a1[x] = 1;
	a1[y] = 2;
	a2[x] = 1;
	a2[y] = 1;
	j = 3;
	Fo(i,1,n+1)
	{
		if(i==x or i==y)continue;
		a1[i] = a2[i] = j;
		j++;
	}
	cout<<"YES"<<endl;
	Fo(i,1,n+1)cout<<a1[i]<<" ";cout<<endl;
	Fo(i,1,n+1)cout<<a2[i]<<" ";cout<<endl;

}