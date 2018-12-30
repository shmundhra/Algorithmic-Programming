//https://codeforces.com/contest/1092/problem/F

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
#define nl '\n' 
#define is == 
#define all(v) (v).begin() , (v).end()
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lp1(i , n ) for ( ll i = 1 ; i <= n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n ) 	 
#define umap unordered_map 

#define F first 
#define S second
#define pb push_back
#define mp make_pair

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( vec_name ) for ( auto val : vec_name ) cout<<val<<" " ; cout<<nl 
ll power(ll x,ll y,ll mod){ll res = 1; while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
#define fast ios::sync_with_stdio(false); cin.tie(0);

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; // 18! tak hai 

vll v ; 
vll sum ; 
vll val ; 
vll ans; 

void solve1 ( int i , int p , vll *adj )
{	
	sum[i] += v[i] ; 
	lp ( j , sz(adj[i]) )
	{
		ll nbr = adj[i][j] ; 
		if ( !sum[nbr] and nbr != p )
		{
			solve1 ( nbr , i , adj ) ; 
			val[i] += val[nbr] + sum[nbr] ; 
			sum[i] += sum[nbr] ; 
		}
	}		
}

void solve2 ( int i , int p , vll *adj )
{
	lp ( j , sz(adj[i]) )
	{
		ll nbr = adj[i][j] ; 
		if ( !ans[nbr] and nbr != p ) 
		{
			ll val1 = ans[i] - ( val[nbr] + sum[nbr] ) ; 
			ll val2 = sum[0] - sum[nbr] ; 
			ans[nbr] = val[nbr] + ( val1 + val2 ) ; 			
			solve2 ( nbr , i , adj ) ; 
		}
	}
}

int main () 
{
	fast 		
	ll n ; cin>>n ;
	v.assign(n,0) ; invec(v) ;  
	sum.assign(n,0) ; 
	val.assign(n,0) ;
	ans.assign(n,0) ;	

	ll x , y ; 
	vll adj[n] ; 
	lp ( i , n-1 )
	{
		cin>>x>>y ; x-- ; y-- ;
		adj[x].pb(y) ; 
		adj[y].pb(x) ; 
	}

	solve1(0,-1,adj) ; 
	//debug(sum) ; debug(val) ; 
	
	ans[0] = val[0] ; 
	solve2(0,-1,adj) ; 

	//debug(ans) ;
	cout<< *max_element(all(ans)) <<nl  ; 

	return 0 ; 
	
}
