// https://www.codechef.com//JAN18/problems/MONSTER

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
#define fast ios::sync_with_stdio(false); cin.tie(0);


int main() {
    
    fast 
    
    ll n ;
    cin>>n ; 
    ll arr[n] ; 
    lp ( s , n ) 
        cin>>arr[s] ; 
    
    ll num = n ; ll dig = 1 ; 
	while ( num>>=1 ) dig++ ; 
	ll high = 1<<dig ; 
    
    ll x , y ; 
    
    ll q ; 
    cin>>q ; 
    
    ll rt = (ll)sqrt(q) ; 
    //cout<<rt<<endl;
    ll alive = n ; 
    
    lp ( i , rt+1)
    {   
        ll ans[rt+1] = {0} ; 
        wg lel[high] ;
        ll val[high] = {0} ;
        wg quer ; 
            
        ll count = 0 ; 
        lp ( j , ( min( (i+1)*rt , q ) - i*rt) )
        {
            cin>>x>>y ; 
            x = x%high ; 
            count++ ; 
            lel[x].pb( mp ( j , y) ) ;     
            val[x] += y ; 
            quer.pb(mp(x,y)) ; 
        }
        
        lp (j , dig )
        {    for(int mask = 0; mask < high ; ++mask)
            {
	            if((mask & (1<<j)) == 0)
	            {
	                val[mask] += val[mask^(1<<j)] ; 
	                lel[mask].insert( lel[mask].end() , lel[mask^(1<<j)].begin() ,  lel[mask^(1<<j)].end()  ) ; 
	            }
            }
        }    
        
        lp (j , n )
        {   
            if ( arr[j] <= 0 ) continue ; 
            
            if (  arr[j] - val[j] > 0 )
                arr[j] -= val[j] ; 
                
            else if ( arr[j] - val[j] <= 0)
            {   
                lp ( t , count )
                {
                    if ( (j&quer[t].f) == j)
                    {
                        arr[j] -= quer[t].s ; 
                        if ( arr[j] <= 0 )
                        {
                            ans[ t ] ++ ; 
                            break ; 
                        }
                    }
                }
                
            }
        }
        //cout<<count<<endl ; 
        lp ( j , count )
        {
            cout<<alive-ans[j] <<endl ; 
            alive -= ans[j] ; 
        }
        
    }
 	return 0;
}










