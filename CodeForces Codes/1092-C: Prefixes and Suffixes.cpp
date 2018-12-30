//https://codeforces.com/contest/1092/problem/C

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

int main () 
{
	fast 		
	ll n ; cin>>n ; string s ; 
	
	vec < pair < pair<int,int> , string > > v(2*n-2) ; 
	lp ( i , 2*n-2)
	{
		cin>>s ; 
		v[i]={ {sz(s),i} , s } ; 
	}
	sort(all(v)) ; 
	//lp ( i , sz(v) ) cout<<v[i].S<<" " ; cout<<nl ; 

	vec < pair < string , string > > aux ; 

	aux.pb( { v[0].S + v[2*n-3].S , v[2*n-4].S + v[1].S  } ) ; 
	aux.pb( { v[2*n-3].S + v[0].S , v[1].S + v[2*n-4].S  } ) ;

	aux.pb( { v[1].S + v[2*n-3].S , v[2*n-4].S + v[0].S  } ) ; 
	aux.pb( { v[2*n-3].S + v[1].S , v[0].S + v[2*n-4].S  } ) ; 

	lp ( var , sz(aux) )
	{			
		if ( aux[var].F is aux[var].S )
		{	
			string ans ( 2*n-2 , ' ') ;
			s = aux[var].F ; 

			map < string , int > PM ; 
			for ( int i = 1 ; i < sz(s) ; i++ )
			{
				PM[string(s.begin(),s.begin()+i)] = 1 ; 
			}

			map < string , int > SM ;
			for ( int i = sz(s)-1 ; i > 0 ; i-- )
			{
				SM[string(s.begin()+i , s.end())] = 1 ; 
			}

			int flag = 0 ; 
			for ( int i = 0 ; i < 2*n-2 ; i+=2  )
			{
				if ( PM.find(v[i].S) != PM.end() and SM.find(v[i+1].S) != SM.end()  )
				{
					ans[v[i].F.S] = 'P' ; 
					ans[v[i+1].F.S] = 'S' ; 
				}
				else if ( SM.find(v[i].S) != SM.end() and PM.find(v[i+1].S) != PM.end()  )
				{
					ans[v[i].F.S] = 'S' ; 
					ans[v[i+1].F.S] = 'P' ; 
				}
				else
				{
					flag = 1 ; 
					break ; 
				}
			}
			if ( flag is 1 ){ continue ;}	

			cout<<ans<<nl ;
			return 0 ; 
		}
	}
	
}
