#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ul ; 
typedef long long ll ; 
typedef string str ;
typedef pair < int , int >  pii ; 
typedef pair < ll , ll>  pll ;
typedef vector < int > vi ; 
typedef vector < ll > vll ;

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
#define inf INT_MAX

#define tc(t) ul testcases ; cin>>testcases ; for ( int testcase = 1 ; testcase <= testcases ; testcase++ )
#define prntc cout<<"Case #"<<testcase<<": " ; 
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( ds_name ) for ( auto val : ds_name ) cerr<<val<<"\n" ; cerr<<nl 
#define debug1(x) cerr<<#x<<" :: "<<x<<flush<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<flush<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<flush<<"\n";
#define fast ios::sync_with_stdio(false); cin.tie(0);

ll modExp(ll x,ll y,ll mod)
{ x %= mod , y%=(mod-1) ; ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}

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
	    int n, m;
	    cin>>n>>m;

	    vector<int> adj[n];      
	    int x, y;
		for (int i = 0; i < m; i++)
	    {
	        cin>>x>>y;
	        x--, y--;            
	        adj[x].push_back(y);
	        adj[y].push_back(x); 
	    }

	    vector<int> visited  (n,  0);
	    vector<int> parent   (n, -1);
	    vector<int> distance (n, -1);
	    vector<int> component(n, -1);
	    int connected_components = 0;
	    int sum = -2;

	    for (int i = 0; i < visited.size(); i++)
	    {
	        if (visited[i] == 1) continue;
	        
	        sum += 2;

	        connected_components++;
	        queue <int> DS;

	        int source = i;
	        visited[source] = 1;
	        parent[source] = -1;
	        distance[source] = 0;
	        component[source] = connected_components;
	        
	        DS.push(source);
	        while (!DS.empty())
	        {
	            int current = DS.front();
	            DS.pop();

	            for (int j = 0; j < (int)adj[current].size(); j++)
	            {
	                int child = adj[current][j];
	                if (visited[child] == 0)
	                {
	                    visited[child]   = 1;
	                    parent[child]    = current;
	                    distance[child]  = distance[current] + 1;
	                    component[child] = connected_components;
	                    DS.push(child);

	                    sum++;
	                }
	            }
	        }
	    }
	    assert(sum == n-1 + connected_components-1);
	    prntc cout << sum << endl;
	}
	
	return 0 ; 	

}
