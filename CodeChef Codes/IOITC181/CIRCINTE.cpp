// https://www.codechef.com/IOITC181problems/CIRCINTE

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair<ll, ll >  pll ;
typedef pair< ll , pll  > edge ; 
typedef vector < ll  > uwg ;
typedef vector < pll  > wg ;

#define MOD 1000000007 
#define vec vector 
#define scu(x) ul x ; cin>>x ; 
#define scl(x) ll x ; cin>>x;  
#define pr(x) cout<<x ;   
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) ll arr[n+10] = {0} ; lp ( i , n) cin>>arr[i] 
#define fast ios::sync_with_stdio(false); cin.tie(0);

ul M ;
int N ; 
vector < pair < ul , ul > > v ;
ul low , high , mid ;
ul startP_L , startP_H , startP_M ; 


int check  ( ul startP , ul minD )
{
    ul currP = startP  ; 
    
    //cout<<minD<<"-> " ; 
    
    for ( int i = 1 ; i < N ; i++ )
    {   
        //cout<<currP<<" " ; 
        if ( currP + minD <= v[i].f )
        {
            currP = v[i].f ; 
        }
        else
        {
            if ( currP + minD > v[i].s )
                return 1 ; 
            else
                currP += minD ; 
        }
    }
     
    
    ul dist = M - currP + startP ; 
    
    if ( dist >= minD ) return 0 ; 
    
    else return -1 ; 
}

bool search ( ul minD  )
{
    startP_L = v[0].f ; 
    startP_H = v[0].s ; 
    /*
    for ( int st = startP_L ; st <= startP_H ; st++  )
    {  
        if ( check ( st , minD ) == 0 ) return true ; 
    }
    return false ; */
    
    while ( startP_L <= startP_H )
    {   
        if ( startP_L < v[0].f or startP_H >v[0].s ) return false ; 
        
        startP_M = startP_L + (startP_H - startP_L ) /2 ;  
        
        int result = check( startP_M , minD ) ; 
        //cout<<endl ; 
        
        if ( result == 0 ) return true ; 
        if ( result == 1) 
        {
            startP_H = startP_M - 1 ; 
        }
        else
        {
            startP_L = startP_M + 1 ; 
        }
    }
    return false ; 
}

int main() {
	 
	fast 
	
	cin>>M>>N ;
	
	if ( N == 1 ) return M ; 
	
	ul x , y ; 
	lp ( i , N )
	{
	    cin>>x>>y ; 
	    v.pb( mp( x%M , y%M ) ) ; 
	}
	
	low = (ul)1  ; 
	high = M ;
	
	while ( low < high )
	{   
	    mid = low + (high - low + 1 )/2 ; 
	    
	    if ( search( mid ) )
	    {
	        low = mid ; 
	    }
	    else
	    {
	        high = mid-1 ; 
	    }
	}
	
	cout<<high<<endl ; 
	return 0;
}
