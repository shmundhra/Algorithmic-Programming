// https://www.codechef.com/DEC17problems/CHEFUNI

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
 
#define sc(x) scanf("%ul",&x)  
#define pr(x) printf("%ul",x)  
#define rep(i , a , b , n) for(i=a;i<b;i+=n)

typedef unsigned long long ul  ;
using namespace std;
 
int main() 
{
    ul t , x , y , z , A , b, c ; 
    ul p  , q , r ; 
    int i , j , k ; 
    
    ul a[102][102][102] ; 
    
    rep ( i , 0 , 102 , 1 )
    {
        rep ( j , 0 , 102 , 1 )
        {
            a[0][i][j] = 1000000 ;
            a[i][0][j] = 1000000 ; 
            a[i][j][0] = 1000000 ; 
        }    
    }
    
    
    cin>>t ; 
    while(t--)
    {
        cin>>x>>y>>z>>A>>b>>c ;
        a[0][0][0] = -c ; 
        
        rep ( i , 1 , x+2 , 1 )
        {
            rep ( j , 1 , y+2 , 1 )
            {
                rep ( k , 1 , z+2 , 1 )
                {
                     p = A + min ( min ( a[i-1][ j ][ k ] , a[ i ][j-1][ k ] ) , a[ i ][ j ][k-1]   ) ;    
                     q = b + min ( min ( a[i-1][j-1][ k ] , a[i-1][ j ][k-1] ) , a[ i ][j-1][k-1]   ) ;
                     r = c + a[i-1][j-1][k-1] ; 
                     a[i][j][k] = min ( min ( p , q) , r ) ; 
                }
            }
        }
        cout<<a[x+1][y+1][z+1]<<endl;
        
    }
    
    return 0 ; 
    
}













