// https://www.codechef.com/problems/KCOMPRES

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

#define minimum(E,F) ( (E) > (F) ? (F) : (E) )   
#define maximum(E,F) ( (E) < (F) ? (F) : (E) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

ll n , s ; 
vll a , b ; 
vp v , seg_tree ; 


void build ( ll index , ll start , ll end )
{
    if ( start == end )
    {
        seg_tree[index] = { 1 , -a[start] } ; 
        return ; 
    }

    ll mid = start + ( end-start )/2 ; 

    build ( 2*index , start , mid ) ; 
    build ( 2*index+1, mid+1 , end ) ;
    
    return ;     
}

int update ( ll index , ll start , ll end , ll position , ll value )
{
    if ( position < start or end < position ) return 0 ; 

    if ( start == end ) 
    {
        seg_tree[index].f = value ; 
        return 0 ; 
    }

    ll mid = start + ( end-start )/2 ; 

    update ( 2*index , start , mid , position , value ) ; 
    update ( 2*index+1 , mid+1 , end , position , value ) ;

    if (  start <= position and position <= end )
    {
        pll p1 = seg_tree[2*index] ; 
        pll p2 = seg_tree[2*index+1] ; 

        if ( p1 > p2 ) 
        {
            seg_tree[index] = p1 ; 
        }
        else
        {
            seg_tree[index] = p2 ;     
        }
    } 
    
    return 0 ; 
}


pll query ( ll index , ll start , ll end , ll left , ll right )
{
    if ( right < start or end < left ) return {-1,0} ; 

    if (  left <= start and end <= right ) return seg_tree[index] ; 

    ll mid = start + ( end-start )/2 ; 

    pll p1 = query ( 2*index , start , mid , left , right ) ; 
    pll p2 = query ( 2*index+1 , mid+1 , end , left , right ) ; 

    if ( p1 > p2 ) 
    {
        return p1 ; 
    }
    else
    {
        return p2 ;     
    }
}

bool check ( int k )
{    
    seg_tree.clear() ; 
    seg_tree.assign( 4*n, {0,-1} ) ; 
    build( 1 , 1 , n ) ; 
    
    ll mini = v[0].f ; 
    ll start , end ; 
    start = 0 ; 

    lp ( i , n+1 )
    {    
        //for ( int i = 1 ; i < 2*n ; i++ ) cout<<"("<<seg_tree[i].f<<","<<seg_tree[i].s<<") " ; cout<<endl ; 
        if ( i == n or v[i].f > v[start].f )
        {
            for ( ll j = start ; j < i ; j++ )
            {   
                ll pos = v[j].s ;
                pll p = query ( 1 , 1 , n , maximum(1,pos-k) , minimum(n,pos+k) ) ; 
                if ( v[j].f == -p.s )
                {
                    b[pos] = p.f ; 
                }
                else
                {
                    b[pos] = p.f + 1 ; 
                }
                update ( 1 , 1 , n , pos , b[pos] ) ; 
            }
            start = i ; 
        }
        
        if ( i == n ) break ; 
        
        
        ll pos = v[i].s ; 
        if ( v[i].f == mini )
        {
            b[pos] = 1 ;             
        }
        else
        {
            pll p = query ( 1 , 1 , n , maximum(1,pos-k) , minimum(n,pos+k) ) ; 
            if ( v[i].f == -p.s )
            {
                b[pos] = p.f ; 
            }
            else
            {
                b[pos] = p.f + 1 ; 
            }
        }
        update ( 1 , 1 , n , pos , b[pos] ) ;          
    }
    
    //cout<<k<<" : " ; lp1(i,n) cout<<b[i]<<" " ; cout<<endl ;     
    return ( accumulate( all(b) , 0 ) <= s ) ; 
}


int main () 
{
    fast 
    
    tc(t)
    {
        cin>>n>>s ; 

        a.assign(n+1,0) , b.assign(n+1,0) , v.clear() ;  

        lp1( i , n )
        {
            cin>>a[i] ; 
            v.pb( {a[i],i} ) ; 
        }
        sort( all(v) ) ; 

        ll low = -1 , high = n ; ll mid ; 

        while ( low < high )
        {
            mid = low + ( high - low + 1 ) / 2 ; 

            if ( check(mid) )
            {
                low = mid ; 
            }
            else
            {
                high = mid-1 ; 
            }
        }
        
        cout<<low+1<<"\n" ; 
    }
    
    return 0 ; 
}
