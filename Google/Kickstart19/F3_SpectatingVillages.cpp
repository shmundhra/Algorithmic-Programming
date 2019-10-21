#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ul ;
typedef long long ll ;
typedef string str ;
typedef pair <int, int >  pii ;
typedef pair <ll, ll>  pll ;
typedef vector <int> vi ;
typedef vector <bool> vb ;
typedef vector <ll> vll ;

//#define cerr cout
#define MOD 1000000007
#define vec vector
#define nl '\n' << flush
#define is ==
#define all(v) (v).begin() , (v).end()
#define sumof(v) accumulate ( all(v) , 0LL )
#define maxof(v) max_element( all(v) )
#define minof(v) min_element( all(v) )
#define rev(v) reverse(all(v))
#define sz(v)  (long long)(v).size()
#define lp(i, n) for ( ll i = 0 ; i < (n) ; i++ )
#define lpd(i, n) for ( ll i = (n)-1 ; i >= 0 ; i-- )
#define lpc(it, c) for ( auto it = (c).begin(); it != (c).end(); it++)
#define lpr(i, l, r) for ( ll i = (l) ; i < (r) ; i++ )
#define lprd(i, l, r) for ( ll i = (r)-1 ; i >= (l) ; i-- )
#define umap unordered_map

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define inf INT_MAX
#define eps 1e-6

#define tc(t) ul testcases ; cin>>testcases ; for ( int testcase = 1 ; testcase <= testcases ; testcase++ )
#define prntc cout<<"Case #"<<testcase<<": " ;
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]
#define invec(vec_name) lp ( i , sz(vec_name) ) cin>>vec_name[i]
#define fast ios::sync_with_stdio(false); cin.tie(0);

#ifndef ONLINE_JUDGE
#define show ; cerr <<
#define sp ; cerr << "\n";
#define debug(ds_name) for ( auto val : ds_name ) cerr<<val<<"\n" ; cerr<<"\n";
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__);
#else
#define show {}
#define sp {}
#define debug(ds_name) {}
#define pr(...) {}
#endif

ll max(ll x, int y) {return max(x, (ll)y);} ll max(int x, ll y) {return max((ll)x, y);}
ll modExp(ll x,ll y,ll mod) { x %= mod , y%=(mod-1) ; ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}

template <class T> ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class S, class T> ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }
template <class T, class... S> void dbs(string str, T t, S... s) { int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...); }

// Seperating String
string sep = "----------------\n";
// Array for factorials
vector <unsigned long long> factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000   } ; // 18! tak hai

vll v, o, l, d;
vec<vll> adj;

void solve(ll i, ll par)
{
    if (sz(adj[i]) is 1 and adj[i][0] is par)   // LEAF
    {
        o[i] = v[i];
        l[i] = INT_MIN;
        d[i] = 0;
        return;
    }

    lp(j, sz(adj[i]))                           // POST-ORDER
    {
        ll ch = adj[i][j];
        if (ch is par) continue;
        solve(ch, i);
        // pr(ch, o[ch], l[ch], d[ch])
    }

    d[i] = 0;
    lp(j, sz(adj[i]))
    {
        ll ch = adj[i][j]; if (ch is par) continue;
        d[i] += max(d[ch], l[ch]);
    }

    o[i] = v[i];
    lp(j, sz(adj[i]))
    {
        ll ch = adj[i][j]; if (ch is par) continue;
        o[i] += max(v[ch] + d[ch], max(o[ch], l[ch]));
    }

    l[i] = v[i];
    ll flag = 0, mindiff = INT_MAX;
    lp(j, sz(adj[i]))
    {
        ll ch = adj[i][j]; if (ch is par) continue;
        if (o[ch] >= max(d[ch], l[ch]))
        {
            l[i] += o[ch];
            flag = 1;
        }
        else
        {
            l[i] += max(d[ch], l[ch]);
            mindiff = min(mindiff, (max(d[ch], l[ch])-o[ch]));
        }
    }
    if (!flag) l[i] -= mindiff;
    // pr(i, flag, mindiff) sp

    return;
}

signed main ()
{
    fast;
    tc(t)
    {
        ll n; cin>>n;
        adj.assign(n, vll());
        v.assign(n,0), o.assign(n,0), l.assign(n,0), d.assign(n,0);
        invec(v);

        lp(i,n-1)
        {
            ll x, y; cin>>x>>y; x--, y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        solve(0, -1);
        vll ans{o[0], l[0], d[0]};
        prntc cout<<*maxof(ans)<<endl;

    }
    return 0 ;
}
