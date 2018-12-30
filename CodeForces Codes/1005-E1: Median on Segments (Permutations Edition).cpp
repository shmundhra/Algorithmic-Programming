//https://codeforces.com/contest/1005/problem/E1

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
	
	ll n , m ; 
	cin>>n>>m ; 

	inarr(n) ; 

	int i ; 
	for ( i = 0 ; i < n ; i++ ) if ( v[i] == m ) break ; 

	int l = i ; 
	
	vll a(n) ; 
	a[l] = 0 ; 

	unordered_map < ll , ll > L , R ; 
    
	R[0] ++ ; 
	for ( int j = l + 1 ; j < n ; j++  ) 
	{
		if ( v[j] > v[l] ) a[j] = a[j-1] + 1 ; 
		else a[j] = a[j-1]-1 ; 

		R[ a[j] ] ++ ; 
	}
    
    L[0] ++ ;     
	for ( int j = l - 1 ; j >= 0 ; j-- ) 
	{
		if ( v[j] > v[l] ) a[j] = a[j+1] + 1 ; 
		else a[j] = a[j+1] - 1 ; 

		L[ a[j] ] ++ ; 
	}

	ll count = 0 ;
		
	for ( auto it = L.begin() ; it != L.end() ; it++ )
	{
		int val = it->first ; 
		count += (it->second)*(R [ -val ] + R [ -(val-1) ]) ; 
	}

 	cout<<count<<endl ; 
 	
	return 0 ; 
}
