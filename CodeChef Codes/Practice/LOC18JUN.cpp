// https://www.codechef.com/problems/LOC18JUN

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
    
    int n ; 
    cin>>n ; 
    
    vector < string > v (n) ; 
    lp(i,n) cin>>v[i] ; 
    
    lp(i,n)
    {
        for ( int j = v[i].size() ; j < 20 ; j++ )
        {
            v[i].pb('a'-1) ; 
        }
    }
    
    vector <int> m[20][27] ; 
    
    lp ( i , 20 )
    {
        lp ( j , n )
        {
           m[i][ v[j][i] - 'a' + 1 ].push_back(j) ; 
        }
    }
    
    tc(q)
    {
       int l , r , p ; char c ; 
       
       cin>>l>>r>>p>>c ; 
       
       l-- ; r-- ; p-- ; 
      
       auto li = lower_bound( m[p][c-'a'+1].begin() , m[p][c-'a'+1].end() , l ) ;
       auto ri = upper_bound( m[p][c-'a'+1].begin() , m[p][c-'a'+1].end() , r ) ;
       
       cout<<ri-li<<endl ; 
    }
    
	return 0 ; 
}