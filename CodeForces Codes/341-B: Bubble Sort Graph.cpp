//https://codeforces.com/contest/341/problem/B

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

void update ( vector < ll > &BIT , int index , int value )
{
	for ( int i = index ; i < BIT.size() ; i += i&(-i) )
	{
		BIT[i] = maxi ( BIT[i] , value ) ; 
	}
}

int query ( vector < ll > &BIT , int index )
{	
	int ans = 0 ; 
	for ( int i = index ; i > 0; i -= i&(-i) )
	{
		ans = maxi ( BIT[i] , ans ) ; 
	}
	return ans ; 
}

int LIS ( vector < ll > &v )
{
	v.insert(v.begin() , 1 , 0 ) ; 
	vector < ll > BIT ( v.size() , 0 ) ; 
	vector < ll > A ( v.size() , 0 ) ; 

	vector < pair < int , int > > vp ; 

	for ( int i = 1 ; i < v.size() ; i++ ) 
		vp.push_back(make_pair(v[i] , i) ) ; 

	sort ( vp.begin() , vp.end() ) ; 	

	for ( int i = 0 ; i < vp.size() ; i++ )
		A[ vp[i].second ] = i+1 ; 
    
    //lp( i , sz(v)-1 ) printf("%3d" , v[i+1] ) ; cout<<endl ;  
    //lp ( i , sz(A)-1 ) printf("%3d" , A[i+1] ) ; cout<<endl ; 
    
	for ( int i = 1 ; i < A.size() ; i++ )
	{
		update ( BIT , A[i] , query ( BIT , A[i]-1 ) + 1 ) ; 
	}
    
    //lp ( i , sz(BIT)-1 ) printf("%3d" , query( BIT , A[i+1] ) ) ; cout<<endl ; 
    
	return query ( BIT , sz(BIT)-1 ) ; 
}

int main ()
{
    ll n ; 
    cin>>n ; 
    
    inarr(n) ; 
    
    cout<<LIS(v) ; 
    
    return 0 ; 
}