//https://codeforces.com/contest/910/problem/C

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
	vector < string > vec ; 
	string s ; 
	ll mark[11]  = {0} ; 
	ll final[11] = {0} ;
	ll val[11]   = {0} ; 
	
	rep ( i , 0 , n , 1 )
	{
	    cin>>s ;
	    vec.pb(s) ; 
	    mark[ vec[i][0]-'a'] = 1 ; 
	    reverse( vec[i].begin() , vec[i].end() ) ; 
	}
	
	rep ( i , 0 , n , 1 )
	{
	    rep ( j , 0 , vec[i].size() , 1 ) 
	    {
	        val[ vec[i][j] - 'a' ] += (int) pow(10,j) ; 
	    }
	        
	}
	
	ll max = -1 ; 
	int maxpos = -1  ; 
	rep ( i , 0 , 10 , 1 )
	{
	    if ( mark[i] == 1) continue ; 
	    
	    if ( max < val[i] )
	   {
	       max = val[i] ; 
	       maxpos = i ; 
	   }
	}
	final[maxpos] = 0 ; 
	val[maxpos] = 1E15 ; 
	
	wg arr ; 
	
	rep ( i , 0 , 10 , 1 )
	{
	    arr.pb( mp( val[i] , i ) ) ;  
	}
	sort( arr.begin() , arr.end() , greater<pll>() ) ; 
	
	rep ( i , 1 , 10 , 1 )
	{
	    final[arr[i].s] = i ;     
	}
	
	ll sum = 0 ; 
	rep ( i , 0 , 10 , 1 )
	{
	    sum += val[i]*final[i] ; 
	}
	cout<<sum ; 
	
	return 0;
}











