//https://codeforces.com/contest/1090/problem/K

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
	fastIO;
	vector < string > v1, v2;
	ll t, n, i, j, k;
	string s1, s2, s3;
	cin>>n;
	string empty;
	map < pair < string , string > , vector < ll > > mp;
	fo(i,n)
	{
		cin>>s1>>s2;
		ll stat = 1;
		map < char , ll > tempo;
		for(auto x:s2)tempo[x] = 1;
		j = s1.size();j--;
		while(j>=0 and tempo[s1[j]]==1){s1.pop_back();j--;}
		s3.clear();
		Fo(j,97,123)if(tempo[char(j)]==1)s3.pb(char(j));
		mp[{s1,s3}].pb(i+1);
	}
	cout<<mp.size()<<endl;
	for(auto x:mp)
	{
		cout<<x.S.size()<<" ";
		for(auto y:x.S)cout<<y<<" ";
		cout<<endl;
	}

}