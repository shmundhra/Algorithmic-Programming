// https://www.codechef.com/COOK89problems/BTAR

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
        ul sum = 0 ; 
        ll a[4] = { 0 } ;  
        ll x ; 
        ll ans = 0 ;
        rep ( i , 0 , n , 1 )
        {
            cin>>x;
            
            sum+=x ; 
            
            a[ x % 4 ] ++ ; 
        }
        if ( sum % 4)
        {
            cout<<-1<<endl;
           
        }
        else 
        {
        ans = min ( a[1] , a[3] ) + a[2] / 2 ; 
        if ( a[2] % 2 )
        {
            ans += 2 + ( 3 * ( max ( a[1] , a[3]) - min (a[1] , a[3] ) - 2) ) / 4 ;  
        }
        else
        {
            ans += ( 3 * ( max ( a[1] , a[3]) - min (a[1] , a[3] ) ) ) / 4  ; 
        }
        cout<<ans<<endl ; 
        }
    }
    return 0 ; 
}











