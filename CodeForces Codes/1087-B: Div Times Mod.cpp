//https://codeforces.com/contest/1087/problem/B

#include <bits/stdc++.h>

using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;
typedef string str ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ; 
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

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
#define lp1(i , n ) for ( ll i = 1 ; i <= (n) ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- ) 	 
#define umap unordered_map 

#define F first 
#define S second
#define pb push_back

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( vec_name ) for ( auto val : vec_name ) cout<<val<<" " ; cout<<nl 
#define fast ios::sync_with_stdio(false); cin.tie(0);
ll modExp(ll x,ll y,ll mod){ ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}
vll calc_fact (ll n , ll mod ){	vll fact(n+1,1) ; lp1 (i,n) fact[i] = (fact[i-1]*i) % mod ; return fact ; }
vll FF( str A ) { vll LPB(sz(A),0); ll len = 0 ; lp1 ( i , sz(A)-1) {if ( A[i] is A[len] ) LPB[i] = ++len ; else if ( len ) len = LPB[len-1] , i-- ; } return LPB ; }
bool KMP( str A, str B, vll LPB ){ ll j=0 ; lp (i,sz(A)) {if ( A[i] is B[j]) {if ( ++j is B.size() ) return true ;} else if (j) {j = LPB[j-1] ; i-- ; } } return false ;}

vll factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; //18!  


int main () 
{
	fast
	ll n , k ; cin>>n>>k ; 
	
	vp v ; 
	for ( int i = 1 ; i <= sqrt(n) ; i++ )
	{
		if ( n%i is 0 )
		{
			v.pb({i,n/i}) ;
		}
	}

	ll ans = INT_MAX ; 
	for ( auto p : v )
	{
		if ( p.F < k )
		{
			ans = min ( ans , k*p.S + p.F ) ; 
		}
		if ( p.S < k )
		{
			ans = min ( ans , k*p.F + p.S ) ;
		}
	}
	cout<<ans<<nl ; 

	return 0 ; 
	
}
