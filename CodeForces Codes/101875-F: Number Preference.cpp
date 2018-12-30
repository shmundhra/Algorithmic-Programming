//https://codeforces.com/gym/101875/problem/F

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
#define nl '\n' 
#define is == 
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

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 



int main () 
{
    fast     

    ll n ; cin>>n ; 

    int t , s ; 

    set < ll > pool ; 
    vector < vll > like ; 
    vector < vll > hate ; 

    lp ( i , n )
    {
        cin>>t>>s ; 
        vll v(s) ; 

        lp ( j , s )
        {
            cin>>v[j] ; 
            pool.insert( v[j] ) ; 
        }

        if ( t == 1 )
        {             
            like.pb(v) ; 
        }
        else
        {            
            hate.pb(v) ; 
        }
    }

    vec < ll > red ( all(pool) ) ; 
    map < ll , ll > m ; 
    
    lp ( i , sz(red) )
    {
        m[red[i]] = i ; 
    }

    vll hashl ( sz(red) , 0 ) ; 
    vll hashh ( sz(red) , 0 ) ; 

    lp ( i , sz(like) ) 
    {
        lp ( j , sz(like[i]) )
        {
            hashl[  m[ like[i][j] ]  ] ++ ; 
        }
    }

    lp ( i , sz(hate) ) 
    {
        lp ( j , sz(hate[i]) )
        {
            hashh[  m[ hate[i][j] ]  ] ++ ; 
        }
    }

    if ( !sz(like) )
    {
        ll ans = 1e18 ; 
        lp ( i , sz(hashh) )
        {
            if ( hashh[i] ) ans -- ; 
        }
        cout<<ans<<endl ; 
        return 0 ; 
    }

    ll ans = 0 ; 
    lp ( i , sz(hashl) )
    {            
        if ( hashl[i] is sz(like) and !hashh[i] )
            ans ++ ; 
    }
    cout<<ans<<nl ; 
    return 0 ; 
    

}