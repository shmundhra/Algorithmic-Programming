//https://codeforces.com/contest/910/problem/A

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
    
	scl(n) ; 
	scl(d) ;
	
	char s[1000] ; 
	rep ( i , 1 , n+1 , 1 )
	    cin>>s[i] ; 
	 
	ll flag ; 
	ll c = 1 ; 
	ll b = 1 ; 
	ll e = 1+d ;
	
	while(1)
	{   
	    flag = 0 ; 
	    for ( ll i = e ; i > b ; i-- )
	    {  
	        if ( s[i]=='1')
	        {   
	            flag = 1 ;
	            c++ ; 
	            b = i ; 
	            e = i + d ; 
	            break ; 
	        }
	    }
	    if (b == n) 
	            c-- ; 
	            
	    if ( e >= n) 
	    {
	            cout<<c;
	            return 0 ;
	    }
	    if ( flag == 0 )
	    {
	            cout<<-1 ;
	            return 0 ; 
	    }
	}
	
}





