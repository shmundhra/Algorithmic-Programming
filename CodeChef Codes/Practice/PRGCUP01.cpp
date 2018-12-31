// https://www.codechef.com/problems/PRGCUP01

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

#define row(x) (x)/8 
#define col(x) (x)%8 
#define val(a,b) 8*(a)+(b) 

int arr[8][8] ;
                                                     
int x[] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2 } ; int y[] = {  1 ,  2 , 2 , 1 ,-1 ,-2 , -2 , -1 } ;

int main() {
    
	ul t ;
	int flag , i , j , p , r , a ; 
	string si , sf ;
	sc(t) ;
	int sx , sy , ex , ey ;
	
	while (t--)
	{   
	    queue <int> q ;
	    for ( int u = 0 ; u < 8 ; u++ )
            for ( int v= 0 ; v < 8 ; v++ )
                    arr[u][v] = -1 ;
            
	    cin>>si>>sf;
	    sx = si[0] - 'a' ; 	    sy = si[1] - '1' ; 
	    ex = sf[0] - 'a' ; 	    ey = sf[1] - '1' ; 
	    
	    arr[sx][sy] = 0 ; 
	    if ( sx == ex && sy == ey ) 
	    {  
	        cout<<0<<endl;
	        break ;
	    }
	    
	    flag = 0 ; 
	    q.push( val(sx,sy) ) ;
	    while ( ! q.empty() )
	    {
	        i = row ( q.front() ) ;
	        j = col ( q.front() ) ;
	        q.pop() ; 
	        
	        rep ( a , 0 , 8 , 1 )
	        {   
	            p = i + x[a] ; 
	            r = j + y[a] ;
	            if ( p < 0 || p > 7 || r < 0 || r > 7 )
	                continue;
	            if ( arr[p][r] == -1 )
	            {
	                arr[p][r] = arr[i][j] + 1 ;
	                                             
	                if ( p == ex && r == ey )
	                {  
	                    cout<<arr[p][r]<<endl ;
	                    flag = 1 ; 
	                    break ;
	                }
	                                              
	                q.push( val ( p , r) ) ; 
	            }
	        }
	        if ( flag == 1 )
	        break ; 
	    }
	}
	return 0;
}
