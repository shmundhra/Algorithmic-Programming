//https://codeforces.com/contest/1228/problem/B

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
#define sp cerr<<"\n";
#define spp cerr<<"\n\n";
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
    fast
    ll h , w ; cin >> h >> w;
    vi r(h), c(w);
    lp(i,h) cin>>r[i];
    lp(i,w) cin>>c[i];

    lp(i,h) {
        int j = r[i];
        if (j < w and c[j] > i)
        {   
            // cerr<<"ERROR"<<nl;
            cout << 0 << endl;
            return 0;
        }
    }

    lp(j,w) {
        int i = c[j];
        if (i < h and r[i] > j)
        {   
            // cerr<<"ERROR"<<nl;
            cout << 0 << endl;
            return 0;
        }
    }

    vector<vi> mat(h, vi(w,0));

    lp(i,h)
    {
        lp(j, r[i]) mat[i][j] = 1;
        if (r[i] == w) continue;
        mat[i][r[i]] = -1;
    }

    vector<vi> row(h, vi(w,0));
    lp(i,h)
    {
        lpr(j, 1, w)
        {
            if (mat[i][j-1] == -1 or row[i][j-1] == 1)
            {
                row[i][j] = 1;
            }
        }
    }


    lp(j,w)
    {
        lp(i, c[j]) mat[i][j] = 1;
        if (c[j] == h) continue;
        mat[c[j]][j] = -1;
    }

    vector<vi> col(h, vi(w,0));
    lp(j,w)
    {
        lpr(i, 1, h)
        {
            if (mat[i-1][j] == -1 or col[i-1][j] == 1)
            {
                col[i][j] = 1;
            }
        }
    }
    
    // lp(i,h) {
    //     lp(j,w) cerr << mat[i][j] << " ";
    //     sp;
    // }spp
    // lp(i,h) {
    //     lp(j,w) cerr << row[i][j] << " ";
    //     sp;
    // }spp
    // lp(i,h) {
    //     lp(j,w) cerr << col[i][j] << " ";
    //     sp;
    // }
    ll dc = 0;
    lp (i,h) lp (j,w) if (row[i][j] * col[i][j]) dc++;

    cout << modExp(2 , dc, MOD) << endl;

    return 0 ;
}
