//https://codeforces.com/contest/991/problem/C

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
#define scu(x) ul x ; cin>>x ; 
#define scl(x) ll x ; cin>>x ;  
#define pr(x) cout<<x ;   
#define all(v) ( v.begin() , v.end() ) 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) uwg v ( n , 0 ) ; lp ( i , n) cin>>v[i]  
#define fast ios::sync_with_stdio(false); cin.tie(0);

ul n ; 

bool check ( ul k )
{
    ul f = 0 ;
    ul s = 0 ; 
    ul total = n ; 
    
    while ( total > k and total > 9 )
    {
        f += k ; 
        total-=k ;
        total = total - total/10 ; 
    }
    f += total ;
    
    if ( f >= (n+1)/2 ) return true ; 
    else return false ; 
}



int main () 
{   
    cin>>n ; 
    
    ul low = 1 ; 
    ul high = n ; 
    
    while ( low < high )
    {
        ul mid = low + ( high - low ) / 2 ; 
        
        if ( check(mid) ) 
        {
            high = mid ; 
        }
        else
        {
            low = mid+1 ; 
        }
    }
	cout<< low <<endl ; 
	
	return 0 ; 
}


















