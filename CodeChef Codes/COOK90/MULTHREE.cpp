// https://www.codechef.com//COOK90/problems/MULTHREE

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

int main() {
	 
    fast
        
    ll t ; 
    cin>>t ; 
    while ( t--  )
    {
        ll k , a , b ; 
        
        cin>>k>>a>>b ; 
        ll c = a + b ;
        
        if ( k == 2 )
        {
            if ( c % 3 == 0 )cout<<"YES" ; 
            else cout<<"NO" ;
            cout<<endl ; 
            continue ; 
        }
        
        ll sum = c + c%10 ;
        
        if ( k == 3 )
        {
            if ( sum % 3 == 0)cout<<"YES" ; 
            else cout<<"NO" ;
            cout<<endl ; 
            continue ; 
        }
                
        ll num = k - 3 ; 
        
        ll arr[4] ; 
        arr[0] = (2 * (c%10)) % 10 ; 
        arr[1] = (4 * (c%10)) % 10 ; 
        arr[2] = (8 * (c%10)) % 10 ; 
        arr[3] = (6 * (c%10)) % 10 ; 
        
        sum += ( num/4 ) * ( arr[0] + arr[1] + arr[2] + arr[3] ) ; 
        
        lp ( i , num%4 )
        {
            sum += arr[i] ; 
        }
        
        if ( sum  % 3 == 0 ) cout<<"YES" ; 
        else cout<<"NO" ; 
        
        cout<<endl ;            
        
    }
	 
	 
	return 0;
}















