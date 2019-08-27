// https://www.codechef.com/JAN18problems/PRTITION

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
	 
	 tc(t)
	 {
	     
	scl(x) ;
    scl(n) ;

    if ( ( n*(n+1)/2 - x ) % 2 || n < 4)
    {
        cout<<"impossible"<<endl ;
        continue ;
    }

    ll arr[n+2] ;

    lp ( i , n+1)
    {
        arr[i] = 1 ;
    }
    arr[x] = 2 ;

    vector < ll > v ;

    rep ( i , 1 , n+1 , 1 )
    {
        if ( i == x) continue ;
        v.pb(i) ;
    }

    ll len = v.size() ;
    ll lsum = 0 ;

    switch ( len%4 )
    {
        case 0 : rep( i , 0 , 0 + (len-0)/2-1 , 2 )
                 {
                    lsum += v[i] + v[len-1-i] ;

                    arr[ v[i] ] = 0 ;
                    arr[ v[len-1-i] ] = 0 ;
                 }
                 break ;

        case 1 : lsum += ( v[0] + v[1] ) ;
                 arr[ v[0] ] = 0 ;
                 arr[ v[1] ] = 0 ; 
                 rep ( i , +3 , 3 + (len-3)/2 - 1 , 2 )
                 {
                    lsum += v[i] + v[len+2-i] ;

                    arr[ v[i] ] = 0 ;
                    arr[ v[len+2-i] ] = 0 ;
                 }
                 lsum+= v[3 + (len-3)/2 - 1] ;
                 arr[ v[3 + (len-3)/2 - 1 ] ] = 0 ;

                 break ;

        case 2 : rep ( i , 0 , 0 + (len-0)/2-1 , 2 )
                 {
                    lsum += v[i] + v[len-1-i] ;

                    arr[ v[i] ] = 0 ;
                    arr[ v[len-1-i] ] = 0 ;
                 }
                 lsum+= v[len/2 - 1] ;
                 arr[ v[len/2 - 1] ] = 0 ;

                 break ;

        case 3 : lsum += ( v[0] + v[1] ) ;
                 arr[ v[0] ] = 0 ;
                 arr[ v[1] ] = 0 ; 
                 rep ( i , 3 , 3 + (len-3)/2 - 1 , 2 )
                 {
                    lsum += v[i] + v[len+2-i] ;

                    arr[ v[i] ] = 0 ;
                    arr[ v[len+2-i] ] = 0 ;
                 }
                 break ;

        default: break ;
    }

    ll rsum = n*(n+1)/2 - x - lsum ;

    if ( lsum > rsum )
    {
        rep ( i , 1 , n , 1)
        {
            if ( arr[i] == 1 && arr[i+1] == 0)
            {
                arr[i+1] = 1 ; 
                arr[i] = 0 ; 
                break ; 
            }
        }
    }
    else if ( rsum > lsum )
    {
        rep ( i , 1 , n , 1)
        {
            if ( arr[i] == 0 && arr[i+1] == 1)
            {
                arr[i+1] = 0 ; 
                arr[i] = 1 ; 
                break ; 
            }
        }
    }
	 
	rep ( i , 1 , n+1 , 1)
	    cout<<arr[i] ; 
	cout<<endl ;
	     
	 }
	return 0;
}









