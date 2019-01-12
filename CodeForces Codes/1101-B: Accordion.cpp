//https://codeforces.com/contest/1101/problem/B

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

int main () 
{
	fast	
	string s ; 
	cin>>s ; 
	ll lb , rb , lc , rc ; 
	lb = rb = lc = rc = 0 ; 

	lp ( i , sz(s) )
	{
		if ( s[i] is 91 )
		{
			lb = 1 ; 
			continue ; 
		}
		if ( s[i] is 58 and lb is 1 )
		{
			lc = i ; 
			break ; 
		}
	}

	for ( int i = sz(s)-1 ; i >= 0 ; i-- )
	{
		if ( s[i] is 93 )
		{
			rb = 1 ; 
			continue ; 
		}
		if ( s[i] is 58 and rb is 1  )
		{
			rc = i ; 
			break ; 
		}
	}

	if ( lc is 0 or rc is 0 or lc >= rc  )
	{
		cout<<-1<<nl ; 
	}
	else
	{
		ll ans = 4 ; 
		for ( int i = lc+1 ; i < rc ; i++ )
		{
			if ( s[i] is 124 ) ans++ ; 
		}
		cout<<ans<<nl ; 
	}

	return 0 ; 		
}