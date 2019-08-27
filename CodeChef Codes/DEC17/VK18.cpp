// https://www.codechef.com/DEC17problems/VK18

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define sc(x) scanf("%ul",&x)  ; 
#define pr(x) printf("%ul",x)  ;
typedef unsigned long long ul ;

#define rep(i,a,b,n) for(i = a ; i < b ; i += n ) ; 
using namespace std;

int main ()
{
    long int i , j , t , n ;
    cin>>t ;
    
    long int sum , dig ;
    long int d[2000001] , a[1000001]; 
    
    for ( i = 0 ; i < 2000001 ; i++)
    {
        sum = 0 ;
        for ( j = i ; j > 0 ; j/=10 )
        {
            dig = j % 10 ;
            if ( dig % 2 )
                sum -= dig ;
            else
                sum += dig ;         
        }
        if ( sum < 0 ) sum *= -1 ;
        d[i] = sum ; 
    }
    
    for ( i = 1 ; i < 2000001 ; i++)
    {
        d[i] += d[i-1] ; 
    }
    
    a[1] = 2 ;
    for ( i = 2 ; i < 1000001 ; i++)
    {
        a[i] = a[i-1] + d[2*i] + d[2*i-1] - 2*d[i] ; 
    }
    
    
    while ( t--)
    {
        cin>>n ; 
        cout<<a[n]<<endl;
    }
    
    return 0 ;
}
    
    
    