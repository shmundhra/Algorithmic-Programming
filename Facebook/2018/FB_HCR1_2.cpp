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
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
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
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; 

int preorder ( int root , vector<int> &A , vector<int> &B , vector<int> &ans )
{
    if ( root == 0 ) return 0 ; 
    ans.pb(root) ; 
    preorder(A[root],A,B,ans) ; 
    preorder(B[root],A,B,ans) ; 
    return 0 ;
}

int postorder ( int root , vector<int> &A , vector<int> &B , vector<int> &ans )
{
    if ( root == 0 ) return 0 ;      
    postorder(A[root],A,B,ans) ; 
    postorder(B[root],A,B,ans) ; 
    ans.pb(root) ;
    return 0 ;
}

vector < int > anc ; 
vector < int > size ; 

void initialise (  int n )
{ 
    anc.assign(n+1,0) ; 
    size.assign(n+1,0) ;
    lp ( i , n )
    {
        anc[i+1] = i+1 ;
        size[i+1] = 1 ;
    }
}

ll root ( int node )
{
    while ( anc[node] != node )
    {
         anc[node] = anc[ anc[node] ] ;
         node = anc[node] ;
    }
    return node ;
}

void join ( int v1 , int v2 )
{
    int r1 = root ( v1 ) ;
    int r2 = root ( v2 ) ;

    if ( r1 != r2 )
    {    
        if ( size[r1] < size[r2] )
        {
            anc[r1] = anc[r2] ;
            size[r2]+=size[r1] ;
        }
        else
        {
            swap(r1,r2) ;
            anc[r1] = anc[r2] ;
            size[r2]+=size[r1] ;
        }
    }
}

int main () 
{
    fast     
    ll t ; cin>>t ; 
    for ( int testcase = 1 ; testcase<= t ; testcase++ )
    {
        ll n,k ; 
        cin>>n>>k ; 

        vector<int> A ( n+1 , 0 ) ; 
        vector<int> B ( n+1 , 0 ) ; 

        lp ( i , n )
        {
            cin>>A[i+1]>>B[i+1] ; 
        }

        cout<<"Case #"<<testcase<<": ";

        vector < int > pre  ; 
        vector < int > post ;

        preorder(1,A,B,pre) ; 
        postorder(1,A,B,post) ; 

        vector < int > labels ( n+1 , 0 ) ;
        
        anc.clear() ; 
        size.clear() ; 

        initialise(n) ; 

        for ( int i = 0 ; i < pre.size() ; i++ )
        {
            join ( pre[i] , post[i] ) ; 
        }
        
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( anc[i] == i )
            {                   
                labels[i] = max(k,1) ;
                k-- ; 
            }
        }

        if ( k > 0 )
        {
            cout<<"Impossible"<<endl ; 
            continue ;
        }

        for ( int i = 1 ; i <= n ; i++ )
        {
            labels[i] = labels[root(i)] ; 
        }

        for ( int i = 1 ; i <= n ; i++ ) cout<<labels[i]<<" " ; cout<<endl ; 
        
    }
    
    return 0 ; 
}
