//https://codeforces.com/contest/1029/problem/D

#include <bits/stdc++.h>
#include <stdio.h>
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
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lp1(i , n ) for ( ll i = 1 ; i <= n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )      
#define umap unordered_map 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

int main () 
{
    //fast 

    int n , k ; 
    scanf("%d%d",&n,&k) ;     
    //cin>>n>>k ; 
    
    vi v ( n , 0 ) ; lp ( i , n ) scanf("%d" , &v[i] ) ;        
        
    //inarr(n) ; 

    vll power(11,0) ;

    ll val = 10 ; 
    for ( int i = 1 ; i < 11 ; i++ )
    {
        power[i] = val%k ; 
        val*=10 ; 
    } 

    umap < int , int  > m[11] ; 

    lp ( i , n )
    {
        lp1( j , 10 )
        {   
            ll val = ( ( v[i] % k )*( power[j] ) ) %k ; 
            m[j][ val ] ++ ; 
        }
    }

    ll ans = 0 ; 
    lp ( i , n )
    {         
        ll want = k - v[i]%k ; 
        if ( want == k ) want = 0 ; 

        ll len = 1 ; for ( ll a = v[i] ; a >=10 ; a/=10 , len++ ) ; 

        ans += m[len][want] ; 
        
        //cout<<v[i]<<" "<<ans<<endl ; 
    }

    lp ( i , n )
    {
        ll len = 1 ; for ( ll a = v[i] ; a >=10 ; a/=10 , len++ ) ; 

        ll val = ( ( v[i] % k )*( power[len] ) ) %k + ( v[i] % k ) ;

        if ( val % k == 0 ) ans -- ; 
    }

    cout<<ans<<endl ; 

    return 0 ; 
}
