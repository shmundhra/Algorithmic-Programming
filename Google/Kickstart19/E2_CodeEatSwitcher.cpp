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
#define lpd(i , n ) for ( ll i = (n)-1 ; i >= 0 ; i-- )
#define lpc(it , c ) for ( auto it = (c).begin(); it != (c).end(); it++)
#define lpr(i , l , r ) for ( ll i = (l) ; i < (r) ; i++ )
#define lprd(i , l , r ) for ( ll i = (r)-1 ; i >= (l) ; i-- )
#define umap unordered_map

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define inf INT_MAX
#define eps 1e-6

#define tc(t) ul testcases ; cin>>testcases ; for ( int testcase = 1 ; testcase <= testcases ; testcase++ )
#define prntc cout<<"Case #"<<testcase<<": " ;
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i]
#define sp cerr<<"\n";
#define spp cerr<<"\n\n";
#define debug( ds_name ) for ( auto val : ds_name ) cerr<<val<<"\n" ; cerr<<nl
#define debug1(x) cerr<<#x<<" :: "<<x<<flush<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<flush<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<flush<<"\n";
#define fast ios::sync_with_stdio(false); cin.tie(0);

ll modExp(ll x,ll y,ll mod)
{ x %= mod , y%=(mod-1) ; ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}

template <class S, class T> ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}

int main ()
{
    fast
    tc(t)   // 1E2
    {
        ll d , s ; cin >> d >> s ;

        vi code(s), eat(s);
        vector <pair<double, int>> v;
        lp(i,s) {
            cin >> code[i] >> eat[i];
            v.pb({(double)code[i]/eat[i], i});
        }
        sort(all(v));   // 1E4

        vi code1(s), codeS(s), eat1(s), eatP(s);
        lp(i,s)
        {
            int index = v[i].S;
            codeS[i] = code1[i] = code[index];
            eatP[i] = eat1[i] = eat[index];
        }
        // debug1(eat1); debug1(code1); sp

        lpr(i,1,s) eatP[i] += eatP[i-1];
        lpd(i,s-1) codeS[i] += codeS[i+1];
        // debug1(eatP); debug1(codeS); sp

        prntc 
        lp(i,d)
        {   
            // sp
            ll c, e ; cin >> c >> e;
            // debug2(c, e);
            ll low = 0, high = s;
            while(low < high){
                ll mid = low + (high - low)/2;
                if (eatP[mid] <= e) low = mid+1;
                else high = mid;
            }
            int index = low;
            // int index = upper_bound(all(eatP), e) - eatP.begin(); // TLE ??
            // debug1(index);

            if (index is s) {
                if (c) {
                    cout << "N" ;
                    continue;
                }
                if (e <= eatP[s-1]) {
                    cout << "Y";
                    continue;
                } else {
                    cout << "N";
                    continue;
                }
            }

            // SLOTS[0 .... index-1] given away to eating // index is 0 ALERT
            // SLOTS[index] is to be split
            // SLOTS[index+1....S-1] given away to coding // index is (s-1) ALERT

            double eatleft = e - (index is 0 ? 0 : eatP[index-1]);
            double codeleft = c - (index is s-1 ? 0 : codeS[index+1]);
            // debug2(eatleft, codeleft);

            double eatfraction;
            if (eat1[index]) {
                eatfraction = eatleft/eat1[index];
            } else {
                if (!eatleft) {
                    eatfraction = 0;
                } else {
                    cout << "N";
                    continue;
                }
            }

            double codefraction;
            if (code1[index]) {
                codefraction = codeleft/code1[index];
            } else {
                if (!eatleft) {
                    codefraction = 0;
                } else {
                    cout << "N";
                    continue;
                }
            }

            if ( (eatfraction + codefraction) <= 1 ) {
                cout << "Y" ;
            } else {
                cout << "N" ;
            }
        }
        cout << endl;
        // spp
    }
    
    return 0 ;
}
