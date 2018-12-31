// https://www.codechef.com/problems/PERFCONT

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
        scl(p) ; 
        inarr(n) ;
        
        ll cw = 0 ; 
        ll hp = 0 ;
        
        lp ( i , n )
        {
            if ( arr[i] >= p/2 )
                cw ++ ; 
                
            if ( arr[i] <= p/10 )
                hp++ ;
        }
        
        if ( cw == 1 && hp == 2)
            cout<<"yes" ;
        else
            cout<<"no" ; 
            
        cout<<endl ; 
        
    }
	return 0;
}



















