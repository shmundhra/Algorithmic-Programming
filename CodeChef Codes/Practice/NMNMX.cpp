// https://www.codechef.com/problems/NMNMX

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

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; 

ll modexp ( ll base , ll exp , ll modulo )
{
    base %= modulo ;
    exp  %= (modulo - 1); 
    ll ans = 1 ; 
    while ( exp )
    {
        if ( exp&1 )
        {
            ans = ( ans * base ) %MOD ; 
        }
        base = ( base * base ) %MOD ;
        exp>>=1 ; 
    }
    return ans ; 
}



int main () 
{
	fast 
	
    vec < vec < ul > > ncr ( 5001 , vec < ul > ( 5001 , 0 ) ) ;   
    
    lp ( i , 5001 ) ncr[i][i] = ncr[i][0] = 1 ;
    
    rep ( i , 1 , 5001 , 1 )
           rep ( j , 1 , i , 1 )
                   ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%(MOD-1) ;  
    
    tc(t)    
    {
        ll n , k ; 
        cin>>n>>k ; 
        
        inarr(n) ; 
        sort(all(v)) ; 
        
        ll ans = 1 ; 
        
        lp ( i , n )
        {
            ll left = i ; 
            ll right = n-i-1 ; 
            
            ll exp = ( ncr[n-1][k-1] - ncr[left][k-1] - ncr[right][k-1] + MOD - 1 + MOD - 1 )%(MOD-1) ; 
            ll val = modexp ( v[i] , exp , MOD ) ;
            
            ans = ( ans * val ) %MOD ; 
        }
        cout<<ans<<endl ;               
    }
    
	return 0 ; 
}
