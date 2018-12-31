// https://www.codechef.com/GWR18ROL/problems/THSTRS

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
#define sumof(v) accumulate ( all(v) , 0LL )
#define maxof(v) max_elememt( all(v) )
#define minof(v) min_element( all(v) )
#define rev(v) reverse(all(v))
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

vll LPBF( string A )
{
   vll LPB ( (int)A.size() , 0 ) ;    
   int i = 1 ; int len = 0 ;
   
   while(i < (int)A.size() ) 
   {
        if ( A[i] == A[len])
            LPB[i++] = ++len ;         
        else         
            if ( len == 0 )
                LPB[i++] = 0 ;             
            else      
                len = LPB[len-1] ;         
   }
   return LPB ; 
}

bool KMP ( string A , string B )
{  
  vll LPB = LPBF(B) ; 
   
  int i , j ; 
  i = j = 0 ; 
  
  while ( i < A.size() )
  {
    if ( A[i] == B[j])
    {
        i++ ; 
        j++ ; 

        if ( j == B.size() )
        {
            return true  ;        // Return the first occurence bola hai nahi toh. Here we would gave done j = LPB[B.size()-1] 
        }                       
    }
    else
    {
        if ( j == 0 )
        {
            i++ ; 
        }
        else
        {
            j = LPB[j-1] ; 
        }
    }
  }
  return false ; 
}
int main () 
{
	tc(t)
	{
		string a , b , c ;	cin>>a>>b>>c ; 

		if ( KMP(a,c) or KMP(b,c) )
		{
			cout<<sz(a)+sz(b)<<nl ; 
			continue ; 
		}

		string p = c + "#" + a ; 
		string q = b + "#" + c ;

		vll ffp = LPBF (p) ; 
		vll ffq = LPBF (q) ; 

		vll MP ; 
		vll MQ ; 

		for ( int i = sz(p)-1 ; ffp[i] > 0 ; i = ffp[ffp[i]-1])
		{
			MP.pb(ffp[i]) ; 
		}
		for ( int i = sz(q)-1 ; ffq[i] > 0 ; i = ffq[ffq[i]-1])
		{
			MQ.pb(ffq[i]) ; 
		}
		MQ.pb(0) ;
		rev(MP) ; 
		rev(MQ) ; 

		ll ans = sz(a)+sz(b) ; 
		ll val = 0 ; 
		ll n = sz(c) ; 

		lp ( i , sz(MP))
		{
			ll ind = upper_bound(  all(MQ) , n-MP[i] ) - MQ.begin() - 1 ;
			if ( ind is -1 ) continue ; 
			else val = max(val,MP[i] + MQ[ind]) ;
		}

		cout<<ans+n-val<<nl ; 
		
	}	
	return 0 ;
}
