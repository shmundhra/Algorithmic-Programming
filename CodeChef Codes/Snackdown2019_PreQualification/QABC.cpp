// https://www.codechef.com/SNCKQL19/problems/QABC

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
#define nl '\n' 
#define is == 
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

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( vec_name ) for ( auto val : vec_name ) cout<<val<<" " ; cout<<nl 

#define fast ios::sync_with_stdio(false); cin.tie(0);

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; // 18! tak hai 



int main () 
{
	fast 	
	string ans[2] ; 
	ans[0] = "NIE\n" ; 
	ans[1] = "TAK\n" ;

	tc(t)
	{
		ll n ; 
		cin>>n ; 

		vll a(n) , b(n) ; 
		lp ( i , n ) cin>>a[i] ; 
		lp ( i , n ) cin>>b[i] ; 

		int flag = 1 ; 
		for ( int i = n-1 ; i >=2 ; i-- )
		{
			if ( b[i] < a[i] or (b[i] - a[i])%3 )
			{
				flag = 0 ; 
				break ; 
			}			
			a[i-1] += 2* ( ( b[i] - a[i] ) / 3 ) ; 
			a[i-2] += ( b[i] - a[i] ) / 3 ; 
			a[i] = b[i] ; 
		}
		if ( n>=1 and a[0] != b[0] ) flag = 0 ;
		if ( n>=2 and a[1] != b[1] ) flag = 0 ; 

		cout<<ans[flag] ; 
	}
	return 0 ; 
}
