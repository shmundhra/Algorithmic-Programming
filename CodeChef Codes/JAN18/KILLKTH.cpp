// https://www.codechef.com/JAN18problems/KILLKTH

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

#define vec vector 
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

bool comp ( string s1 , string s2 )
{
    if ( s1.compare(s2) < 0 )
        return true ; 
        
    else
        return false ; 
}

int main() {
	 
	string s ; 
	cin>>s ; 
	ll len = s.size() ; 
	
	vector < string > v ;  
	lp ( i , len )
	{
	    rep ( j , i+1 , len +1 , 1 )
	    {
	        string c ; 
	        c.append ( s.begin() + i , s.begin() + j ) ; 
	        v.pb(c) ; 
	    }
	}
	
	sort ( v.begin() , v.end() ) ; 
	
	string h ; 
	lp ( i , v.size() ) 
	{
	    h.append( v[i].begin() , v[i].end() ) ; 
	}
	//cout<<h<<endl;
	
	ul g = 0 ;
	tc(q)
	{
	    scl(p) ; 
	    scl(m) ; 
	    
	    ll k = ((p%m)*(g%m))%m + 1 ; 
	    
	    g += h[k-1] ;
	    
	    cout<<h[k-1]<<endl ; 
	    
	}
	
	return 0;
}






















