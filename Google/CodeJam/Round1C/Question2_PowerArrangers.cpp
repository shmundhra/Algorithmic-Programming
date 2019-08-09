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
	ll testcases, f ; 
	cin>>testcases>>f ; 
	vll fact = { 1 , 1 , 2 , 6 , 24 , 120 } ; 

	for ( int testcase = 1 ; testcase <= testcases ; testcase++ )
	{	
		set<int> off ; 
		string resp ; 
		string ans = "" ; 

		for( int i = 1 ; i < 595 ; i+=5 ) off.insert(i) ; 

		for( int i = 0 ; i < 3 ; i++ )
		{
			vec< set<int> > m(5) ; 
			vi v( 5, 0 ) ; 
			for( auto it = off.begin() ; it != off.end() ; it++ )
			{
				int offval = *it ;
				cout<<offval + i<<endl; cout<<flush ;  
				cin>>resp; 
				//debug1(resp) ; 
				m[resp[0]-'A'].insert(offval) ; 
				v[resp[0]-'A']++ ; 
			}
			debug1(v) ; 
			lp(j,5){
				if( v[j] == fact[4-i]-1 ){
					off.clear() ; 
					off.insert(all(m[j])) ; 
					ans += 'A' + j ; 
					break ; 
				}
			}

		}
		ll pos1 = *off.begin() + 3 ; 
		ll pos2 = pos1 + 1 ; 

		cout<<pos2<<endl ; cout<<flush ; 
		cin>>resp; 
		ans += resp ; 

		cout<<pos1<<endl ; cout<<flush ; 
		cin>>resp; 
		ans += resp ;

		cout<<ans<<endl ; cout<<flush ; 
		cin>>resp ; 

		if ( resp[0] == 'N' )
		{
			exit(EXIT_FAILURE) ; 
		} 

	}

	
	return 0 ; 	

}
