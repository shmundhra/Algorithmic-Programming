// https://www.codechef.com/problems/MINSUBAR

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


int main()
{   
    ll t ; 
    cin>>t ; 
    while ( t-- )
    {   
        ll a[100000] = {0} ; 
        ll b[100000] = {0} ; 
        ll max_ind[100000] = {0} ; 
        ll n , d ; 
        cin>>n>>d;
        rep ( i , 1 , n+1 , 1 )
              cin>>a[i] ; 
                 
        rep ( i , 1, n+1 , 1 )
              b[i] = b[i-1] + a[i] ; 
               
        wg v2(n+2) ; 
        v2[0] = mp(0,0) ;
        ll pos = 1 ;
        
        ll index ; 
        ll len = n+2; 
        ll val ; 
        
        rep ( i , 1 , n+1 , 1 )
        {   
            val = b[i] - d ; 
           
            ll beg = 0 ; ll end = pos-1 ; 
            ll mid = beg + ( end-beg ) / 2 ; 
           
            while ( beg <= end)
            {
               if ( v2[mid].f <= val )
               {
                   beg = mid + 1 ;
                   mid = beg + ( end-beg ) / 2 ;
               }
               else
               {
                   end = mid - 1 ; 
                   mid = beg + ( end-beg ) / 2 ;
               }
            }
            index = end ; 
            
            if ( index != -1  )            
                len = min ( len , ( i - v2[index].s ) ) ; 
                        
            while ( v2[pos-1].f >= b[i] && pos > 0 )
            {
                pos -- ; 
            }
            v2[pos] = mp ( b[i] , i ) ; 
            pos++ ; 
            
        }              
        
        if ( len > n )
            cout<<-1<<endl ; 
        else
            cout<<len<<endl ;
        
    }    
    return 0 ; 
}