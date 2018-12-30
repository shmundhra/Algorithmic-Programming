//https://codeforces.com/contest/914/problem/C

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

#define MOD 1000000007 
#define vec vector 
#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) ll arr[n+10] = {0} ; lp ( i , n) cin>>arr[i] 
#define fast ios::sync_with_stdio(false); cin.tie(0);
/*
ul modexp ( ll base , ll expo , ll modulo = MOD )
{
    base = base % modulo ;
    ul ans = 1 ;
    while ( expo )
    {
        if ( expo&1 )
            ans = (ans * base) % modulo ;

        expo >>= 1 ;
        base = (base*base)% modulo  ;

    }
    return ans ;
}

ul ncr ( ll n , ll r )
{   
    if ( r > n ) return 0 ; 
    
    if ( r == 0 ) return 1 ; 
    
    ll a = 1 ; 
    ll b = 1 ; 
    
    rep ( i , 2 , n+1 , 1 ) 
        a = ( a*i ) % MOD ; 
     
    
    rep ( i , 2 , r+1 , 1 ) 
        b = ( b*i ) % MOD ; 
    
    
    rep ( i , 2 , n-r+1 , 1 ) 
        b = ( b*i ) % MOD ; 
    
    ul val1 = modexp ( b , MOD-2 ) ; 
    ul ans = ( (a % MOD) * (val1 % MOD) ) % MOD ; 
    
    return ans ; 
}
*/


int main() {
	 
	fast  
	
	ll ncrt [1001][1001] ; 
	
	lp ( i , 1001 )
	    ncrt[i][0] = 1 ; 
	   
	lp ( i , 1001 ) 
	    ncrt[i][i] = 1 ; 
	
	lp ( i , 1001 )
	    rep ( j , 1 , i , 1 )
	        ncrt[i][j] = ( ncrt[i-1][j] + ncrt[i-1][j-1] ) % MOD ; 
	
	ll val[1010] ; 
	val[1] = 0 ;  
	val[2] = 1 ; 
	  
	rep ( i , 3 , 1001 , 1)
	{   
	    ll count = 0 ; 
	    for ( ll j = i ; j > 0 ; j/=2 )    
	    {
	        if ( j%2 ) count++ ; 
	    }  
	    val[i] = 1 + val[count] ; 
	}
	
	string s ; cin>>s ;
	ll k ;  cin>>k ; 
	
	if ( k == 0 )
	{
	    cout<<1 ; 
	    return 0 ; 
	}
	
	if ( k == 1 )
	{
	    cout<<s.size() - 1 ; 
	    return 0 ; 
	}
	
	ll num1 = 0 ; 
	lp ( i , s.size() )
	{
	    if ( s[i] == '1' ) num1++ ; 
	}
	 
	ul as = 0 ; 
	rep ( i , 1 , s.size()+1 , 1 )
	{
	    if ( val[i] == (k-1) )
	    {
	        ll num = i ;  
	        lp ( j , s.size() )
	        {  
	            if ( s[j] == '1' )
	            {
	                as += ncrt [(ll)(s.size()-1-j)][num] ;
	                as = as % MOD ; 
	                
	                if ( num == 0 )
	                    break ;
	                    
	                num-- ;      
	            }
	        }
	        if ( num1 == i ) 
	            as = (as + 1 ) % MOD ; 
	             
	    }    
	   
	}
	
	cout<<as<<endl ; 
	return 0 ; 
}









