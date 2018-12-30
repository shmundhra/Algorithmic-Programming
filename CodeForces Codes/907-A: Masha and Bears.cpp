//https://codeforces.com/contest/907/problem/A

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
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; sc(t) ; while ( t-- )

int main() {
	
	scl(v1) ; 
	scl(v2) ; 
	scl(v3) ; 
	scl(v) ; 
	
	ll s , m , l ; 
	s = -1 ; 
	m = -1 ; 
	l = -1 ; 
	
	ll b , e ; 
	
	if ( v3 < v )
	{
	    if ( 2*v3 < v )
	    {
	        cout<<-1 ;
	        return 0 ; 
	    }
	    b = v ; 
	    e = 2*v3 ; 
	}
	else
	{
	    if ( 2*v < v3 )
	    {
	        cout<<-1 ;
	        return 0 ; 
	    }
	    b = v3 ; 
	    e = 2*v ; 
	}

	    s = b ;
	    
	    ll x = max ( s , max ( v2 , 2*v + 1 )) ; 
	    ll y =  2*v2 ;  
	    if ( y < x )
	    {
	        cout<< -1 ; 
	        return 0 ; 
	    }
	    
	    m = x ;
	    if ( m == s ) m ++ ; 
	    
	    ll p = max ( m , v1 ) ; 
	    ll q = 2*v1 ; 
	    if ( q < p )
	    {
	         cout<< -1 ; 
	         return 0 ;
	    }
	    
	    l = p ; 
	    if ( l == m ) l++ ; 
	    
	    cout<<l<<" "<<m<<" "<<s ;         
	   	return 0;
}















