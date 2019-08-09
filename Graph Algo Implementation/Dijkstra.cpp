#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair<ll, ll>  pll ;
typedef pair< ll , pll > edge ; 
typedef vector < ll > uwg ;
typedef vector < pll > wg ;

#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; sc(t) ; while ( t-- )

int main() {

    scl(n);
    n++; 
    wg adj[n] ; 
    vector < edge > arr_edge ; 
    
    scl(e);
    rep ( i , 0 , e , 1 )
    {
        scl(v1) ; 
        scl(v2) ; 
        scl(cost) ;
        adj[v1].pb( mp( cost , v2 ) );
        arr_edge.pb( mp( cost , mp ( v1 , v2) ) ) ; 
    }
    
    wg dij_T[n] ; 

    priority_queue < edge , vector < edge > ,  greater<edge> > pq ; 
	pq.push( mp ( 0 , mp ( 0 , -1) ) ) ; 
	int marked[n] = { 0 } ; 
	ll  sp_cost[n] = { 0 } ;  
		
	while ( !pq.empty() )
	{
	    ll cost = ( pq.top() ) . f ; 
	    ll vert = ( pq.top() ) . s . f ; 
	    ll par  = ( pq.top() ) . s . s ; 
	    pq.pop() ; 
	    
	    if ( marked[vert] == 0 )
	    {   
	        marked[vert] = 1     ; 
	        sp_cost[vert] = cost ; 
	        
	        if ( par != -1 )
	        {
	            dij_T[ par ].pb( mp ( sp_cost[vert] - sp_cost[par] , vert) ) ;
	        }

	        lp ( i , adj[vert].size() )
	        {   
	            pll nbr = adj[vert][i] ; 
	            if ( marked[ nbr.s ] == 0 )
	            {
	                pq.push( mp ( sp_cost[vert] + nbr.f , mp ( nbr.s ,  vert ) ) ) ; 
	            }
	        }
	    }
	}
	
	rep ( i , 2 , n , 1 )
	    cout<< ( sp_cost[i] ? sp_cost[i] : 1E9 )<<" " ; 
	
	return 0 ; 
}