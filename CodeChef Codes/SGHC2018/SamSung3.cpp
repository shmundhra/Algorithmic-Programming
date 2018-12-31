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
ll abso ( ll x ) { return x >= 0 ? x : -x ; }
// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 


int main () 
{
    fast 

    tc(t)
    {
        ll n,k ; cin>>n>>K ; inarr(n) ; 

        vec < vec < ll > > s ( n , vec<ll>( n , 0 ) ) ; 

        lp(i,n)
        {   
            vec < ll > hash ( 1000001 , 0 ) ; 
            set < ll , greater<ll> > s ; 
            
            for ( int j = i ; j < n ;  j++ )
            {
                hash[ v[j] ] += 1 ;
                if ( hash[ v[j] ] % 2 == 1 )
                {
                    s.insert( v[j] ) ; 
                } 
                else
                {
                    s.erase( s.find(v[j]) ) ; 
                }
                s[i][j] = *( s.begin() ); 
            }
        }

        vector < vector<ll> > dp(n , vector <ll> (K+1 , -1e15 ) ) ; 

        lp(i,n) dp[i][1] = s[i][n-1] ; 

        for ( int k = 2  ; k <= K ; k++ )
        {
            for ( int i = 0 ; i < n ; i++ )
            {
                for ( int j = i ; j <= n-k ; j++ )
                {
                    dp[i][k] = maxi ( dp[i][k] , s[i][j] + dp[j+1][k-1] ) ; 
                }
            }
        }

        lp1(i,K)
        {
            cout<<dp[0][i]<<" " ; 
        }
        cout<<endl ; 
    }
    
    return 0 ; 
}
