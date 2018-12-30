//https://codeforces.com/contest/908/problem/B

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

int check ( ll i , ll j , ll n , ll m )
{
    if ( i < 0 || j < 0 || i >= n || j >= m)
        return 0 ;
    else
        return 1 ; 
}


int main() {
	
    ll n , m ; 
    cin>>n>> m ; 
    ll sx , sy , ex ,ey ; 
    char a[n][m] ; 
    string s ; 
    
    rep ( i , 0 , n , 1 )
    {
        rep ( j , 0 , m , 1 )
        {
            cin>>a[i][j] ;
            if ( a[i][j] == 'S')
            {
                sx = i ; 
                sy = j ;
            }
        }
    }
    
    cin>>s;
   
    char v[4] = { 'D' , 'L' , 'R' , 'U' } ;
     
    wg dir ( 127 ) ; 
    
    dir['D'] = mp ( 1,0 )  ; 
    dir['L'] = mp ( 0,-1 )  ;
    dir['R'] = mp ( 0,1 ) ;
    dir['U'] = mp ( -1,0 )  ;
    
    sort ( v , v + 4 ) ; 
    
    ll ans = 0 ; 
    ll flag = 0 ; 
    ll com ; 
    ll di ; 
    ll x , y ; 
    do
    {   
        x = sx ; 
        y = sy ; 
        rep ( i , 0 , s.size() , 1 )
        {
            com = s[i]-'0' ; 
            di = v[com] ; 
            
            x += dir[di].f ; 
            y += dir[di].s ; 
            
            if ( check ( x , y , n , m ) == 0 )
            {
                 /*
                cout<<"ERROR OOB FOR ->" ; 
                rep ( k , 0 , 4, 1 )
                    cout<<v[k] ;
                cout<<"\n";
                */
                break ; 
            }
            
            if ( a[x][y] == '#')
            {
                 /*
                cout<<"ERROR OB FOR ->" ; 
                rep ( k , 0 , 4, 1 )
                    cout<<v[k] ;
                cout<<"\n";
                  */  
                break ;
            }
            
            if ( a[x][y] == 'E')
            {
                /*
                cout<<"VALID FOR ->" ; 
                rep ( k , 0 , 4, 1 )
                    cout<<v[k] ;
                cout<<"\n";
                */
                ans++ ; 
                break ;
            }
            
            
        }
    
        
    }while( next_permutation( v , v+4 ) ) ;
    
    cout<<ans<<endl ; 
    
	return 0;
}
















