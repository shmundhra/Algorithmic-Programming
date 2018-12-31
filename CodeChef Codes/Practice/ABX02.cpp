// https://www.codechef.com/problems/ABX02

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
 
#define modu 1000000007 
#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) scu(t); while ( t-- )
 
ll P , Q , S1 , S2 , B1 , B2 , N ; 
 
ll a[51][51][51][51] ; 
ll b[51][51][51][51] ;
 
ll f1 ( ll , ll , ll , ll , ll ) ; 
ll f2 ( ll , ll , ll , ll , ll ) ; 
 
ll f1 ( ll l , ll p , ll q , ll b1 , ll b2 )
{   
    if ( p  > P )   return 0 ; 
    if ( l  > S1 )  return 0 ; 
    if ( b1 > B1 )  return 0 ; 
    if ( p+q > N )  return 0 ;
    
    if ( ( p + q )== N) return 1 ;
    
    if ( l == 1 ) 
        if (a[p][q][b1][b2]  != -1 ) 
            return a[p][q][b1][b2] ; 
        else
        {
            a[p][q][b1][b2] = f1 ( l+1 , p+1 , q , b1 , b2 )%modu + f2 ( 1 , p , q+1 , b1 , b2+1 )%modu ;
            a[p][q][b1][b2] = a[p][q][b1][b2]%modu ; 
            return a[p][q][b1][b2] ; 
        }   
 
    
    return f1 ( l+1 , p+1 , q , b1 , b2 )%modu + f2 ( 1 , p , q+1 , b1 , b2+1 )%modu ; 
}
 
ll f2 ( ll l , ll p , ll q , ll b1 , ll b2 )
{   
    if ( q  > Q )   return 0 ; 
    if ( l  > S2 )  return 0 ; 
    if ( b2 > B2 )  return 0 ; 
    if ( p+q > N )  return 0 ; 
    
    if ( ( p + q )== N) return 1 ; 
    
    if ( l == 1 ) 
        if ( b[p][q][b1][b2]  != -1 ) 
            return b[p][q][b1][b2] ; 
        else
        {
            b[p][q][b1][b2] = f1 ( 1 , p+1 , q , b1+1 , b2 )%modu + f2 ( l+1 , p , q+1 , b1 , b2 )%modu ; 
            b[p][q][b1][b2] = b[p][q][b1][b2]%modu ; 
            return b[p][q][b1][b2] ;
        }
        
    
    return  f1 ( 1 , p+1 , q , b1+1 , b2 )%modu + f2 ( l+1 , p , q+1 , b1 , b2 )%modu ; 
}

int main() {
	
    tc(t)
    {   
        cin>>P>>Q>>N ; 
        cin>>B1>>B2  ;
        cin>>S1>>S2  ;
        
        rep ( i , 0 , P+1 , 1 )
            rep ( j , 0 , Q+1 , 1 )
                rep ( k , 0 , min(P,B1)+1 , 1 )
                    rep ( l , 0 , min(Q,B2)+1 , 1)
                    {
                         a[i][j][k][l] = -1 ; 
                         b[i][j][k][l] = -1 ; 
                    }
        
        a[1][0][1][0] = f1 ( 1 , 1 , 0 , 1 , 0 ) ; 
        b[0][1][0][1] = f2 ( 1 , 0 , 1 , 0 , 1 ) ;
        
        ll ans = a[1][0][1][0] + b[0][1][0][1] ; 
        
        cout<<(ans%modu)<<endl ; 
    }
	return 0;
}
 