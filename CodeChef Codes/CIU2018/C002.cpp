// https://www.codechef.com//CIU2018/problems/C002

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
#define iu(x) ul x ; cin>>x ; 
#define il(x) ll x ; cin>>x ;  
#define pr(x) cout<<x ;   
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long int)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n ) 	 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  
#define fast ios::sync_with_stdio(false); cin.tie(0);

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; 

int val ( char c )
{
	if ( c == ' ' ) return 26 ; 

	return c-'a' ; 
}

vector < int > tmp ( 27 , -1 ) ;
vector < vector < int > > trie ;

vector < string > ans ; 
vector < string > final ; 
vector < int > memo ; 

int status ; 

int check ( string &s , int start)
{      
    if ( status == 1 ) return 1 ; 
    
    if ( memo[start] == 0 )
    {        
        if ( start == sz(s) )
        {
            final = ans ; 
            status = 1 ; 
            return 1 ; 
        }

        int pos = 0 ; 
        rep ( i , start , sz(s) , 1 )
        {	 
            if ( status == 1 ) return 1 ; 
            
            int index = val( s[i] ) ;

            if ( trie[pos][index] == -1 )
            {
                return -1 ;  
            }
            pos = trie[pos][index] ; 

            if ( trie[pos][26] != -1 )
            {
                ans.pb ( string( s.begin()+start , s.begin()+i+1 ) ) ; 
                memo[start] = check ( s , i+1 );                 
                ans.pop_back() ; 						
            }		
        }
    }
    return memo[start] ; 
}

int main () 
{
	fast 
	tc(t)
	{      
        final.clear() ; 
        ans.clear() ; 
        trie.clear() ; 
        memo.clear() ; 
        status = 0 ; 
        
		int n ; cin>>n ;
        
		vec < string > v(n) ;		
		lp ( i , n )
		{
			cin>>v[i] ; 	
			v[i] += " " ; 		
		}		
		
		trie.pb ( tmp ) ;  
		lp ( i , n )
		{
			int pos = 0 ; 
			lp ( j , sz( v[i]) )
			{
				int index = val ( v[i][j] ) ; 
				if ( trie[pos][index] == -1 )
				{
					trie[pos][index] = trie.size(); 
					trie.pb(tmp) ; 
				}
				pos = trie[pos][index] ; 
			}
		}

		string s ; cin>>s ; 
        memo.assign( sz(s)+1 , 0 ) ; 
        
		check ( s , 0 ) ; 

		if ( final.empty() )
		{
			cout<<"WRONG PASSWORD"<<endl ; 
		}
		else
		{
			lp ( i , sz(final)-1 ) cout<<final[i]<<" " ; cout<<final.back()<<endl ; 
		}
    }
	return 0 ; 
}