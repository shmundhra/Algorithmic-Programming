//https://codeforces.com/contest/899/problem/C

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



int main() {
    
    int a[60001] ; 
    ul i , j , n ;
    rep ( i , 1 , 60001 , 1)
        a[i] = i ;
    
    sc(n);
    
    switch ( n )
    {
        case 3 : cout<<0<<endl;
                 cout<<1<<" "<<3;
                 return 0 ;
    }
    
    if ( n % 4 == 0 )
    {
        cout<<0<<endl;
        cout<<n/2;
        rep ( i , 1 , n/2 , 2 )
        {
            cout<<" "<<a[i]<<" "<<a[n+1-i];
        }
        return 0 ; 
    }
    
    if ( n % 4 == 2)
    {
        cout<<1<<endl;
        cout<<n/2;
        rep ( i , 1 , n/2 , 2 )
        {
            cout<<" "<<a[i]<<" "<<a[n+1-i];
        }
        cout<<" "<<a[n/2] ; 
        return 0 ; 
    }
    
    if ( (n-3) % 4 == 0 )
    {
        cout<<0<<endl;
        cout<<(n-3)/2 + 1<<" "<<3 ;
        rep ( i , 4 , 3 + (n-3)/2 , 2 )
        {
            cout<<" "<<a[i]<<" "<<a[n+4-i];
        }
        return 0 ; 
    }
    
    if ( (n-3) % 4 == 2)
    {
        cout<<1<<endl;
        cout<<(n-3)/2 + 1<<" "<<3 ;
        rep ( i , 4 , 3 + (n-3)/2 , 2 )
        {
            cout<<" "<<a[i]<<" "<<a[n+4-i];
        }
        cout<<" "<<a[3 + (n-3)/2] ;
        return 0 ; 
    }
    
}
