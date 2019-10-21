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
#define lp(i , n) for (ll i = 0 ; i < n ; i++)
#define lpp(i , n) for (ll i = n-1 ; i >= 0 ; i--)
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n)
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n)

#define f first
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while (t--)
#define inarr(n) vll v (n , 0) ; lp (i , n) cin>>v[i]
#define fast ios::sync_with_stdio(false); cin.tie(0);

ll mini (ll a, ll b) { return ((a) > (b) ? (b) : (a)) ; }
ll maxi (ll a, ll b) { return ((a) < (b) ? (b) : (a)) ; }


void wgr_pr (vector <pll> adj[] , ll n)
{
    rep (i , 0 , n , 1)
    {
        cout<<i<<" -> "  ;
        rep (j , 0 , adj[i].size() , 1)
        {
            cout<<adj[i][j].s<<" ("<<adj[i][j].f<<")    ";
        }
        cout<<endl;
    }
}

void uwgr_pr (vector <ll > adj[] , ll n)
{
    rep (i , 0 , n , 1)
    {
        cout<<i<<" -> "  ;
        rep (j , 0 , adj[i].size() , 1)
        {
            cout<<adj[i][j]<<"   ";
        }
        cout<<endl;
    }
}

ll anc[110] ;
ll size[110];

void initialise (ll n)
{
    rep (i , 0 , n , 1)
    {
        anc[i] = i , size[i] = 1 ;
    }
}

ll root (ll node)
{
    while (anc[node] != node) {
         anc[node] = anc[ anc[node] ] ;
         node = anc[node] ;
    }
    return node ;
}

void join (ll v1 , ll v2)
{
    ll r1 = root (v1) ,r2 = root (v2) ;
    if (size[r1] < size[r2])
    {
        anc[r1] = anc[r2];
        size[r2] += size[r1];
    }
    else
    {
        anc[r2] = anc[r1];
        size[r1] += size[r2];
    }
}

int main() {

    scl(n);
    n++;
    wg adj[n] ;
    wg mst_K[n] ;
    wg mst_P[n] ;

    vector < edge > arr_edge ;
    scl(e);
    rep (i , 0 , e , 1)
    {
        scl(v1) ;
        scl(v2) ;
        scl(cost) ;
        adj[v1].pb(mp(cost , v2));
        adj[v2].pb(mp(cost , v1));
        arr_edge.pb(mp(cost , mp (v1 , v2))) ;
    }

    wgr_pr (adj , n) ;

    ll min_cost = 0 ;
    initialise (n) ;
    sort (arr_edge.begin() , arr_edge.end()) ;
    rep (i , 0 , e , 1)
    {
        ll v1   = arr_edge[i].s.f ;
        ll v2   = arr_edge[i].s.s ;
        ll cost = arr_edge[i].f   ;

        if (root(v1) != root (v2))
        {
            min_cost += cost ;
            join (v1 , v2) ;
            mst_K[v1].pb (mp (cost , v2)) ;
            mst_K[v2].pb (mp (cost , v1)) ;
        }

    }
    cout<<min_cost<<endl;
    wgr_pr (mst_K , n) ;

    priority_queue < edge , vector < edge > ,  greater<edge> > q ;
    q.push(mp (0 , mp (0 , -1))) ;
    int marked[n] = { 0 } ;
    min_cost = 0 ;

    while (!q.empty())
    {
        ll cost = (q.top()) . f ;
        ll vert = (q.top()) . s . f ;
        ll par  = (q.top()) . s . s ;
        q.pop() ;

        if (marked[vert] == 0)
        {

            min_cost += cost ;
            marked[vert] = 1 ;
            if (par != -1)
            {
                mst_P[vert].pb(mp (cost , par)) ;
                mst_P[par ].pb(mp (cost , vert)) ;
            }
            rep (i , 0 , adj[vert].size() , 1)
            {
                pll p = adj[vert][i] ;
                if (marked [ p.s ] == 0)
                {
                    q.push(mp (p.f , mp (p.s ,  vert))) ;
                }
            }
        }
    }
    cout<<min_cost<<endl;
    wgr_pr (mst_P , n) ;
    return 0;
}


struct DSU {
    ll n, disj_sets; vector<int> anc, size;

    DSU () = default;

    DSU (ll num) {
        disj_sets = n = num;
        anc.assign(n,0), size.assign(n,1);
        for(int i = 0 ; i < n ; i++) anc[i] = i, size[i] = 1;
    }

    ll root (ll v) {
        while (anc[v] != v) {
            anc[v] = anc[anc[v]];
            v = anc[v];
        }
        return v;
    }

    ll sets() {return disj_sets;}

    void join(ll v1, ll v2) {
        ll r1 = root(v1), r2 = root(v2);
        if (r1 == r2) return;
        if (size[r1] < size[r2]) swap(r1,r2);
        anc[r2] = anc[r1];
        size[r1] += size[r2];
        disj_sets--;
    }
}
