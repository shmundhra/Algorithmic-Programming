//https://codeforces.com/contest/889/problem/E

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
	
	ll a[200009] ; 
	scl(n) ;
	
	a[0] = -1 ; 
	rep ( i , 1 , n+1 , 1 ) cin>>a[i] ; 
	a[n+1] = -2 ;
	
	set < pll > s1 ; set < pll > s2 ; 
	
	ll start = 1 ; 
	rep ( i , 2, n+1 , 1)
	{
	    if ( a[i] != a[i-1] )
	    {
	        s1.insert( mp ( start - i , start )) ; 
	        s2.insert( mp ( start , i - start )) ; 
	        start = i ; 
	    }
	}
	s1.insert( mp ( start - (n+1) , start )) ; 
	s2.insert( mp ( start , (n+1) - start )) ;
	
	s2.insert( mp ( 0   , -1 )) ;
	s2.insert( mp ( n+1 , -1 )) ;
	/*
    for ( auto it = s1.begin() ; it != s1.end() ; it++ ) 
            cout<<"("<<(*it).f<<" , "<<(*it).s<<")" ;
    cout<<endl ; 
    
    for ( auto it = s2.begin() ; it != s2.end() ; it++ ) 
        cout<<"("<<(*it).f<<" , "<<(*it).s<<")" ;
    cout<<endl ; 
    
    for ( auto it = s2.begin() ; it != s2.end() ; it++ ) 
        rep ( i , 0 , (*it).s  , 1 )
            cout<<a[(*it).f]<<" " ; 
    cout<<endl ;
    */
    
    set <pll> :: iterator it1 , it2 , it3 , it4; 
    pll p1 , p2 , p3 ,p4 ; 
    
    ll count = 0 ; 
    while ( !s1.empty() )
    {
        it1 = s1.begin() ; 
        s1.erase(it1) ; 
        count++ ; 
        
        p1 = *it1 ; 
        it2 = s2.find( mp (  p1.s , (-1)*p1.f ) ) ; 
        
        it3 = it2  ; it3-- ; 
        it4 = it2  ; it4++ ; 
        
        p3 = *it3 ; p4 = *it4 ;
        
        if ( a[ p3.f ] ==  a[ p4.f ] )
        {
           s1.erase ( mp ( (-1)*p3.s , p3.f ) ) ;  
           s1.erase ( mp ( (-1)*p4.s , p4.f ) ) ; 
           s1.insert( mp ( (-1)*( p3.s+p4.s ), p3.f ) ) ; 
           
           s2.erase( it3 , ++it4 ) ; 
           s2.insert( mp ( p3.f , p3.s + p4.s ) ) ; 
        }
        else
        {
            s2.erase(it2) ; 
        }
        /*
        for ( auto it = s1.begin() ; it != s1.end() ; it++ ) 
            cout<<"("<<(*it).f<<" , "<<(*it).s<<")" ;
        cout<<endl ; 
    
        for ( auto it = s2.begin() ; it != s2.end() ; it++ ) 
            cout<<"("<<(*it).f<<" , "<<(*it).s<<")" ;
        cout<<endl ;
        
        for ( auto it = s2.begin() ; it != s2.end() ; it++ ) 
            rep ( i , 0 ,  (*it).s  , 1 )
                cout<<a[(*it).f]<<" " ; 
        cout<<endl ;
    */
        
    }
    cout<<count<<endl  ; 
    return 0;
}