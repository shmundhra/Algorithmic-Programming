// https://www.codechef.com//LTIME55/problems/NW1

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
	
    ll t; 
    cin>>t ; 
    while ( t-- )
    {
        int a[] = { 4 , 4 , 4 , 4 , 4 , 4 , 4 } ; 
        int st ; 
        string s ; 
        ll d ; 
        cin>>d;
        cin>>s ; 
        
        if ( s.compare("mon") == 0 ) st = 0 ; 
        if ( s.compare("tues") == 0 ) st = 1 ; 
        if ( s.compare("wed") == 0 ) st = 2 ; 
        if ( s.compare("thurs") == 0 ) st = 3 ; 
        if ( s.compare("fri") == 0 ) st = 4 ; 
        if ( s.compare("sat") == 0 ) st = 5 ; 
        if ( s.compare("sun") == 0 ) st = 6 ; 
        
        rep ( i , 0 , d-28 , 1)
        {
            a[(st+i)%7]++ ; 
        }
        
        rep ( i , 0 , 7,  1 )
        {
            cout<<a[i]<<" " ;
        }
        cout<<endl ; 
        
    }
    
	return 0;
}
















