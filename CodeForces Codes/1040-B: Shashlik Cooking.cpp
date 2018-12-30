//https://codeforces.com/contest/1040/problem/B

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ; 
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

#define MOD 1000000007 
#define vec vector    
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )      
#define umap unordered_map 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);

#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

int main () 
{
    fast 
    ll n , k ; 
    cin>>n>>k ; 

    vi v( n+1 , 0 ) ; vi ans ;
    ll count = 0 ; ll start = 1 ;     

    ll val = (n+2*k)/(2*k+1) ; 
    
    ll offset = 0 ; 
    ans.pb(1) ; 
    
    for ( int start = k+2 ;   ; start += 2*k+1 )
    {
        if ( start > n ) break ; 
        
        if ( start + k > n )
        {
            offset = n - start + 1 ; 
            break ; 
        }
        
        ans.pb(start + k) ; 
    }
    
    cout<<val<<endl ; 
    lp ( i , sz(ans) ) cout<<ans[i]+offset<<" " ; cout<<endl ;
    return 0 ;     

}
