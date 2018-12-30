//https://codeforces.com/contest/899/problem/D

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
 

#define sc(x) scanf ("%llu",&x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(i=a;i<b;i+=n)
#define f first 
#define s second

typedef unsigned long long ul  ;
using namespace std;

#define e(x) (ul) pow ( 10 , x ) 


int main() {

    ul n , p , i , j ;
    sc(n) ; 
    if ( n < 5 )
    {
        switch ( n )
        {
            case 2 : cout<<1 ; return 0 ;
            case 3 : cout<<3 ; return 0 ;
            case 4 : cout<<6 ; return 0 ;
        }
    }
    rep ( i , 1 , 9 , 1 )
    {
        if ( n < 5*e(i) )
            break ; 
    }
    p = i ; 
    ul val = 0 ;
    
    rep ( i , e(p)-1 , 2*n , e(p) )
    {
        val += min(n,i-1) - i/2 ;
    }
    
    cout<<val ; 
    return 0;
}
