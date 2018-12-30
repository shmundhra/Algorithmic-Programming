//https://codeforces.com/contest/1003/problem/C

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
#define iu(x) ul x ; cin>>x ; 
#define il(x) ll x ; cin>>x ;  
#define pr(x) cout<<x ;   
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long int)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n ) 	 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  
#define fast ios::sync_with_stdio(false); cin.tie(0);

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; 



int main () 
{
	fast 

	int n , k ;	cin>>n>>k ;

	vll v(n) ;  	
	
	lp( i , n ) 
	{
		cin>>v[i] ; 		
	}

	
	double total = 0 ; 
	
	for ( int len = k ; len <= n ; len++ )
	{   
        ll sum = 0 ; 
		for ( int i  = 0 ; i < len ; i++)
		{
			sum+= v[i] ; 
		}
        
		ll maxsum = sum ;
		for ( int i = len ; i < n ; i++ )
		{
			sum += v[i]-v[i-len] ; 
			maxsum = maxi ( sum , maxsum) ; 
		} 
        
		double av = (long double)maxsum/(long double)len ; 
		
		if ( total < av )
			total = av ; 
	}
	printf( "%.15lf" , total) ; 
	return 0 ; 
}
