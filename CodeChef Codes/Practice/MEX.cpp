// https://www.codechef.com/problems/MEX

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
#define inarr(n) ll arr[n+10] = {0} ; lp ( i , n) cin>>arr[i] 

int main() {
    
    tc(t)
    {
        scl(n) ; 
        scl(k) ; 
        inarr(n) ;
        
        int hash[200099] = {0} ; 
        
        lp ( i , n )
        {
            hash[arr[i]] = 1 ;   
        }
        ll count = 0 ; 
        lp ( i , 200099)
        {
            if ( hash[i] == 0 )
                count++ ; 
                
            if ( count > k)
            {
                cout<<i<<endl;
                break ; 
            }
        }
        
    }
	return 0;
}



















