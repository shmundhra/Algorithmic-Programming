// https://www.codechef.com/problems/CHEFEXQ

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
 
#define sc(x) scanf ("%llu",&x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(i=a;i<b;i+=n)
 
typedef unsigned long long ul  ;
using namespace std;
 
int main() 
{
  ul i , j ,  n , q , arr[100010] , b[100010] ; 
  ul c[350] = {0} ;
  int a[350][1050000] = { {0} };
  ul t , p , r , calc , prev , x ; 
  
  sc(n) ; sc(q) ;
  
  rep ( i , 0 , n  , 1) 
  {
      sc(arr[i]);
  }
  
  ul rt = (int) sqrt(n) ;
  rep ( i , 0 , rt+1 , 1)
  {
      x = 0 ;
      rep ( j , i*rt , min ( (i+1)*rt , n ) , 1 )
      {
          x ^= arr[j]  ;
          a[i][x] ++ ;
          b[j] = x ; 
      }
      c[i] = x ; 
  }
  
  
  while(q--)
  {
      sc(t) ; 
      sc(p) ;
      sc(r) ;
      p-- ; 
      switch ( t )
      {
          case 1  : arr[p] = r ;
                    i = p/rt ; 
                    
                    if ( p%rt ) 
                        x = b[p-1] ;
                    else
                        x = 0 ;
                        
                    rep ( j , p , min ( (i+1)*rt , n ) , 1 )
                    {
                        a[i][ b[j] ] -- ; 
                        x ^= arr[j]  ;
                        a[i][x] ++ ;
                        b[j] = x ; 
                    }
                    c[i] = x ;
                    
                  
                        
                    break;
                    
          case 2  : calc = 0 ;
                    prev = 0 ;
                    j = p/rt ; 
                    
                    rep ( i , 0 , j , 1 )
                    {
                        calc += a[i][r ^ prev];
                        prev ^= c[i] ; 
                    }
                    
                    rep ( i , j*rt , p+1 , 1)
                    {   
                        
                        if ( ( prev^b[i] ) == r)
                            calc++ ;
                    }
                    cout<<calc<<endl;
                    break ;
                
          default : break ;  
      }
      
  }
 
  return 0 ;
}  