// https://www.codechef.com/problems/PRGCUP04

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
typedef vector < ll > uwg ;
typedef vector < pll > wg ;

void swap(  ll *r1 , ll *r2 )
{
    *r1 = *r1 + *r2 ; 
    *r2 = *r1 - *r2 ; 
    *r1 = *r1 - *r2 ;
}
#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(int i =a;i<b;i+=n)
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; sc(t) ; while ( t-- )

ll anc[110] ; 
ll size[110];

void initialise ( ll n )
{
  rep ( i , 0 , n , 1)
  {
      anc[i] = i ; 
      size[i] = 1 ; 
  }
}

ll root ( ll node )
{
    while ( anc[node] != node )
    {
         anc[node] = anc[ anc[node] ] ; 
         node = anc[node] ;
    }
    return node ;
}

void join ( ll v1 , ll v2 )
{
    ll r1 = root ( v1 ) ; 
    ll r2 = root ( v2 ) ; 
    if ( size[r1] < size[r2] )
    {
        anc[r1] = anc[r2] ; 
        size[r2]+=size[r1] ; 
    }
    else
    {   
        swap(&r1,&r2) ; 
        anc[r1] = anc[r2] ; 
        size[r2]+=size[r1] ;
    }
    
}


int main() {

    scl(n);
    n++; 
    wg adj[n] ; 
    wg mst[n] ; 
    
    vector < pair < ll , pll > > edge ; 
    scl(e);
    rep ( i , 0 , e , 1 )
    {
        scl(v1) ; 
        scl(v2) ; 
        scl(cost) ;
        adj[v1].pb( mp( cost , v2 ) );
        adj[v2].pb( mp( cost , v1 ) );
        edge.pb( mp( cost , mp ( v1 , v2) ) ) ; 
    }
    
    initialise ( n ) ; 
    
    ll min_cost = 0 ;
    sort ( edge.begin() , edge.end() ) ; 
    rep ( i , 0 , e , 1 )
    {
        ll v1   = edge[i].s.f ; 
        ll v2   = edge[i].s.s ;
        ll cost = edge[i].f   ;
        
        if ( root(v1) != root (v2) )
        {   
            min_cost += cost ;
            join ( v1 , v2 ) ; 
            mst[v1].pb ( mp (cost , v2) ) ; 
            mst[v2].pb ( mp (cost , v1) ) ; 
        }
        
    }
	
	cout<<min_cost ; 
	return 0;
}
