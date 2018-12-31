// https://www.codechef.com//COOK90/problems/SURVIVE

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
	 
	 ll t , n , k  , s ; 
	 cin>>t ; 
	 
	 while(t--)
	 {
	     cin>>n>>k>>s ; 
	     
	     if ( k > n ) 
	     {
	         cout<<-1<<endl ; 
	         continue ; 
	     }
	     
	     if ( s>=7 && 7*k > 6*n )
	     {
	         cout<<-1<<endl ; 
	         continue ; 
	     }
	     
	      ll count = ( (s/7) *7*k + n-1) / n ; 
	      
	      ll val =  (s%7) * k - count * n + (s/7) *7*k ;  
	      
	      if ( val > 0 )
	      {
	          count += ( val + n - 1) / n ; 
	      }
	      cout<<count<<endl ; 
	 }
	 
	 
	 
	 
	 
	 
	return 0;
}









