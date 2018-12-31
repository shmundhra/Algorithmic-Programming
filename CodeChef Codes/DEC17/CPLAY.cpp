// https://www.codechef.com//DEC17/problems/CPLAY

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
#define rep(i,n) for(i=0;i<n;i++)
#define sc(x) scanf("%ul",&x)  ; 
#define pr(x) printf("%ul",x)  ;
#define ul unsigned long long int  ;
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
 
int main() {
    
int i , e , o ;
string A;
while(getline(cin, A))
{    e = 0 ;
     o = 0 ; 
  	 for ( i = 0 ; i < 9 ; i+=2)
	 {
	      if ( A[i] == '1') e++ ;
	      else o++ ; 
	            
	      if ( e > 5 ) 
	      {     cout<<"TEAM-A "<<i+1<<endl;
	            break ; 
	      }
	      else if ( o > 5)
	      {     cout<<"TEAM-B "<<i+1<<endl;
	            break ;
	      }
          
         
         
	      if ( A[i+1]=='0') e++ ;
	      else o++ ; 
	            
	      if ( e > 5 ) 
	      {      cout<<"TEAM-A "<<i+2<<endl;
	             break ; 
	      }
	      else if ( o > 5)
	      {     cout<<"TEAM-B "<<i+2<<endl;
	            break ;
	      }
          
	  
     }
      if ( i < 9)  continue ;
      
      for ( i = 10 ; i < 20 ; i+=2)
      {
          if ( A[i] - A[i+1] == 1 )
          {      cout<<"TEAM-A "<<i+2<<endl;
	             break ;
          }
          else if ( A[i] - A[i+1] == -1 )
          {      cout<<"TEAM-B "<<i+2<<endl;
	             break ;
          }            
      }
      if ( i==20) cout<<"TIE"<<endl ; 
      
}	   
 
	return 0;
}
 
 