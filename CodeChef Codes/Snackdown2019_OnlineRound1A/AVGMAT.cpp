// https://www.codechef.com/SNCK1A19/problems/AVGMAT

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
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( vec_name ) for ( auto val : vec_name ) cout<<val<<" " ; cout<<nl 

#define fast ios::sync_with_stdio(false); cin.tie(0);

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 



int main () 
{
    fast      
    tc(t)
    {
        ll n , m ; 
        cin>>n>>m ;

        string inp[n] ; 
        lp ( i , n ) cin>>inp[i] ; 

        vi tmp ( 1501 , 0 ) ; 
        vec < vi > arr ( 1501 , tmp ) ; 
        vec < vi > forw ( 1501 , tmp ) ; 
        vec < vi > back ( 1501 , tmp ) ; 

        lp ( i , n ) lp ( j , m ) 
        forw[i+600][j+600] = back[i+600][j+600] = arr[i+600][j+600] = ( inp[i][j] - '0' ) ; 

        for ( int i = 1 ; i < 1500 ; i++ )
        {
            for ( int j = 1 ; j < 1500 ; j++ )
            {
                forw[i][j] = arr[i][j] + forw[i-1][j+1] ; 
                back[i][j] = arr[i][j] + back[i-1][j-1] ; 
            }
        }

        vll ans ( 600 , 0 ) ; 

        lp ( i , n ) lp ( j , m )
        {
            if ( arr[i+600][j+600] == 1 )
            {
                lp1 ( d , n+m-2 )
                {   
                    ll ru = back[i+600][j+600 + d ] - back[i+600 - d ][j+600] ; 

                    ll rd = forw[i+600 + d][j+600] - forw[i+600][j+600 + d] ; 

                    ll ld = back[i+600 + d][j+600] - back[i+600][j+600 - d] ; 

                    ll lu = forw[i+600][j+600 - d] - forw[i+600 - d][j+600] ;  

                    ll bottom = arr[i+600 + d][j+600] ; 
                    ll top =    arr[i+600 - d][j+600] ; 

                    ans[d] = ( ans[d] +  ru +  rd +  ld +  lu - bottom + top ) ; 
                    
                    //cout<<d<<"-> "<<ru<<" "<<rd<<" "<<ld<<" "<<lu<<" "<<ans[d]<<nl ; 
                }
            }
        }

        lp1 ( d , n+m-2 )
        {
            cout<<ans[d]/2<<" " ; 
        }

    }

}
