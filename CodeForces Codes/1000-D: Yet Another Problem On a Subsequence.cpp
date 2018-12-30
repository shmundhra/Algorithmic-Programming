//https://codeforces.com/contest/1000/problem/D

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

#define modu 998244353 

int main () 
{
	unsigned long long ncr[1001][1001] ; 

	lp ( i , 1001 ) ncr[i][0] = 1 ; 

	lp ( i , 1001 ) ncr[i][i] = 1 ; 

	lp ( i , 1001 ) 
		for ( int j = 1 ; j < i ; j++ )
			ncr[i][j] = ( ncr[i-1][j] + ncr[i-1][j-1] ) % modu ; 

	int n ; 
	cin>>n ; 

	vll A(n) ; 
	lp ( i , n ) cin>>A[i] ; 

	vec < ul > F( n+1 ) ; 
	F[n] = 0 ;
	F[n-1] = 0 ; 

	for ( int i = n-2 ; i >= 0 ; i-- )
	{
		ul count = F[i+1] ; 
		if ( A[i] > 0 )
		{
			for ( int j = i+A[i] ; j<n ; j++ )
			{
				count = ( count + ( ncr[j-i-1][A[i]-1] * ( 1 + F[j+1] ) ) % modu ) % modu ; 
			}
		}
		F[i] = count ; 
	}

	cout<<F[0]<<endl ; 
}