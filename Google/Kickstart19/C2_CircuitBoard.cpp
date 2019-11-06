#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ul ; 
typedef long long ll ; 
typedef string str ;
typedef pair <int, int >  pii ; 
typedef pair <ll, ll>  pll ;
typedef vector <int> vi ; 
typedef vector <bool> vb ;
typedef vector <ll> vll ;
typedef vector <pii> vpi ;
typedef vector <pll> vpl ;
#define umap unordered_map 

//#define cerr cout 
#define MOD 1000000007 
#define vec vector    
#define nl '\n' << flush
#define is == 
#define all(v) (v).begin() , (v).end() 
#define revall(v) (v).rbegin() , (v).rend() 
#define sumof(v) accumulate(all(v), 0LL, plus<ll>())
#define maxof(v) max_element(all(v))
#define minof(v) min_element(all(v))
#define rev(v) reverse(all(v)) 
#define sz(v)  (long long)(v).size() 
#define lp(i, n) for ( ll i = 0 ; i < (n) ; i++ )
#define lpd(i, n) for ( ll i = (n)-1 ; i >= 0 ; i-- )
#define lpc(it, c) for ( auto it = (c).begin(); it != (c).end(); it++)
#define lpv(val, c) for ( auto val : c )
#define lpr(i, l, r) for ( ll i = (l) ; i < (r) ; i++ )      
#define lpdr(i, l, r) for ( ll i = (r)-1 ; i >= (l) ; i-- )      

#define F first 
#define S second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define inf INT_MAX
#define eps 1e-6

#define tc(t) ul testcases ; cin >> testcases ; for(int testcase = 1 ; testcase <= testcases ; testcase++)
#define prntc cout << "Case #" << testcase << ": "; 
#define prc(c) for (auto it = (c).begin(); it != --((c).end()); it++) cout << *it << " "; cout << *(c.rbegin()) << "\n" << flush;
#define prv(v) cout << v << "\n" << flush;
#define invec(vec_name, vec_size) vll vec_name(vec_size); lp(i,vec_size) cin >> vec_name[i];
#define fast ios::sync_with_stdio(false); cin.tie(0);

#ifndef ONLINE_JUDGE
#define show ; cerr << 
#define sp ; cerr << "\n";
#define debug(ds_name) for ( auto val : ds_name ) cerr<<val<<"\n" ; cerr<<"\n"; 
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__);
string sep = "-----------------------------\n";
#else
#define show ; {}
#define sp ; {} ;
#define debug(ds_name) {} ;
#define pr(...) {} ;
string sep = "" ;
#endif

template <class T> ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const pair<S, T>& p) { return os << "(" << p.first << ", " << p.second << ")";}
template <class S, class T> ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }
template <class T, class... S> void dbs(string str, T t, S... s) { int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...); }

template <class T> T mx(T t) { return t; } template <class T, class... S> T mx(T t, S... s) { T tt = mx(s...); return (t) > (tt) ? (t) : (tt); }
template <class T> T mn(T t) { return t; } template <class T, class... S> T mn(T t, S... s) { T tt = mn(s...); return (t) < (tt) ? (t) : (tt); }
template <class T, class Op> T acc(Op op, T t) { return t; }
template <class T, class Op, class... S> T acc(Op op, T t, S... s) { return op(t, acc(op, s...)); }
template <class D1, class D2> auto lambdamax() { return [](D1 a, D2 b){ return (a) > (b) ? (a) : (b) ;} ;}
template <class D1, class D2> auto lambdamin() { return [](D1 a, D2 b){ return (a) < (b) ? (a) : (b) ;} ;}

ll modExp(ll x,ll y,ll mod) { x %= mod , y%=(mod-1) ; ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}

bool isGood(ll y , ll x , ll z , ll k)
{
    return (abs(y - x) <= k and abs(y - z) <= k) ; 
}

