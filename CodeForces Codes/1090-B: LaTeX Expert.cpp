//https://codeforces.com/contest/1090/problem/B

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
	ll t, n, i, j, k, cnt = 0;
	map < string , int > m1, m2;
	vector < string > bibs, finalbiblio;
	bibs.clear();
	m1.clear();
	m2.clear();
	string start = "\\begin{thebibliography}{99}";
	string end = "\\end{thebibliography}";
	string s;
	getline(cin,s);
	while(s!=start)
	{
		istringstream is(s);
		while(is>>s)
		{
			if(s.length()>=5 and s[0]=='\\' and s[1]=='c'
				and s[2]=='i' and s[3]=='t' and s[4]=='e')
			{
				j = 6;
				string temp;
				while(s[j]!='}')
				{
					temp.pb(s[j]);
					j++;
				}
				m1[temp] = ++cnt;
				bibs.pb(temp);
			}
		}
		getline(cin,s);
		i++;
	}
	getline(cin,s);
	cnt = 0;
	while(s!=end)
	{
		string temp;
		j = 9;
		while(s[j]!='}')
		{
			temp.pb(s[j]);
			j++;
		}
		m2[temp] = ++cnt;
		finalbiblio.pb(s);
		getline(cin,s);
	}
	ll stat = 1;
	for(auto x:bibs)
	{
		if(m1[x]!=m2[x])
		{
			stat=0;break;
		}
	}
	if(stat==1){cout<<"Correct";return(0);}
	else cout<<"Incorrect"<<endl;
	cout<<start<<endl;
	for(auto x:bibs)
	{
		//cout<<x<<endl;
		cout<<finalbiblio[m2[x]-1]<<endl;
	}
	cout<<end<<endl;

}