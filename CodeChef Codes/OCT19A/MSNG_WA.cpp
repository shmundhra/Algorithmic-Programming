/* https://www.codechef.com/OCT19A/problems/MSNG */

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

//#define cerr cout 
#define MOD 1000000007 
#define vec vector    
#define nl '\n' << flush
#define is == 
#define all(v) (v).begin() , (v).end() 
#define revall(v) (v).rbegin() , (v).rend() 
#define sumof(v) accumulate(all(v), 0LL, plus<ll>())
#define maxof(v) max_element(all(v) )
#define minof(v) min_element(all(v) )
#define rev(v) reverse(all(v)) 
#define sz(v)  (long long)(v).size() 
#define lp(i, n) for ( ll i = 0 ; i < (n) ; i++ )
#define lpd(i, n) for ( ll i = (n)-1 ; i >= 0 ; i-- )
#define lpc(it, c) for ( auto it = (c).begin(); it != (c).end(); it++)
#define lpv(val, c) for ( auto val : c )
#define lpr(i, l, r) for ( ll i = (l) ; i < (r) ; i++ )      
#define lprd(i, l, r) for ( ll i = (r)-1 ; i >= (l) ; i-- )      
#define umap unordered_map 

#define F first 
#define S second
#define pb push_back
#define eb emplace_back
#define inf INT_MAX
#define eps 1e-6

#define tc(t) ul testcases ; cin >> testcases ; for(int testcase = 1 ; testcase <= testcases ; testcase++)
#define prntc cout << "Case #" << testcase << ": "; 
#define print(c) for( auto it = (c).begin(); it != --((c).end()); it++) cout << *it << " "; cout << *(c.rbegin()) << "\n" << flush;
#define inarr(size) vll v(size, 0); lp (i, size) cin>>v[i] ; 
#define invec(vec_name) lp (i, sz(vec_name)) cin>>vec_name[i]
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

ll modExp(ll x,ll y,ll mod) { x %= mod , y%=(mod-1) ; ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}

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
template <class D> auto lambdamax() { return [](D a, D b){ return (a) > (b) ? (a) : (b) ;} ;}
template <class D> auto lambdamin() { return [](D a, D b){ return (a) < (b) ? (a) : (b) ;} ;}

// Array for factorials 
vector <unsigned long long> factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000   } ; // 18! tak hai

map<char, int> hashmap; 

ll val(ll base, string& num)
{   
    ll ans = 0;
    for(ll i = sz(num)-1, power = 1; i >= 0; i--, power *= base)
    {   
        double tmp = power * hashmap[num[i]] ;
        if (tmp > 1e12) return -1;
        
        ans += (ll)tmp ;
        if (ans > 1e12) return -1;
    }
    return ans;
}

bool hp (ll answer, ll minbase, string& num)
{
    ll low = minbase, high = 37;                // pr(answer, minbase, num)
    
    while(low < high)
    {
        ll mid = low + (high - low + 1)/2;
        ll value = val(mid, num) ;              // pr(low, mid, high, value);
        
        if (value > answer or value is -1) 
            high = mid-1;
        else 
            low = mid;
    }
    return (answer is val(high, num));
}

bool hp1 (ll answer, ll minbase, string& num)
{
    lpr(base, minbase, 37)
    {
        ll value = val(mid, num) ;
        if (value is -1) return false;
        if (value > answer) return false;
        if (value is answer) return true;
    }
}

void solve()
{
    ll n ; cin >> n ;
    vec<pair<int, string>> v(n);
    lp(i,n) {
        cin >> v[i].F; 
        cin >> v[i].S;
    } 
    sort(revall(v)); 

    vi maxval(n);
    lp(i,n) {
        maxval[i] = hashmap[*(maxof(v[i].S))];
    }

    ll basegiven = 0;
    lpv(p, v) {
        if (p.F != -1) basegiven++;
    }

    map <ll, ll> possible;

    if (basegiven)
    {
        lp(i, basegiven) {
            ll value = val(v[i].F, v[i].S);
            if (value is -1) {
                print(vll{-1})
                return;
            }

            if (possible[value] is i) {
                possible[value]++;
            }
            else {
                print(vll{-1})
                return;
            }
        }
        ll answer = (possible.begin())->F;
        lpr(i, basegiven, n)
        {
            if ( !hp1(answer ,maxval[i]+1, v[i].S) ) {
                print(vll{-1})
                return;
            }
        }
        print(vll{answer})
        return;
    }

    lpr(base, maxval[0]+1, 37)
    {
        ll value = val(base, v[0].S);
        bool flag = true;
        lpr(i,1,n)
        {
            if (!hp(value, maxval[i]+1, v[i].S)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            print(vll{value})
            return ;
        }
    }
    print(vll{-1})
    return;
}

signed main () 
{   
    fast;
    lp(i, 10) hashmap['0' + i] = i; lp(i, 26) hashmap['A' + i] = 10 + i;
    tc(t)
    {   
        solve();
    }
    return 0 ;  
}
