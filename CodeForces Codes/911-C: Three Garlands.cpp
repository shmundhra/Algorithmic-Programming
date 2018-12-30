//https://codeforces.com/contest/911/problem/C

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
#define tc(t) scu(t); while ( t-- )

int main() {
	
	scl(k1) ; 
	scl(k2) ; 
	scl(k3) ; 
	
	if ( k1 == 1 || k2 == 1 || k3 == 1 )
	{
	    cout<<"YES";
	    return 0 ; 
	}
	if (  k1 == 3 && k2 == 3 && k3 == 3 )
	{
	      cout<<"YES";
	      return 0 ; 
	}
	
	ll a, b ,c ; 
	
	a = max ( k1 , max ( k2 , k3 ) ) ;
	c = min ( k1 , min ( k2 , k3 ) ) ; 
	b = k1 + k2 + k3 - a - c ; 
	
	if ( c == 2 && b == 2 )
	{
	    cout<<"YES";
	    return 0 ;
	}
	
	if ( a == 4 && b == 4 && c == 2 )
	{
	      cout<<"YES";
	      return 0 ; 
	}
	
	cout<<"NO" ; 
	return 0 ;
}
















