//https://codeforces.com/contest/913/problem/B

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


int main() {
	 
	 scl(n) ; 
	 
	 uwg adj[n+1] ; 
	 ll par ; 
	 rep ( i , 1 , n , 1)
	 {
	     cin>>par ; 
	     adj[par].pb(i+1) ; 
	 }
	 
	 rep ( i , 1, n+1 , 1)
	 {
	     if( adj[i].size() != 0 )
	     {
	        ll c = 0 ; 
	        lp ( j , adj[i].size() )
	        {
	            ll v = adj[i][j] ; 
	            if ( adj[v].size() == 0)
	                c++ ; 
	        }
	        if ( c < 3)
	        {
	            cout<<"No" ; 
	            return 0 ; 
	        }
	      
	     }
	 }
	 cout<<"Yes" ; 
	 
	return 0;
}









