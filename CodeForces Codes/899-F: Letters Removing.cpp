//https://codeforces.com/contest/899/problem/F

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

ll n ; 

int query ( ll arr[200001] , ll index )
{
    ll val = 0 ; 
    for ( ll i = index ; i > 0 ; i -= i & (-i) )
            val += arr[i] ; 
    
    return ( val ) ; 
}

ll bin_search ( ll arr[200001] , ll index )
{
    ll b , e , m , pref , ans ; 
    b = index ; 
    e = n ; 
    m = b + (e-b)/2 ; 
    while ( b <= e )
    {
        pref = query ( arr , m ) ; 
        if ( (m - pref) == index ) 
        {
            ans = m ;
            e = m - 1 ;
            m = b + (e-b)/2 ; 
            
        }
        else if ( ( m - pref ) > index )
        {
            e = m - 1 ;
            m = b + (e-b)/2 ; 
        }
        else
        {
            b = m + 1 ;
            m = b + (e-b)/2 ; 
        }
    }
    return ans ; 
}

void update ( ll arr[200001] , ll index )
{
    for ( ll i = index ; i <=n ; i += i & (-i) )
            arr[i] += 1 ; 
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll l , r , m ; 
    vector < set < ll >  > a ( 126 ) ;
    set < ll > :: iterator li , ri , itr ; 
    
    cin>>n>>m ; 
	ll arr[n+1] = {0} ;
	
	char c ; 
	rep ( i , 1 , n+1 , 1 )
	{
	    cin>>c ; a[c].insert(i) ; 
	}

	rep ( i , 0 , m , 1 )
    {
        cin >> l >> r >> c ; 
        l = bin_search ( arr , l ) ; 
        r = bin_search ( arr , r ) ;
        
        // cout<<"#"<<l<<"#"<<r<<endl ;
        
        for ( itr = a[c].begin() ; itr != a[c].end() ; itr ++ )
            if ( (*itr) >= l )
                break ; 
        li = itr ;    
        
        for ( itr = li ; itr != a[c].end() ; itr ++ )
            if ( (*itr) > r )
                break ; 
        ri = itr ;
        
        for ( itr = li ; itr != ri ; itr++ )
            update( arr , (*itr) ) ; 
        
        a[c] . erase ( li , ri ) ; 
    
    }
    
    char s[n+1] = {0} ; 
    rep ( i , 0 , 125 , 1 ) 
    {
        for ( itr = a[i].begin() ; itr != a[i].end() ; itr++ )
        {
            s[*itr] = i ; 
        }
    }
    rep ( i , 1 , n+1 , 1 )
    {
        if ( s[i] != 0 )
            cout<<s[i] ; 
    }
    cout<<endl ; 
   
    	
	return 0;
}