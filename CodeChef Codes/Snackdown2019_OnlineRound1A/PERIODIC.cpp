// https://www.codechef.com/SNCK1A19/problems/PERIODIC

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


ll gcd ( ll a , ll b )
{   
    if ( a < b ) swap ( a , b ) ;

    if ( b is 0 ) return a ;     
    return gcd ( b , a%b ) ; 
}

int main () 
{
    fast      
    tc(t)
    {
        ll n ; 
        cin>>n ; 
        
        inarr(n) ;     

        vp aux ;   
        lp ( i , n )
        {
            if ( v[i] != -1 )
            {
                aux.pb({v[i] , i}) ; 
            }
        }

        if ( sz(aux) <= 1 )
        {
            cout<<"inf"<<nl ; 
            continue ; 
        }
        
        ll flag1 = 1 ;        
        vll per ;   

        for ( int i = 1 ; i < sz(aux) ; i++ )
        {
            ll valD = aux[i].f - aux[i-1].f ; 
            ll indD = aux[i].s - aux[i-1].s ; 
            
            if ( valD > indD )
            {
                flag1 = 0 ; 
                cout<<"impossible"<<nl ; 
                break ; 
            }
            else if ( valD < indD )
            {                    
                per.pb(indD - valD) ;                
            }
        }

        if ( !flag1 ) continue ; 

        if ( per.empty() ) 
        {
            cout<<"inf"<<nl ; 
            continue ; 
        } 

        ll period ; 
        if ( per.size() is 1 )
        {
            period = per[0] ; 
        }
        else
        {
            period = gcd ( per[0] , per[1] ) ; 
            for ( int i = 2 ; i < sz(per) ; i++  )
            {
                period = gcd ( period , per[i] ) ; 
            }
        } 

        vll arr  ( v.begin() + aux.begin()->s , v.end() ) ; 
        vll patt ( sz(arr) ) ;

        lp ( i , sz(arr) )
        {
            patt[i] = ( ( arr[0] + i - 1 )%period + 1 ) ; 
        }

        lp ( i , sz(arr) )
        {
            if ( !(arr[i] is patt[i] or arr[i] is -1) )
            {
                flag1 = 0 ;
                break ; 
            }
        }

        if ( flag1 )
        {
            cout<<period<<nl ;
        }
        else
        {
            cout<<"impossible"<<nl ; 
        }

    }
    
    return 0 ; 
}
