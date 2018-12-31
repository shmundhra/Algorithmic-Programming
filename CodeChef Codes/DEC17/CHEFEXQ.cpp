// https://www.codechef.com//DEC17/problems/CHEFEXQ

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
 
#define sc(x) scanf ("%lld",&x)  
#define pr(x) printf("%lld", x)  
#define rep(i , a , b , n) for(i=a;i<b;i+=n)

typedef unsigned long long ul  ;
using namespace std;
 
int main() 
{
  ul i , n , q , a[100010] , b[100010] ;
  ul t , p , r , c ; 
  
  sc(n) ; sc(q) ;
  
  rep ( i , 1 , n+1 , 1) 
  {
      sc(a[i]);
  }
  b[0] = 0    ;
  rep ( i , 1 , n+1 , 1)
  {
      b[i] = b[i-1]^a[i] ; 
  }
  
  while(q--)
  {
      sc(t) ; 
      sc(p) ;
      sc(r) ;
      
      switch ( t )
      {
          case 1  : a[p] = r ; 
                    rep( i , p , n+1 , 1)
                    {
                        b[i] = b[i-1]^a[i] ; 
                    }
                    break ;
                    
          case 2  : c = 0 ;
                    rep ( i , 1 , p+1 , 1 )
                    {
                        if ( b[i] == r)
                            c++ ; 
                    }
                    cout<<c<<endl;
                    break ;
                
          default : break ;  
      }
      
  }
 
  return 0 ;
}  
 
  