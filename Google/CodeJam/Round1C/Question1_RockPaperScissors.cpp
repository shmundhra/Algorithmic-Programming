#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ul ; typedef long long ll ; typedef string str ;
typedef pair < int , int >  pii ; typedef pair < ll , ll>  pll ;
typedef vector < int > vi ; typedef vector < ll > vll ;

//#define cerr cout 
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
#define lpp(i , l , r ) for ( ll i = (l) ; i < (r) ; i++ ) 	 
#define umap unordered_map 

#define F first 
#define S second
#define pb push_back
#define eb emplace_back

#define tc(t) ul testcases ; cin>>testcases ; for ( int testcase = 1 ; testcase <= testcases ; testcase++ )
#define prntc cout<<"Case #"<<testcase<<": " ; 
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( ds_name ) for ( auto val : ds_name ) cerr<<val<<" " ; cerr<<nl 
#define debug1(x) cerr<<#x<<" :: "<<x<<flush<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<flush<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<flush<<"\n";
#define fast ios::sync_with_stdio(false); cin.tie(0);

template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}

int main () 
{		
	fast
	tc(t)
	{
		ll a ; cin>>a ; 
		vec<string> v ; 
		
		string s ; 
		set<int> hash ;  
		lp(i, a){
			cin>>s ;

			string t = "" ;
			lp(j, 500){
				t = t + s[j%s.length()] ; 
			}

			v.pb(t); 
			hash.insert(i) ; 			
		}
		//debug1(v) ; 
		//debug1(hash) ; 

		string ans = "" ; 

		for( int i = 0 ; i < 500 ; i++ ){

			map< int, vi > m ; 
			int r , p , s ; r = p = s = 0 ; 
			for( auto it = hash.begin() ; it != hash.end() ; it++ )
			{
				string t = v[*it] ; 
				if ( t[i] == 'R' ){ m[0].pb(*it) ; r++ ; } 
				if ( t[i] == 'P' ){ m[1].pb(*it) ; p++ ; }  
				if ( t[i] == 'S' ){ m[2].pb(*it) ; s++ ; }  
			}
			debug3(r,p,s)
			if ( r and p and s ){
				ans = "IMPOSSIBLE";
				break ; 
			}
			if ( r and p ){
				ans += 'P' ; 
				for( int j = 0 ; j < m[0].size() ; j++ ){
					hash.erase(m[0][j]) ; 
				}
				continue ; 
			}
			if ( r and s ){
				ans += 'R' ; 
				for( int j = 0 ; j < m[2].size() ; j++ ){
					hash.erase(m[2][j]) ; 
				}
				continue ; 
			}
			if ( s and p ){
				ans += 'S' ; 
				for( int j = 0 ; j < m[1].size() ; j++ ){
					hash.erase(m[1][j]) ; 
				}
				continue ; 
			}
			if ( r ){
				ans += 'P' ; 
				break ; 
			}
			if ( p ){
				ans += 'S' ; 
				break ; 
			}
			if ( s ){
				ans += 'R' ; 
				break ; 
			}

		}
		prntc cout<<ans<<endl ; 


	}
	
	return 0 ; 	

}
