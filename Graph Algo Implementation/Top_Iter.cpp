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

    scl(n);n++;
    uwg adj[n] ;

    scl(e);
    rep ( i , 0 , e , 1 )
    {
        scl(v1) ;
        scl(v2) ;
        adj[v1].pb( v2 );
    }

    rep ( i , 0 , n , 1 )
        sort ( adj[i].begin() , adj[i].end() , greater<ll>() ) ;

    int vis[n] = { 0 } ;
    uwg top_sort[n]  ;

    ll cc = -1 ;
    rep ( i , 1 , n , 1 )
    {
        if ( vis[i] == 0 )
        {
            cc++ ;
            stack < ll > s ;
            s.push(i) ;
            while ( !s.empty( ) )
            {
                ll vert = s.top () ;
                s.pop () ;
                if ( vis[vert] == 0 )
                {
                     vis[vert] = 1 ;
                     top_sort[cc].pb ( vert ) ;

                     rep ( j , 0 , adj[vert].size() , 1 )
                    {
                        ll nbr = adj[vert][j] ;
                        if ( vis[nbr] == 0 )
                            s.push( nbr ) ;
                    }
                }
            }
        }
    }
    rep ( i , 0 , cc+1 , 1 )
        rep ( j , 0 , top_sort[cc-i].size() , 1 )
            cout<<top_sort[cc-i][j]<<" ";

   return 0 ;
}
