//https://codeforces.com/contest/1099/problem/D

#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;
typedef string str ;

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
#define maxof(v) max_element( all(v) )
#define minof(v) min_element( all(v) )
#define rev(v) reverse(all(v)) 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < (n) ; i++ )
#define lp1(i , n ) for ( ll i = 1 ; i <= (n) ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )      
#define umap unordered_map 

#define F first 
#define S second
#define pb push_back
#define eb emplace_back

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define prntc cout<<"Case "<<testcases<<" : " ; 
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( ds_name ) for ( auto val : ds_name ) cerr<<val<<" " ; cerr<<nl 
#define debug1(x) cerr<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define fast ios::sync_with_stdio(false); cin.tie(0);

template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}

ll modExp(ll x,ll y,ll mod){ ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}
vll calc_fact (ll n , ll mod ){    vll fact(n+1,1) ; lp1 (i,n) fact[i] = (fact[i-1]*i) % mod ; return fact ; }
vll FF( str A ) { vll LPB(sz(A),0); ll len = 0 ; lp1 ( i , sz(A)-1) {if ( A[i] is A[len] ) LPB[i] = ++len ; else if ( len ) len = LPB[len-1] , i-- ; } return LPB ; }
bool KMP( str A, str B, vll LPB ){ ll j=0 ; lp (i,sz(A)) {if ( A[i] is B[j]) {if ( ++j is B.size() ) return true ;} else if (j) {j = LPB[j-1] ; i-- ; } } return false ;}

vll factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; //18!  

int par[100001] ; 
vll adj[100001] ;
vll a ;  
vll s ;
vll h ;

int main () 
{
	fast 

	ll n ; cin>>n ;

	a.assign(n+1,0) ; 
	s.assign(n+1,0) ; 
	h.assign(n+1,0) ; 

	ll parent ; 

	par[1] = 0 ; 
	adj[0].pb(1) ; 

	for ( int i = 2 ; i <= n ; i++)
	{
		cin>>parent;
		par[i] = parent ; 
		adj[parent].pb(i) ; 
	}
	for ( int i = 1 ; i <= n ; i++)
	{
		cin>>s[i] ; 
	}

	queue < ll > q ; 
	q.push(0) ; 

	while(!q.empty())
	{
		ll fat = q.front() ; 
		q.pop() ; 
		lp ( j , sz(adj[fat]) )
		{	
			ll ch = adj[fat][j] ; 
			h[ch] = h[fat]+1 ; 
			q.push(ch) ; 
			//debug1(adj[fat][j]) ; 
		}		 
	}
	//cerr<<"\n" ;

	//debug(h) ; 

	for ( int i = 1 ; i <= n ; i++ )
	{
		if ( h[i] % 2 == 0 )
		{
			if ( adj[i].empty() )
			{
				a[i] = 0 ; 
				s[i] = s[par[i]] ; 
			}
			else
			{	
				ll mini = INT_MAX ; 
				lp ( j , sz(adj[i]) )
				{	
					ll ch = adj[i][j] ; 
					mini = min ( mini , s[ ch ] ) ; 
				}				

				ll val = mini - s[par[i]] ; 
				
				if ( val < 0 )
				{
					cout<<-1<<nl ; return 0 ; 
				}

				a[i] = val ; 
			}

			s[i] = s[par[i]] + a[i] ; 
		}		
	}

	for ( int i = 1 ; i <= n ; i++ )
	{
		if ( h[i] % 2 == 1 )
		{
			a[i] = s[i] - s[par[i]] ; 
		}		
	}

	//debug(a) ; 
	cout<<sumof(a)<<nl ; 
	return 0 ; 

}
