//https://codeforces.com/contest/902/problem/A

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul;
typedef long long ll;

typedef pair<int, int> pii;

#define sc(x) scanf ("%llu",&x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(int i =a;i<b;i+=n)
#define f first 
#define s second
#define pb push_back
#define tc(t) ul t ; sc(t) ; while ( t-- )

int main() {
	
	ul n , m , a[110] , b[110] ; 
	
	sc(n) ; 
	sc(m) ; 
	
	rep (i , 0 , n , 1 )
	{
	    cin>>a[i];
	    cin>>b[i];
	}
	ul rx = n ;
	ul ry = m   ;

	while(1)
	{   
	    int flag = 0 ;
	    rep ( i , 0 , rx , 1)
	    {
	        if ( b[i] >= ry )
	        {   
	            flag = 1 ; 
	            ry = a[i] ;
	            rx = i ;
	            if ( a[i] == 0 )
	            { 
	                cout<<"YES";
	                return 0 ;
	            }
	            break ;
	        }
	    }
	    if ( flag == 0)
	    {
	        cout<<"NO" ;
	        return 0 ; 
	    }
	}
	
	return 0;
}
