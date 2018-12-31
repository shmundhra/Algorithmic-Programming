// https://www.codechef.com/problems/ABX01

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
#define tc(t) scu(t); while ( t-- )

ll sod ( ul a )
{
    if ( a%9 == 0 )
        return 9 ; 
    else
        return a%9 ; 
}

int main() {
	
	tc(t) 
	{   
	    scu(a) ; scu(n) ; 
	    
	    uwg v ; 
	    for ( ll i = n ; i > 0 ; i/= 18 )
	    {
	        v.pb( i%18 ) ; 
	    }
	    //Vector v contains 18-ary representation of exponent n 
	    /*
	    lp ( i , v.size() )
	        cout<<v[i] ; 
	    cout<<"#" ; 
	    */
	    
	    ul fa = sod ( a ) ;
	    ul f ; 
	    ll ans = 1 ; 
	    lp ( i , v.size() ) 
	    {   
	        f = sod ( (ul)pow( fa , (ul)pow(18,i) ) ) ; 
	        ans *= sod ( (ul) pow( f , v[i]) ) ; 
	        ans  = sod ( ans ) ; 
	    }
	    cout<<ans<<endl; 
	    
	}
	return 0;
}
