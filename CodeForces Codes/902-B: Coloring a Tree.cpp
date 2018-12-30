//https://codeforces.com/contest/902/problem/B

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair<int, int> pii;

#define sc(x) scanf("%llu", &x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(int i =a;i<b;i+=n)
#define f first 
#define s second
#define pb push_back
#define tc(t) ul t ; sc(t) ; while ( t-- )

vector < int > adj[10010] ;
vector < int > cc   ;
vector <int > cf ;
int arr[10010] = {0} ; 

ul x = 0 ; 
ul n ; 


void colour ( ul r )
{
    if ( !( cc[r] == cf[r] ) )
    {
        x++ ; 
        
        queue < int > q1 ; 
        q1.push(r) ;
        vector < int > visited1 ; 
        visited1.assign ( 10010 , 0 );
        visited1[r] = 1 ; 
        while ( !q1.empty() )
        {
             int b = q1.front() ; 
             
             q1.pop();
             cc[b] = cf[r] ; 
             rep ( i , 0 , adj[b].size() , 1)
             {   
                 if ( visited1 [ adj[b][i] ] == 0 && arr[  adj[b][i] ] != 1 )
                 {
                     visited1[ adj[b][i] ] = 1 ; 
                     q1.push(adj[b][i]) ; 
                 }
             }
        }
        
    }
}

int main() {
	
	sc(n);
	cc.assign ( n+2 , 0 );
	ul a ;
	rep ( i , 2 , n+1 , 1 )
	{
	    sc(a);
	    adj[i].pb(a);
	    adj[a].pb(i);
	}
	cf.pb(-1) ;  
	rep ( i , 1 , n+1 , 1)
	{ 
	    sc(a);
	    cf.pb( a );
	}
	
	queue < int > q ; 
    q.push(1) ;
    vector < int > visited ; 
    visited.assign ( n+2 , 0 );
    visited[1] = 1 ; 
    
    int b ;
    while ( !q.empty() )
    {
             b = q.front() ; 
             
             q.pop();
             colour(b) ;
             arr[b] = 1 ; 
             rep ( i , 0 , adj[b].size() , 1)
             {
                 if ( visited [ adj[b][i] ] == 0  )
                     {
                        visited[ adj[b][i] ] = 1 ; 
                        q.push( adj[b][i] ) ; 
                     }
             }
    }
    
    cout<<x<<endl;
    
	return 0;
}
