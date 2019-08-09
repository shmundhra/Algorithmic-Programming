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

int main () 
{
	fast 
	
	ll t ; cin>>t ; 
	for ( int testcase = 1 ; testcase<= t ; testcase++ )
	{
		ll n ; 
		cin>>n ; 

		vector <string> s(3,"") ; 
		cin>>s[0]>>s[1]>>s[2] ; 

		cout<<"Case #"<<testcase<<": ";

		if ( n%2 or s[0][0] == '#' or s[2].back() == '#' ) 
		{
			cout<<0<<endl ; 
			continue ; 
		}		

		for ( int j = 0 ; j < n ; j++ )
		{
			if ( s[1][j] == '#' )
			{
				cout<<0<<endl ; 
				continue ; 
			}
		}

		vector < vector <ll> > dp ( 3 , vector < ll > (n,0) ) ; 

		dp[1][1] = 1 ;  

		for ( int j = 2 ; j < n ; j++ )
		{
			if ( j%2 == 1 )
			{
				dp[1][j] = ( dp[0][j-1] + dp[2][j-1] )%MOD ;  
			}
			else
			{
				if ( s[0][j] == '.') dp[0][j] = dp[1][j-1] * ( s[0][j-1] == '.' ) ; 
				if ( s[2][j] == '.') dp[2][j] = dp[1][j-1] * ( s[2][j-1] == '.' ) ; 
			}
		}
		cout<<dp[1].back()<<endl ; 
	}
	
	return 0 ; 
}
