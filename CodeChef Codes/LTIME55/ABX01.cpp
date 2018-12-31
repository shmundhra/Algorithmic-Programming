// https://www.codechef.com//LTIME55/problems/ABX01

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

int sod ( ul a )
{
        ul sum = 0  ;
        ul val = a  ; 
        
        while ( (val/10) != 0)
        {   
            sum = 0 ; 
            for ( ul i = val ; i > 0 ; i/=10)
            {
                sum += i % 10 ; 
            }
            val = sum ;     
        }
    return val ; 
}


int main() {
	
    ll t; 
    cin>>t ; 
    while ( t-- )
    {   
        ul ans ; 
        ul a , n ; 
        cin>>a>>n ; 
        ul x = n ; 
        ul value ; 
        if ( n <= 3 )
        {
            value = ( ul )pow ( a , n ) ; 
            ans = sod ( value ) ; 
            cout<<ans<<endl ; 
            continue ; 
        }
               
        
        ul fa = sod ( a ) ; 
        ll rem = 1 ; 
        ul divi ;
        
        if ( n <= 100 )
        { 
            rep ( i , 0 , n , 1)
            {
                rem = rem * fa ; 
                rem = sod(rem) ; 
            }
            cout<<rem<<endl ; 
            continue ; 
        }
        
        
         
        for ( ul j = n ; j > 0 ; )
        {
            divi = j / 18 ; 
            for ( int i = 0 ; i < j%18 ; i++ )
            {
                rem*=fa ; 
                rem = sod(rem) ; 
            }
            fa = sod ( fa*fa*fa*fa*fa*fa * fa*fa*fa*fa*fa*fa * fa*fa*fa*fa*fa*fa ) ; 
            
            j = divi ; 
                        
        }
         ans = sod ( fa * rem ) ; 

        cout<<ans<<endl ; 
        
    }
    
	return 0;
}
















