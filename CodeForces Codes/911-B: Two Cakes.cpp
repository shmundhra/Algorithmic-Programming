//https://codeforces.com/contest/911/problem/B

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
	
	scl(n) ; 
	scl(a) ; 
	scl(b) ; 
	ll arr[n] ;
	
	rep ( i , 1 , n , 1 )
	    arr[i] = min ( a/i , b/(n-i) ) ;
	
	ll mm = arr[1] ; 
	rep ( i , 2, n , 1 )
	{
	    mm = max ( arr[i] , mm ) ; 
	}
	cout<<mm ; 
	return 0;
}
















