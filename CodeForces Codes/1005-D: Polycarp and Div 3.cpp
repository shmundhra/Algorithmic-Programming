//https://codeforces.com/contest/1005/problem/D

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
	
	string a ; cin>>a ; 

	vll v ; 
	lp ( i , sz(a) )
	{
		v.pb( (a[i]-'0')%3 ) ; 
	}
	v.pb(3) ; 
	v.pb(3) ; 
	v.pb(3) ; 
    //lp ( i ,sz(v) ) cout<<v[i] ; cout<<endl ; 
    
	ll count = 0 ; 

	int i ; 
	for ( i = 0 ; v[i] < 3 ; )
	{  
               
		if ( v[i] == 0 )
		{
			count++ ; 
			i++ ; 
		}
		else if ( v[i] == 1 )
		{
			if ( v[i+1] == 0 or v[i+1] == 2 )
			{
				count++ ; 
				i+=2 ; 
			}
			else if ( v[i+2] == 0 or v[i+2] == 1 or v[i+2] == 2 )
			{
				count++ ; 
				i+=3 ; 
			}
            else
            {
                break ; 
            }
		}
		else if ( v[i] == 2 )
		{
			if ( v[i+1] == 0 or v[i+1] == 1 )
			{
				count++ ; 
				i+=2 ; 
			}
			else if ( v[i+2] == 0 or v[i+2] == 1 or v[i+2] == 2 )
			{
				count++ ; 
				i+=3 ; 
			}
            else
            {
                break ; 
            }
		}
        else
        {
            break ; 
        }
	}	

	cout<<count<<endl ;
    
	return 0 ; 
}
