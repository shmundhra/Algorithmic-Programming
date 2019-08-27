// https://www.codechef.com/ELE32018problems/CHFPRMDM

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

int main () 
{
    fast     

    const int LIM = 15000000 ; 
    vector < bool > isprime ( LIM+1 , true ) ; 
    isprime[0] = isprime[1] = false ;         

    for ( long long i = 2 ; i*i <= LIM ; i++ )
    {
        if ( isprime[i] )
        {
            for ( long long j = i*i ; j <= LIM ; j+=i )
            {
                isprime[j] = false ; 
            }
        }
    }

    tc(t)
    {
        ll n ; 
        cin>>n ; 

        inarr(n) ; 

        lp ( i , n )
        {
            if ( isprime[v[i]] ) v[i] = 1 ; 
            else v[i] = -1 ; 
        }

        vll pref(n+1,0) , best(n+1) ; 

        lp1(i,n) 
        {
            pref[i] = pref[i-1] + v[i-1] ; 
        }

        best[n] = pref[n];
        for(int i=n-1; i>-1; --i)
            best[i] = max(best[i+1], pref[i]);
         
        ll length = INT_MIN; 
        ll start = 1 ; 
        for(int end=1; end<n+1; ++end)
        {
            if( best[end] > pref[start-1] ) 
                length = max(length, end-start+1);
            else 
                ++start;
        }
        cout<<length<<endl ; 
    }

    return 0 ; 
}
