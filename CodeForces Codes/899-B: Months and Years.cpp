//https://codeforces.com/contest/899/problem/B

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

int x[] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31 } ; 
int y[] = {31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31 } ; 

int main() {
	
	ul i , j , n , a[24] , b ; 
	int flag ; 
	sc(n) ; 
	b = 0 ; 
	rep ( i , 0 , n , 1 )
	{
	    cin>>a[i];
	    if ( a[i] == 29 ) b = 1 ; 
	    
	}
	
	switch ( b )
	{
	    case 0 : rep ( i , 0 , 24 , 1 )
	             {
	                 flag = 0 ;
	                 rep ( j , 0 , n , 1)
	                 {
	                     if ( x[(i+j)%24] != a[j] )
	                     {     
	                         flag = 1 ;
	                         break ; 
	                     }
	                 }
	                 if ( flag == 0 )
	                 {
	                     cout<<"YES" ;
	                     return 0 ;
	                 }
	             }
	             cout<<"NO";
	             return 0 ;
	    
	     case 1 : rep ( i , 0 , 24 , 1 )
	             {
	                 flag = 0 ;
	                 rep ( j , 0 , n , 1)
	                 {
	                     if ( y[(i+j)%24] != a[j] )
	                     {     
	                         flag = 1 ;
	                         break ; 
	                     }
	                 }
	                 if ( flag == 0 )
	                 {
	                     cout<<"YES" ;
	                     return 0 ;
	                 }
	             }
	             cout<<"NO";
	             return 0 ;         
	}
}
