// https://www.codechef.com//DEC17/problems/CHEFHAM

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
#define sc(x) scanf ("%lld",&x)  
#define pr(x) printf("%lld", x)  
#define rep(i , a , b , n) for( i = a ; i < b ; i += n )
typedef unsigned long long ul  ;

using namespace std;

int val ( int a , int b , int n )
{
   if ( a+b <= n)
        return a + b ; 
    else 
        return a + b - n ;
}

void swap ( ul *a , ul *b )
{
    *a = *a+*b ;
    *b = *a-*b ;
    *a = *a-*b ;
}

int main() 
{
    ul  i , j , t , n , a[100000] , b[100000] ; 
    
    sc(t) ; 
    while(t--)
    {
        sc(n);
        rep ( i , 1 , n+1 , 1)
        {
            sc( a[i] )  ;
            b[i] = a[i] ;
        }
        
        int flag = 0 ; 
        switch ( n )
        {
            case 1 : cout<<0<<endl;
                     cout<<a[1]<<endl;
                     flag = 1 ;
                     break ;
                
            case 2 : if ( a[1] == a[2] )
                     {  
                         cout<<0<<endl;
                         cout<<a[1]<<" "<<a[2]<<endl;
                         flag = 1 ; 
                     }
                     break ; 
            
            case 3 : if ( a[1] == a[2] || a[2] == a[3] ||  a[1] == a[3] )
                     {
                         cout<<2<<endl;
                         cout<<a[3]<<" "<<a[1]<<" "<<a[2]<<endl;
                         flag = 1 ; 
                     }
                     break ; 
                
            default : break ; 
        }
        
        if ( flag == 1 ) continue ; 
        
        for ( i = 1 , j = 2 ; i <= n ; )
        {
            if ( a[i] != a[j])
            {
                swap ( &b[i] , &b[j] ) ;
                i += 2;
                j = val(j,2,n);
            }
            else
            {
                swap ( &b[i] , &b[val(j,1,n)] ) ;
                swap ( &b[j] , &b[val(j,2,n)] ) ;
                i += 4;
                j = val(j,4,n);
            }
        }
        cout<<n<<endl;
        rep(i , 1 , n , 1)
        {
            cout<<b[i]<<" ";
        }
        cout<<b[n]<<endl;
        
    }
    
    return 0 ;   
}










