// https://www.codechef.com//ISCC2018/problems/T28

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
unsigned long long modexpCALC ( long long base , long long expo , long long modulo )
{  
   // NON NEGATIVE BASE AND POSITVE EXPONENT 
   base = base % modulo ;
   expo = expo % (modulo - 1) ; 
   
   unsigned long long ans = base ? 1 : 0 ;

   while ( expo )
   {
       if ( expo&1 )
           ans = (ans * base) % modulo ;

       expo >>= 1 ;
       base = (base*base)% modulo  ;

   }

   return ans ;
}

int modexp ( long long BASE , long long EXPO , long long modulo )
{  
   long long base = ( (BASE >= 0) ? BASE : -BASE) ; 
   long long expo = ( (EXPO >= 0) ? EXPO : -EXPO) ; 

   long long ans = modexpCALC( base , expo , modulo ) ; 

   if ( BASE < 0 && expo%2 == 1 )   // ODD POWER OF A NEGATIVE BASE will be NEGATIVE  
   {
        ans = ( modulo - ans ) % modulo ; 
   }

   if ( EXPO < 0 )                  // NEGATIVE EXPONENT , MODULO INVERSE PROCEDURE 
   {
        ans = modexpCALC ( ans , modulo - 2 , modulo ) ; 
   }
    
    return (int)ans ; 
}

int main () 
{
	fast 
	
	ll n , q; cin>>n>>q ; 
	map < ul , ll > M ; 

	ul x , y ; 

	lp ( i , n )
	{
		cin>>x>>y ; 
		if ( x < y ) swap(x,y) ; 
		M[ 4*x*y + 2*x ]++ ; 
	}

	lp ( i , q )
	{
		ul k ; 
		cin>>k;	 
		auto it = M.find(k*(k+1)) ; 

		if ( it == M.end() ) 
		{
			cout<<-1<<endl ; 
		}
		else
		{
			cout<<modexp(it->second,MOD,MOD+2)<<endl ; 
		}		
	}
	return 0 ; 
}
