//https://codeforces.com/contest/915/problem/D

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

#define vec vector 
#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) ll arr[n+10] = {0} ; lp ( i , n) cin>>arr[i] 

uwg vis , st , fin , adj[500] ; 
ll n ; 
ll timer ; 
ll be  ; 

int DFS ( ll source )
{
    vis[source] = 1 ; 
    st[source] = ++timer ; 
    //cout<<"\nSource -> " << source << " : " ; 
    
    lp ( i , adj[source].size()  )
    {
        ll v = adj[source][i] ; 
        
        if ( vis[v] == 1 )
        {   
            //cout<<"VV("<<v<<") " ; 
            if ( st[v] < st[source] && fin[v] == 0 )
            {
                //cout<<"<-#BE# " ;
                be++ ; 
            }
        }
        else if ( vis[v] == 0 )
            DFS ( v ) ; 
    }
    
    fin[source] = ++timer ; 
}


int main() {
	 
	 cin>>n ; 
	 scl(m) ; 
	
	 ll x , y ; 
	 lp ( i , m )
	 {
	    cin>>x>>y ; 
	    adj[x-1] .pb ( y-1 ) ; 
	 }
	 
	 lp ( k , n ) { 
	 
	     timer = 0 ; 
	     be = 0 ; 
	     vis.clear() ; 
	     st.clear () ; 
	     fin.clear() ;
	     
	     lp ( i , n )
	     {
	       vis.pb(0) ; 
	       st.pb(0) ; 
	       fin.pb(0) ; 
	     }
	 
	 lp ( i , n )
	 {
	     if ( vis[(i+k)%n ] == 0 )
	     {
	         DFS ( (i+k)%n ) ; 
	     }
	 }
    //cout<<"*"<<be ; 
	 if ( be <= 1 ) 
	 {   
	    // cout<<"$"<<k ; 
	     cout<<"YES" ; 
	     return 0 ; 
	 }
	 
	 }
	 cout<<"NO" ; 
	 
	 return 0;
}









