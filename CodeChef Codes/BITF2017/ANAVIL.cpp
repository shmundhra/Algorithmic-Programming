// https://www.codechef.com/BITF2017problems/ANAVIL

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
#define tc(t) scu(t); while ( t-- )


int main() {
	
	scl(n) ; 
	uwg v[2*n+1] ;
	int x , y ;
	rep ( i , 0 , n , 1 )
	{
	    cin>>x>>y ; 
	    v[x].pb(y) ; 
	    v[y].pb(x) ; 
	}
	
	int vis[2*n+1] = {0} ; 
	int mini = 15002 ; 
	int maxi = 0 ; 
	rep ( j , 0 , 2*n , 1 )
	{
	    if ( vis[j+1] == 0 )
	    {   
	        int c = 1 ; 
	        int s = j + 1 ; 
	        queue <int> q;
            q.push(s);
            
            vis[ s ] = 1;
            while(!q.empty())
            {
                 int p = q.front();
                 q.pop();
                 for(int i = 0;i < v[ p ].size() ; i++)
                 {
                       if(vis[ v[ p ][ i ] ] == 0)
                       {    
                            c++ ; 
                            q.push(v[ p ][ i ]) ;
                            vis[ v[ p ][ i ] ] = 1 ;
                       }
                 }
            }
            maxi = max ( c , maxi) ; 
            if ( c!= 1) mini = min ( c , mini) ; 
        }
	    
	}
	
	cout<<mini<<" "<<maxi ; 
	
	return 0;
}













