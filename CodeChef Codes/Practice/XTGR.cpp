// https://www.codechef.com/problems/XTGR

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

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

ll solve ( vi &v1 , vi &v2  , int x )
{       
    multiset <pii> s1  ;    
    lp ( i , v1.size() )
    {
        s1.insert({v1[i],i}) ; 
    }
    
    multiset <pii> s2  ;    
    lp ( i , v2.size() )
    {
        s2.insert({v2[i],i}) ; 
    }
    
    vi hash1 ( v1.size() , 0 ) ; 
    int count1 = 0 ; 
    vi hash2 ( v2.size() , 0 ) ; 
    int count2 = 0 ; 

    if ( v1.size() == 1 and v2.size() == 1 ) return 0 ; 
    
    ll ans = INT_MAX ; 
    ll flag = 0 ; 
    while (flag <= 1000000)
    {   
        flag++ ; 
        auto it = s1.end() ; 

        auto it11 = it ;  it11-- ; ll max11 = it11->f ;
        ll max12 ; if ( v1.size() != 1 ) { auto it12 = it11 ; it12-- ; max12 = it12->f ; }

        ll min11 = s1.begin()->f ; 

        ll a = max11 - min11 ;   

        //_____________________________________    

        it = s2.end() ; 

        auto it21 = it ;  it21-- ; ll max21 = it21->f ;
        ll max22 ; if ( v2.size() != 1 ) { auto it22 = it21 ; it22-- ; max22 = it22->f ; }

        ll min21 = s2.begin()->f ; 

        ll b = max21 - min21 ;         
        
        //_______________________________________
        
        
        ll n1 , n2 ; 
        n1 = n2 = INT_MAX ; 
        
        if ( v1.size() != 1 ) n1 = ( max11 - max12 ) / x + 1  ; 
        if ( v2.size() != 1 ) n2 = ( max21 - max22 ) / x + 1  ; 
        
        ll n = mini ( n1 , n2 ) ; 
              
        
        int val = max11 - n*x ; 
        
        int ind = it11->s ;         
        if ( hash1[ind] == 0 )
        {
            hash1[ind] = 1 ; 
            count1++ ; 
        }    
        
        s1.erase ( it11 ) ; 
        s1.insert({val,ind}) ;   

        val = max21 - n*x ; 
        ind = it21->s ; 
        if ( hash2[ind] == 0 )
        {
            hash2[ind] = 1 ; 
            count2++ ; 
        }
        s2.erase ( it21 ) ; 
        s2.insert({val,ind}) ;           
        
        //cout<<a<<" "<<b<<endl ; 
                        
        ans = mini ( ans , a+b ) ; 
    }

    return ans ; 
}
int main () 
{
    fast 

    int n , m , x ; 
    cin>>n>>m>>x ; 

    vi v1 ( n , 0 ) ; 
    lp(i,n) cin>>v1[i] ;      

    vi v2 (m,0) ; 
    lp(i,m) cin>>v2[i] ;   

    ll ans = solve(v1 , v2 , x) ; 

    cout<<ans<<endl ; 

    return 0 ; 
}
