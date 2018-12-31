// https://www.codechef.com//JAN18/problems/MAXSC

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair<ll, ll>  pll ;
typedef pair< ll , pll > edge ; 
typedef vector < ll > uwg ;
typedef vector < pll > wg ;

#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) ll arr[n+10] = {0} ; lp ( i , n) cin>>arr[i] 

int main() {
	 
	tc(t)
	{
	    scl(n) ; 
 	    ll a[n][n] ; 
 	    
 	    lp ( i , n )
	        lp ( j , n )
	            cin>>a[i][j] ; 
	      
	    ll inf = 1E10 ;
	    ll sum = 0 ; 
	     
	    for ( int i = n-1 ; i >= 0 ; i -- )
	    {   
	        ll high = -1 ;
	        lp (  j , n )
	        {
	            if ( a[i][j] < inf )
	            {
	                high = max ( high , a[i][j] ) ; 
	            }
	        }
	        if ( high == -1 )
	        {
	            sum = -1 ; 
	            break ; 
	        }
	        sum += high ; 
	        inf = high ; 
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
