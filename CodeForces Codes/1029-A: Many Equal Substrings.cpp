//https://codeforces.com/contest/1029/problem/A

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
vector < ll > FailureFunction( string A )
{
   vector < ll > LPB ( (int)A.size() , 0 ) ; 
   
   int i = 1 ; int len = 0 ;
   
   while(i < (int)A.size() ) // Len always holds the value of the previous LPB 
   {
        if ( A[i] == A[len])
        {   
            LPB[i++] = ++len ; 
        }
        else
        {   
            if ( len == 0 )
            {
                LPB[i++] = 0 ; 
            }
            else    // Apparently this can be put into loop too ?? We basically need to keep doing this till we get either A[i] == A[len] or len : 0 -> -1 
            {      
                len = LPB[len-1] ; 
            }
        }
   }
   return LPB ; 
}

int main () 
{
    fast 

    ll n , k ; 
    cin>>n>>k ; 

    string s ;
    cin>>s ; 

    vec<ll> v = FailureFunction(s) ; 

    ll lpb = v.back()  ; 

    string ans = s ; 
    for ( int i = 0 ; i < k-1 ; i++ )
    {
        ans += string( s.begin() + lpb , s.end() ) ; 
    }
    cout<<ans<<endl ; 
    
    return 0 ; 
}
