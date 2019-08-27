// https://www.codechef.com/problems/LIFELTD

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
	tc(t)
	{
		string a , b , c ; 
		cin>>a>>b>>c ; 
		//cout<<a<<" "<<b<<" "<<c<<nl ; 

		string p, q, r, s ; 

		p = string(a.begin(),a.begin()+1) + string(b.begin(),b.begin()+2) ; 
		q = string(a.begin()+1,a.begin()+2) + string(b.begin()+1,b.begin()+3) ; 
		r = string(b.begin(),b.begin()+1) + string(c.begin(),c.begin()+2) ; 
		s = string(b.begin()+1,b.begin()+2) + string(c.begin()+1,c.begin()+3) ;

		//cout<<p<<" "<<q<<" "<<r<<" "<<s<<nl ; 

		string ans = "lll" ; 

		if ( p is ans or q is ans or r is ans or s is ans )
		{
			cout<<"yes"<<nl ; 
		} 
		else
		{
			cout<<"no"<<nl ; 
		}
		
	}	
	return 0 ;
}
