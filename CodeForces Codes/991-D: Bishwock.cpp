//https://codeforces.com/contest/991/problem/D

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

int main () 
{
	fast 
    string a , b ; 
    cin>>a ; 
    cin>>b ; 
    
    int count = 0 ; 
    int i = 0 ; 
    
    for ( ; i < (int)a.size()-2 ; )
    {
        if ( a[i] =='X' and b[i] == 'X' )
        {
            i++ ; 
            continue ; 
        }
        
        if ( a[i] == 'X' or b[i] =='X' )
        {
            if ( a[i+1]=='X' or b[i+1] == 'X')
            {
                i+=1 ; 
                continue ; 
            }
            else
            {
                count++ ; 
                i+=2 ; 
                continue ; 
            }    
            
        }



        
        if ( a[i+1]=='X' and b[i+1] == 'X')
        {
            i+=2 ; 
            continue ; 
        }
        if ( a[i+1] == 'X' or b[i+1] =='X')
        {
            count++ ; 
            i+=2 ; 
            continue ; 
        }



        
        if ( a[i+2] =='X' or b[i+2] =='X')
        {
            i+=2 ; 
            count++ ; 
            continue ; 
        }
        
        i+=3 ; 
        count+=2 ; 
        
    }
    
    int c = 0 ; 
    if ( i == a.size()-2 )
    {
        if ( a[i] =='X') c++ ; 
        if ( b[i] =='X') c++ ; 
        if ( a[i+1] =='X') c++ ; 
        if ( b[i+1] =='X') c++ ;
        
        if ( c < 2 ) count++ ; 
    }
    
    cout<<count<<endl;

	return 0 ; 
}


















