//https://codeforces.com/contest/1000/problem/A

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
    int n  ; 
    cin>>n ; 
    
    unordered_map < string , int > m1 , m2 ; 
    string s ; 
    
    lp ( i , n )
    {
        cin>>s ; 
        m1[s] ++ ; 
    }
    
    lp ( i , n )
    {
        cin>>s ; 
        m2[s]++ ; 
    }
    
    vector < string > v = { "S" , "M" , "L" , "XS" , "XL" , "XXS" , "XXL" , "XXXS" , "XXXL" } ; 
    
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        int x = min ( m1[ v[i] ] , m2[ v[i] ] ) ; 
        m1[v[i]] -=x ; 
        m2[v[i]] -=x ; 
    }
    long long val = 0 ;
    
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        val += m2[ v[i] ] ; 
    }
    
    cout<<val<<endl ; 
    

	return 0 ; 
}






