//https://codeforces.com/contest/911/problem/A

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
#define tc(t) scu(t); while ( t-- )

int main() {
	
	scl(n) ; 
	ll a[n] ; 
	
	rep ( i , 0 , n , 1 )
	{
	    cin>>a[i] ; 
	}
	
	ll mini = a[0] ; 
	rep ( i , 1 , n , 1 )
	{
	    mini = min ( mini , a[i] ) ;  
	}
	//cout<<mini<<endl ; 
	
	ll pos[n] ; 
	
	ll c = 0 ; 
	rep ( i , 0 , n , 1 )
	{
	    if ( a[i] == mini )
	    {
	        pos[c++] = i ; 
	        //cout<<"#"<<i<<"#";
	    }
	    
	}
	mini = n+1 ; 
	rep ( i , 1 , c , 1 )
	{
	    mini = min ( mini , pos[i] - pos[i-1] ) ; 
	}
	cout<<mini ; 
	
	return 0;
}
















