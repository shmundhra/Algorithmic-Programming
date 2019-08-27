// https://www.codechef.com/OCT18Aproblems/SURCHESS

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

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 


int main () 
{
    fast     

    ll n , m ; 
    cin >> n >> m ; 

    string s[n] ; lp ( i , n ) cin>>s[i] ; 

    vec < vll > v ( n+1 , vll( m+1 , 0 ) ) ; 

    lp1 ( i , n )
    {
        lp1 ( j , m )
        {
            v[i][j] = s[i-1][j-1] - '0' ;  
            v[i][j] = 2*v[i][j] + ( i + j ) % 2 ; 	
        }
    }

    ll q ; cin>>q ; vll query (q) ; lp ( i , q ) cin>>query[i] ; 

    vec < vec < vll > > pr ( n + 1 , vec < vll > ( m+1 , vll ( 4 , 0 ))) ; 
    lp1 ( i , n )
    {
        lp1 ( j , m )
        {
            pr[i][j].assign ( all ( pr[i][j-1] ) ) ; 
            pr[i][j][v[i][j]] ++ ; 
        }
    }

    vec < vec < vll > > pc ( n+1 , vec < vll > ( m+1 , vll ( 4 , 0 ))) ; 
    lp1 ( j , m )
    {
        lp1 ( i , n )
        {
            pc[i][j].assign ( all ( pc[i-1][j] ) ) ; 
            pc[i][j][v[i][j]] ++ ; 
        }
    }
    /*
    lp1 ( i , n )
    {
        lp1 ( j , m ) 
        {
            lp ( k , 4 )
            {
                cout<<pr[i][j][k]<<" " ; 
            }
            cout<<endl ; 
        }
        cout<<endl;
    }
    cout<<endl ;
    
    lp1 ( j , m )
    {
        lp1 ( i , n ) 
        {
            lp ( k , 4 )
            {
                cout<<pc[i][j][k]<<" " ; 
            }
            cout<<endl ; 
        }
        cout<<endl;
    }
    cout<<endl ; 
    */

    vll ans(100000+1,1) ;  
    vll a ;

    lp1 ( i , n )
    {
        lp1 ( j , m )
        {
            a.assign(4,0) ; 
            lp1 ( len , min ( n+1-i , m+1-j ) )
            {
                ll r = i + len - 1 ; 
                ll c = j + len - 1 ; 

                lp ( k , 4 )
                {
                    a[k] = a[k] + pr[r][c][k] - pr[r][j-1][k] + pc[r][c][k] - pc[i-1][c][k] - (int)(v[r][c] is k ) ; 
                }                                
                
                //cout<<a[0]<<"+"<<a[3]<<"_"<<len<<" "<<a[1]<<"+"<<a[2]<<"_"<<len<<" " ; 
                
                ans[( a[0] + a[3] )] = max ( ans[( a[0] + a[3] )] , len ) ; 
                ans[( a[1] + a[2] )] = max ( ans[( a[1] + a[2] )] , len ) ; 
            }
            //cout<<nl ; 
        }
    }       

    lp1 ( i , 100000 )
    {
        ans[i] = max ( ans[i] , ans[i-1] ) ; 
    }
    
    lp ( i , sz(query) )
    {
        ll que = query[i] ;         
        que = min ( que , (ll)100000 ) ; 

        cout<<ans[que]<<nl ; 
    }

    return 0 ; 

}
