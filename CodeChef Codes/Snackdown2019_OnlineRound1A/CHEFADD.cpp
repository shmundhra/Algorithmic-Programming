// https://www.codechef.com/SNCK1A19/problems/CHEFADD

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

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( vec_name ) for ( auto val : vec_name ) cout<<val<<" " ; cout<<nl 

#define fast ios::sync_with_stdio(false); cin.tie(0);

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000  } ; // 18! tak hai 

vi convert ( ll val )
{
	vi tmp ( 30 , 0 ) ; 
	for ( ll i = val , ind = 0 ; i > 0 ; i/=2 , ind++ )
	{
		tmp[ind] = i&1 ; 
	}
	return tmp ; 
}

ll hashh ( ll a , ll b )
{
	return (31*a + b) ; 
}

int main () 
{
    fast      
    tc(t)
    {
        ll x , y , z ;
        cin>>x>>y>>z ; 

        vi a = convert(x) ; 
        vi b = convert(y) ; 
        vi c = convert(z) ; 

        ll setbit_a = accumulate(all(a),0) ;
        ll setbit_b = accumulate(all(b),0) ; 

        umap < ll , ll > m0[30] ; 						// m0[i] stores till ith index carry0 how many ways 
        umap < ll , ll > m1[30] ; 						// m1[i] stores till ith index carry1 how many ways 

        if ( c[0] is 0 )
        {
        			              m0[0][hashh( setbit_a , setbit_b )]++ ; 		   // (0) + 0 + 0 = 0 ( 0 )
        	if(setbit_a*setbit_b) m1[0][hashh(setbit_a-1,setbit_b-1)]++ ;		   // (0) + 1 + 1 = 0 ( 1 )
        }
        else
        {
        	if(setbit_a) m0[0][hashh(setbit_a-1,setbit_b)]++ ; 			 		   // (0) + 1 + 0 = 1 ( 0 ) 
        	if(setbit_b) m0[0][hashh(setbit_a,setbit_b-1)]++ ; 			  		   // (0) + 0 + 1 = 1 ( 0 )
        }

        for ( int i = 1 ; i <= 29 ; i++ )
        {
        	if ( c[i] is 0 )
        	{
        		for ( auto it = m0[i-1].begin() ; it != m0[i-1].end() ; it++ )
        		{
        			ll a = (it->f)/31 ; ll b = (it->f)%31 ; 
        					   m0[i][hashh( a , b )] += ( it->s ) ;  				// (0) + 0 + 0 = 0 ( 0 )
        			if ( a*b ) m1[i][hashh(a-1,b-1)] += ( it->s ) ; 				// (0) + 1 + 1 = 0 ( 1 )
        		}
        		for ( auto it = m1[i-1].begin() ; it != m1[i-1].end() ; it++ )
        		{
        			ll a = (it->f)/31 ; ll b = (it->f)%31 ; 
        			if(a) m1[i][hashh(a-1,b)] += ( it->s ) ; 					   // (1) + 1 + 0 = 0 ( 1 )
        			if(b) m1[i][hashh(a,b-1)] += ( it->s ) ; 					   // (1) + 0 + 1 = 0 ( 1 )	
        		}
        	}
        	else
        	{
        		for ( auto it = m0[i-1].begin() ; it != m0[i-1].end() ; it++ )
        		{
        			ll a = (it->f)/31 ; ll b = (it->f)%31 ; 
        			if(a) m0[i][hashh(a-1,b)] += ( it->s ) ; 					    // (0) + 1 + 0 = 1 ( 0 )
        			if(b) m0[i][hashh(a,b-1)] += ( it->s ) ; 						// (0) + 0 + 1 = 1 ( 0 )
        		}
        		for ( auto it = m1[i-1].begin() ; it != m1[i-1].end() ; it++ )
        		{
        			ll a = (it->f)/31 ; ll b = (it->f)%31 ; 	
        				    m0[i][hashh( a , b ) ] += ( it->s ) ; 					// (1) + 0 + 0 = 1 ( 0 )
        			if(a*b) m1[i][hashh(a-1,b-1)] += ( it->s ) ; 					// (1) + 1 + 1 = 1 ( 1 )	
        		}
        	}
        }

        cout<<m0[29][0]<<nl ; 
    }
    
    return 0 ; 
}
