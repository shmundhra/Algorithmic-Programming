// https://www.codechef.com//COOK89/problems/FBMT

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


int main()
{   
    ll t ; 
    cin>>t ; 
    while ( t-- )
    {
        ll n ; 
        cin>>n ; 
        string s1 , s2 , s ;
        ll a , b ; 
        a = 0 ; b = 0 ; 
        if ( n != 0 )
        {
            
            cin>>s1 ;
            a++ ; 
            rep ( i , 1 , n , 1 )
            {
              cin>>s ; 
              if ( ! s1.compare(s) )
              {
                  a++ ; 
              } 
              else
              {
                  s2 = s  ; 
                   b++ ; 
              }
            }
        }
        if ( a > b ) cout<<s1 ; 
        else if ( a < b ) cout<<s2 ; 
        else cout<<"Draw" ; 
        cout<<endl ; 
        
        
    }
    return 0 ; 
}











