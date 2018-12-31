// https://www.codechef.com//BITF2017/problems/BLKWID

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

int main () 
{   
    int n ; 
    cin>>n ;
     
    int a[n+2][n+2] ; 
    
    rep ( i , 1 , n+1 , 1 )
        rep ( j , 1 , n+1,  1 )
                cin>>a[i][j] ; 
     
    int temp ;
    int x = n/2 ; 
    int y = (n+1)/2 + 1 ; 
    rep ( i , 0 , n/2 , 1 )
    {
            rep ( j , 0 , n/2 , 1)
            {   
                temp = a[x-i][x-j] ; 
                a[x-i][x-j] = a[y+j][x-i] ;
                a[y+j][x-i] = a[y+i][y+j] ; 
                a[y+i][y+j] = a[x-j][y+i] ; 
                a[x-j][y+i] = temp ; 
            }
    }
    y-- ; 
    if ( n%2 )      
    {
       rep ( k , 0 , (n+1)/2 , 1 )
       {
                temp = a[y-k][y] ; 
                a[y-k][y] = a[y][y-k] ;
                a[y][y-k] = a[y+k][y] ; 
                a[y+k][y] = a[y][y+k] ; 
                a[y][y+k] = temp ; 
       }
    }
    
    rep ( i , 0 , n , 1 )
    {
        rep ( j , 0 , n , 1 )
        {
            printf("%2d " , a[i+1][j+1] ) ;  
        }
        cout<<endl ;
        
    }
    
    return 0 ; 
}

















