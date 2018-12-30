//https://codeforces.com/contest/914/problem/A

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

#define MOD 1000000007 
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
#define fast ios::sync_with_stdio(false); cin.tie(0);


int main() {
	 
	 fast 
	 
	 int a[1000006] = {0} ; 
	 
	 lp ( i , 1001 )
	    a[i*i] = 1 ; 
	  
	 
	ll n ; 
	cin>>n ; 
	ll arr[n+10] ; 
	lp ( i , n )
	    cin>>arr[i] ; 
	 
	 sort ( arr , arr+n) ; 
	 
	 for ( ll i = n-1 ; i >= 0 ; i-- )
	 {
	     if ( arr[i] <  0 )
	     {
	        cout<<arr[i] ; 
	        return 0 ;
	     }
	        
	     if ( a[ arr[i] ] == 0 )
	     {      
	            cout<<arr[i] ; 
	            return 0 ; 
	     }
	 }
}









