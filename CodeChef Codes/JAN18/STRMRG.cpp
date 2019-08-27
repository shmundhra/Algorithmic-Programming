// https://www.codechef.com/JAN18problems/STRMRG

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
typedef vector < pll > wg ;\
 
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
 
ll fa (  char , ll , ll ) ; 
ll fb (  char , ll , ll ) ; 
 
string a , b ; 
ll n , m ;
 
vec<vec<vec<ll>>> A ;
 
ll fa (  char ch , ll ai , ll bi )
{   
    if ( ai >= n) return 10000 ; 
    
    if ( A[0][ai][bi] == -1 )
         A[0][ai][bi] = fa (  'a' , ai+1 , bi ) ;       
    
    if ( A[1][ai][bi] == -1 )
         A[1][ai][bi] = fb ( 'a' , ai+1 , bi ) ;
    
    char c ; 
    if ( ch == 'a' ) c = a[ai-1] ; 
    else c = b[bi-1] ;         
        
        ll ans = 0 ; 
        if ( a[ai] != c ) ans = 1 ;
    
        ll val =  min (  A[0][ai][bi] , A[1][ai][bi] ) ; 
        if (val < 10000)
            ans += val ;  
            
    return ans ;     
   
}
 
ll fb (  char ch , ll ai , ll bi )
{   
    if ( bi >= n) return 10000 ; 
    
   if ( A[2][ai][bi] == -1 )
         A[2][ai][bi] = fa ( 'b' , ai , bi+1 ) ;       
    
    if ( A[3][ai][bi] == -1 )
         A[3][ai][bi] = fb ( 'b' , ai , bi+1 ) ;
    
    char c ; 
    if ( ch == 'a' ) c = a[ai-1] ; 
    else c = b[bi-1] ;         
        
        ll ans = 0 ; 
        if ( b[bi] != c ) ans = 1 ;
    
        ll val =  min (  A[2][ai][bi] , A[3][ai][bi] ) ; 
        if (val < 10000)
            ans += val ;  
    
    return ans ; 
}
 
int main() {
 
    tc(t)
    {
        cin>>n>>m ; 
        cin>>a; cin>>b;
        
        lp ( i , 4 )
        {   
            A.pb( vec < vec <ll> > () ) ;            
            
            lp ( j , n+1 )
            {   
                A[i].pb ( vec <ll>  () ) ;                
                
                lp ( k , m+1 )
                {
                    A[i][j].pb ( -1 ) ; 
                }
            }
        }
        
        ll ans = 1 + min ( min ( fa('a',1,0 ),fb('a',1,0 ) ) , min ( fa( 'b',0,1 ),fb('b',0,1 ) )    )  ;  
        
        cout<<ans<<endl ;  
        
    }
	return 0;
}