// https://www.codechef.com//JAN18/problems/XYHUMOQ

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

ll Min , X , binnum ; 

ll hum ( ll num )  // number of humongous queries
{       
        string s ; 
    
        while ( num>0 )
        {
           s.pb( '0' + num%2 ) ;
           num /=2 ;  
        }
        reverse ( s.begin() , s.end() ) ;  
        
        ll n = s.size() ; 
        
        ll ans1 = 1 ; ll ans0 = 0 ; 
        
        rep ( i , 1 , n , 1 )
        {
            if ( s[i]=='1')
                ans1 = 1 + ans1 + ans0 ; 
            else
                ans0 = ans1 + ans0 ; 
        }
        return ans0 ; 
}

ll hd ( ll num )   // hamming distance or number of flips 
{
    ll val = (num^binnum) ;
    ll count = 0 ; 
    while ( val > 0 )
    {
        count += (val%2) ; 
        val/=2 ; 
    }
    return count ; 
}


int f ( ll num , ll n , ll i )
{   
    if ( i >= (n-1) )
    {   
        if ( hum(num) == X )
        {
            Min = min ( Min , hd(num) ) ; 
        }
        return 0 ; 
    }
    
    f (      num         , n , i+1 ) ; 
    f ( ( num ^ (1<<i) ) , n , i+1 ) ; 
    
    return 0 ; 
}


int main() {
 
    tc(t)
    {   
        Min = 100 ; 
        
        string s ; cin>>s ; 
        cin>>X ; 
        
        ll n = s.size() ; 
        
        ll num = 0 ; 
        for ( int i = n-1 ; i >=0 ; i-- )
        {
            num += (s[i]-'0')<<(n-1-i) ; 
        }
        binnum =  num ;
        
        f ( binnum , n , 1 ) ; 
        
        if ( Min <= n )
        {
            cout<<"YES\n"<<Min<<endl;
        }
        else
            cout<<"NO\n" ; 
            
    }
    
 	return 0;
}











