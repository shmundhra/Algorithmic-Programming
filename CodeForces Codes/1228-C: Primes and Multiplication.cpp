//https://codeforces.com/contest/1228/problem/C

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ul ;
typedef long long ll ;
typedef string str ;
typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef vector < int > vi ;
typedef vector < ll > vll ;

//#define cerr cout
#define MOD 1000000007
#define vec vector
#define nl '\n'
#define is ==
#define all(v) (v).begin() , (v).end()
#define sumof(v) accumulate ( all(v) , 0LL )
#define maxof(v) max_element( all(v) )
#define minof(v) min_element( all(v) )
#define rev(v) reverse(all(v))
#define sz(v)  (long long)(v).size()
#define lp(i , n ) for ( ll i = 0 ; i < (n) ; i++ )
#define lpd(i , n ) for ( ll i = (n)-1 ; i >= 0 ; i-- )
#define lpc(it , c ) for ( auto it = (c).begin(); it != (c).end(); it++)
#define lpr(i , l , r ) for ( ll i = (l) ; i < (r) ; i++ )
#define lprd(i , l , r ) for ( ll i = (r)-1 ; i >= (l) ; i-- )
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
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i]
#define show ; cerr << 
#define sp ; cerr<<"\n";
#define spp ; cerr<<"\n\n";
#define debug( ds_name ) for ( auto val : ds_name ) cerr<<val<<"\n" ; cerr<<nl
#define debug1(x) cerr<<#x<<" :: "<<x<<flush<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<flush<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<flush<<"\n";
#define fast ios::sync_with_stdio(false); cin.tie(0);

ll modExp(ll x,ll y,ll mod)
{ x %= mod , y%=(mod-1) ; ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}

template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}

int main ()
{   
    fast;

    ll x , n ; 
    cin>>x>>n ; 
    
    vll fact;
    for (ll i = 2 ; i*i <= x ; i++)
    {
        if (x % i == 0)
        {
            fact.pb(i);
            while(x%i == 0) x/=i;
        }
    }
    if (x > 1) fact.pb(x);
    show fact sp

    vll pow;
    for (auto factor : fact)
    {
        ll tot = 0;
        for (ll j = factor; ; j*= factor)
        {   
            tot = (tot + n/j) % (MOD-1);

            if (factor > n/j) break;
        }
        pow.pb(tot);
    }
    show pow sp

    vll arr;
    lp(i, sz(fact)){
        arr.pb( modExp(fact[i], pow[i], MOD) );
    }

    ll myans = 1;
    lp(i , sz(arr)){
        myans = (myans * arr[i]) % MOD;
    }

    
    cout << myans << endl;

    return 0 ;
}
