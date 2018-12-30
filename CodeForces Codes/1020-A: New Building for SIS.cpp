//https://codeforces.com/contest/1020/problem/A

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
#define lp1(i , n ) for ( ll i = 1 ; i <= n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )      
#define umap unordered_map 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }
ll abso ( ll x ) { return x >= 0 ? x : -x ; }
// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

int main () 
{
    fast 

    ll n , h , a , b , k ; 
    cin>>n>>h>>a>>b>>k ; 

    ll r1,c1,r2,c2 ; 
    while ( k-- )
    {
        cin>>c1>>r1>>c2>>r2 ; 
          
        if ( r1 < a and r2 < a and c1 != c2 )
        {
            cout<< a - r1 + a - r2 + abso(c1-c2) <<endl ; 
            continue ; 
        }

        if ( r1 > b and r2 > b and c1 != c2 )
        {
            cout<< r1 - b + r2 - b + abso(c1-c2) <<endl ; 
            continue ; 
        }

        cout<< abso(r1-r2) + abso(c1-c2) <<endl ; 

    }
    
    return 0 ; 
}
