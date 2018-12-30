//https://codeforces.com/contest/907/problem/B

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair<ll, ll>  pll ;
typedef pair< ll , pll > edge ; 
typedef vector < ll > uwg ;
typedef vector < pll > wg ;

#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; sc(t) ; while ( t-- )


int main() {
	
	char a[10][10] ; 
	string s ; 
	char c ; 
	rep ( i , 1 , 10 , 1)
	{
	    rep ( j , 1 , 10 , 1 )
	    {   
	        
 	        cin>>a[i][j] ; 
	    }
	    
	}
 
	scl(x) ; 
	scl(y) ; 
	ll cx , cy ;
	
	if ( x%3 == 1 ) cx = 1 ;
	else if ( x%3 == 2) cx = 2 ; 
	else cx = 3 ; 
	
	if ( y%3 == 1 ) cy = 1 ;
	else if ( y%3 == 2) cy = 2 ; 
	else cy= 3 ; 
	
	ll sx = ( cx-1)*3 + 1 ;
	ll sy = ( cy-1)*3 + 1 ; 
    ll flag =  0 ; 
	rep ( i , sx , sx+3 , 1 )
	{
	    rep ( j , sy , sy+3 , 1 )
	    {
	        if ( a[i][j] == '.') { a[i][j] = '!' ; flag ++ ; }
	    }
	}
	
	if ( flag == 0 )
	{
	    rep ( i , 1 , 10 , 1 )
	    {
	        rep ( j , 1, 10 , 1 )
	        {   
	            if ( j == 4 || j == 7) cout<<" " ; 
	            if ( a[i][j] =='.' ) cout<<"!" ; 
	            else cout<<a[i][j] ;
	        }
	        cout<<endl ; 
	        if ( i == 3 || i == 6 ) cout<<endl ; 
	    }
	}
	else
	{
	    rep ( i , 1 , 10 , 1 )
	    {
	        rep ( j , 1, 10 , 1 )
	        {   
	            if ( j == 4 || j == 7) cout<<" " ; 
	            cout<<a[i][j] ;
	        }
	        cout<<endl ;
	        if ( i == 3 || i == 6 ) cout<<endl ; 
	    }
	     
	}
	return 0;
}














