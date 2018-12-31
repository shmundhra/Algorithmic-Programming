// https://www.codechef.com/problems/CHEFGP

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
	     string s ; cin>>s; 
	     scl(x) ; scl(y) ; 
	     ll na = 0 ;ll nb = 0 ; 
	     
	     rep ( i , 0 , s.size() , 1 ) 
	     {
	         if ( s[i] == 'a') na++ ; else   nb++ ; 
	     }
	     
	     ll ba = ( na + x - 1) / x ; 
	     ll bb = ( nb + y - 1) / y ;
	     
	     vector < pair < char , ll > > a ; 
	     ll i , j ; 
	     
	     if ( ba >= bb )
	     {
	         for ( i = na , j = nb ; i>0 && j>0 ; i-=x , j-- )
	         {
	                a.pb( mp ('a' , min ( x , i) ) ) ; 
	                a.pb( mp ('b' , 1 ) ) ; 
	         }
	         
	         if ( i > 0 && j <= 0 )
	         {   
	             a.pb( mp ('a' , min ( x , i) ) ) ; 
	             i-=x ;
	             
	             while( i > 0)
	             {      
	                  a.pb( mp ('*' , 1 ) ) ;
	                  a.pb( mp ('a' , min ( x , i) ) ) ; 
	                  i-=x ; 
	             }
	         }
	         
	         if ( i <=0 && j > 0 )
	         {
	             for ( ll k = 1 ; j > 0  ; k+=2 )
	             {
	                 a[k].s += min ( (y-1) , j )  ; 
	                 j -= ( y-1 ) ; 
	             }
	         }
	     }
	     
	     else
	     {
	         for ( i = nb , j = na ; i>0 && j>0 ; i-=y , j-- )
	         {
	                a.pb( mp ('b' , min ( y , i) ) ) ; 
	                a.pb( mp ('a' , 1 ) ) ; 
	         }
	         
	         if ( i > 0 && j <= 0 )
	         {   
	             a.pb( mp ('b' , min ( y , i) ) ) ; 
	             i-=y ;
	             while( i > 0)
	             {
	                  a.pb( mp ('*' , 1 ) ) ;
	                  a.pb( mp ('b' , min ( y , i) ) ) ; 
	                  i-=y ;
	             }
	         }
	         
	         if ( i <=0 && j > 0 )
	         {
	             for ( ll k = 1 ; j > 0  ; k+=2 )
	             {
	                 a[k].s += min ( (x-1) , j )  ; 
	                 j -= ( x-1 ) ; 
	             }
	         }
	         
	     }
	     
	     rep( k , 0 , a.size() , 1 )
	         rep ( l , 0 , a[k].s , 1 )
	            cout<<a[k].f ; 
	     
	     cout<<endl;
	     
	 }
	 
	return 0;
}



















