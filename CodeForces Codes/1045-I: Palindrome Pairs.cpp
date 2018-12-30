//https://codeforces.com/contest/1045/problem/I

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long int  ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define pic pair<ll,char>
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define st  set <ll, greater <ll> >
#define mst  multiset <ll, greater <ll> >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mapp  unordered_map <ll, ll>
#define ppii pair< pii, pii > 
#define test(t) ll t;cin>>t;while(t--)
#define inarr(n) ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i];
#define ingra(m) vvi arr(100005);for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;arr[u].pb(v);arr[v].pb(u);}
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res;}

int main()
{
  fast;
  ll n,i;
  cin>>n;
  vector < string > odd;
  vector < string > even;
  map < string,ll > od;
  map < string , ll > ev;
  for(i=0;i<n;i++)
  {
    string s;
    cin>>s;
    ll l = s.length();
    ll freq[26]= {0};
    for(auto v:s)
        freq[v-'a']++;
    ll j;
    for(j=0;j<26;j++)
        freq[j]%=2;
    string temp="";
    for(j=0;j<26;j++)
    {
        if(freq[j]==0)
            temp+="0";
        else
            temp+="1";
    }
    if(l%2)
        od[temp]++,odd.pb(temp);
    else
        ev[temp]++,even.pb(temp);
  }
  ll ans = 0;
  for(auto v:od)
  {
    ans = (ans + ((v.sec*(v.sec-1))/2));
  }
  for(auto v:ev)
  {
    ans = (ans + ((v.sec*(v.sec-1))/2));
  }
  for(auto v:od)
  {
    string temp = v.fi;
    ll mul = v.sec;
    for(i=0;i<26;i++)
    {
        if(temp[i]=='0')
        {
            temp[i]='1';
            ans+=(mul*ev[temp]);
            temp[i]='0';
        }
        else
        {
            temp[i]='0';
            ans+=(mul*ev[temp]);
            temp[i]='1';
        }
    }
  }
  cout<<ans;
}