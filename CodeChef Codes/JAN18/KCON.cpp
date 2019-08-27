// https://www.codechef.com/JAN18problems/KCON

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
	     scl(k) ; 
	     inarr(n) ; 
	     
	     if ( k == 1 )
	     {
	         
	         ll suff_sum = -1E7 ; ll maxsum = -1E7 ; 
	        
	         lp (i , n)     
	         {
	            suff_sum = max ( (suff_sum + arr[i]) , arr[i]  ) ; 
	            maxsum = max ( maxsum , suff_sum ) ; 
	         }
	         cout<<maxsum<<endl ;
	         
	         continue ; 
	     }
	     
	     ll sum = 0 ; 
	     lp ( i , n ) sum += arr[i] ;
	        
	     if ( sum > 0 ) 
	     {
	         ll b[2*n+3] ; 
	         lp ( i , n ) b[i] = arr[i] ;
	         b[n] = sum*(k-2) ; 
	         lp ( i , n ) b[i+n+1] = arr[i] ;
	         
	         ll suff_sum = -1E7 ; ll maxsum = -1E7 ; 
	        
	         lp (i , 2*n+1 )     
	         {
	            suff_sum = max ( (suff_sum + b[i]) , b[i]  ) ; 
	            maxsum = max ( maxsum , suff_sum ) ; 
	         }
	         cout<<maxsum<<endl ;
	         
	     }
	        
	     else
	     {
	        ll b[2*n+3] ; 
	        lp ( i , 2*n ) b[i] = arr[i%n] ; 
	            
	        ll suff_sum = -1E7 ; ll maxsum = -1E7 ; 
	        
	        lp (i , 2*n )     
	        {
	            suff_sum = max ( (suff_sum + b[i]) , b[i]  ) ; 
	            maxsum = max ( maxsum , suff_sum ) ; 
	        }
	        cout<<maxsum<<endl ; 
	         
	     }   
	     
	 }
	return 0;
}