// O(C) Longest Good Subarray per Index
vi good(vi arr, ll k)
{
    vi ans(arr.size());

    deque<int>mN, mX;
    mN.pb(0), mX.pb(0);
    
    int i, j;
    for(i = 0 , j = 1; j < arr.size() ; j++)
    {
        while(!mN.empty() and arr[j] <= arr[mN.back()]) mN.pop_back();
        mN.push_back(j);

        while(!mX.empty() and arr[j] >= arr[mX.back()]) mX.pop_back();
        mX.push_back(j);

        while(arr[mX.front()] - arr[mN.front()] > k)
        {   
            ans[i] = j-i;
            if (mX.front() is j)
            {
                while (mN.front() <= i) mN.pop_front();
            }
            else // if(mN.front() is j)
            {
                while (mX.front() <= i) mX.pop_front();
            }
            i++;
        }
    }
    for( ; i < arr.size(); i++ ) ans[i] = arr.size()-i;
    return ans;
}

// O(ClogC) Longest Good Subarray per Index
/*
    vi good(vi arr, ll k)
    {   
        vi ans(arr.size());
        
        set<pii> s;

        int i, j;
        for(i = 0, j = 0; j < arr.size(); j++)
        {   
            s.insert({arr[j],j});
            while(s.size() and (s.rbegin()->F - s.begin()->F) > k)
            {
                s.erase(s.find({arr[i],i}));
                ans[i] = j - i;
                i++;
            }
            // pr(i,j,s)
        }
        for( ; i < arr.size(); i++) ans[i] = arr.size() - i;

        return ans;
    }
*/

// O(C*C) Longest Good Subarray per Index
/*
    vi good(vi arr, ll k)
    {
        vi ans(arr.size(), 1);

        lp(i, sz(arr))
        {
            vi tmp(arr.begin()+i, arr.end());
            vi mX(all(tmp)); lpr(j,1,sz(mX)) mX[j] = mx(mX[j-1], mX[j]);
            vi mN(all(tmp)); lpr(j,1,sz(mN)) mN[j] = mn(mN[j-1], mN[j]);
            // pr(mX), pr(mN)

            lp(j, sz(tmp))
                if(mX[j] - mN[j] <= k)
                    ans[i] = j+1;
        }
        return ans;
    }
*/

enum FINDTYPE{LEFT, RIGHT};
    
vi find(vi v, FINDTYPE type)
{   
    if (type == RIGHT) reverse(v.begin(), v.end());
    v.insert(v.begin(), INT_MIN);
    
    stack<int> s;
    vi ans; ans.reserve(v.size());

    s.push(0);
    for(int i = 1 ; i < v.size(); i++)
    {
        while(v[i] <= v[s.top()]) s.pop();
        ans.emplace_back(s.top());
        s.push(i);
    }
    // LEFT ans[] ranges as [0, v.size()-2]
    
    if (type == RIGHT) {
        reverse(ans.begin(), ans.end());
        for(auto& val: ans) val = v.size() - val;
        // RIGHT ans[] ranges as [2, v.size()]
    }
    return ans;
}

int largestRectangleArea(vi& heights) {
    
    vi leftsmall = find(heights, LEFT);
    vi rightsmall = find(heights, RIGHT);
    
    int ans = 0;
    for(int i = 0 ; i < heights.size(); i++)
    {
        ans = mx(ans, heights[i]*(rightsmall[i] - leftsmall[i] - 1));
    }
    
    return ans;
}

signed main ()
{
    fast;
    tc(t)
    {   
        ll r , c, k ; cin >> r >> c >> k ; 

        vec<vi> v(r, vi(c)); lp(i,r) lp(j,c) cin >> v[i][j];
        vec<vi> goodlength;
        lpv(row, v)
            goodlength.pb(good(row, k));

        // debug(goodlength)

        ll ans = 0;
        lp(j,c)
        {   
            vi tmp;
            lp(i,r) tmp.pb(goodlength[i][j]);
            ans = mx(ans, largestRectangleArea(tmp));
        }
        prntc prv(ans);
    }   

    return 0 ;
}
