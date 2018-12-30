//https://codeforces.com/contest/899/problem/A

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
	
	ul t , c , n , a , b ; 
	a = 0 ;
	b = 0 ;
	sc(n) ; 
	rep ( t , 0 , n , 1 )
	{
	    cin>>c;
	    if ( c == 1 ) a++ ; 
	    else          b++ ;
	}
	
	if ( a <= b ) cout<<a<<endl;
	else cout<<b+(a-b)/3<<endl ; 
	return 0;
}
