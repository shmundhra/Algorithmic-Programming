//https://codeforces.com/contest/1000/problem/B

#include <bits/stdc++.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ; 
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

#define MOD 1000000007 
#define vec vector 
#define iu(x) ul x ; cin>>x ; 
#define il(x) ll x ; cin>>x ;  
#define pr(x) cout<<x ;   
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long int)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n ) 	 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  
#define fast ios::sync_with_stdio(false); cin.tie(0);

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }


int main () 
{
	fast 
    int n , m ; 
    cin>>n>>m ; 
    
    vll v (n+2) ; 
    v[0] = 0 ; 
    
    rep ( i , 1 , n+1 , 1 ) cin>>v[i] ; 
    v[n+1] = m ; 
    
    vll pon(n+2,0) ; 
    vll pe(n+2,0) ;
    vll son(n+2,0) ; 
    vll se(n+2,0) ;
    
    rep ( i , 1 , n+1 , 2 )
    {
        pon[i] = pon[i-1] + v[i] - v[i-1] ; 
        pon[i+1] = pon[i] ; 
    }
    rep ( i , 2 , n+1 , 2 )
    {
        pe[i] = pe[i-1] + v[i] - v[i-1] ; 
        pe[i+1] = pe[i] ; 
    }
    
    if ( n%2 == 0 )
    {
        pon[n+1] = pon[n] + v[n+1] - v[n] ; 
        pe [n+1] = pe[n] ; 
    }
    else
    {
        pe[n+1] = pe[n] + v[n+1] - v[n] ; 
        pon[n+1] = pon[n] ; 
    }
    
    ll ton = pon[n+1] ; 
    ll te = pe[n+1] ; 
    
    lp ( i , n+2 )
    {
        son[i] = ton - pon[i] ; 
        se[i] = te - pe[i] ; 
    }
    
    ll big = ton ; 
    
    rep ( i , 1 , n+1 , 1 )
    {
        ll y = pon[i-1] + ( ( v[i]-1 ) - v[i-1] ) + se[i] ; 
        big = maxi ( big , y ) ; 
        
        ll z = pon[i] + v[i+1] - ( v[i] + 1 ) - se[i+1] ; 
        big = maxi ( big , z ) ; 
    }
    
    cout<<big<<endl ; 

    
    
    
    

	return 0 ; 
}














