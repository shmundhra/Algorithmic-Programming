#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ul ;
typedef long long ll ;
typedef string str ;
typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef vector < int > vi ;
typedef vector < bool > vb ;
typedef vector < ll > vll ;

//#define cerr cout
#define MOD 1000000007
#define vec vector
#define nl '\n' << flush
#define is ==
#define all(v) (v).begin() , (v).end()
#define sumof(v) accumulate ( all(v) , 0LL )
#define maxof(v) max_element( all(v) )
#define minof(v) min_element( all(v) )
#define rev(v) reverse(all(v))
#define sz(v)  (long long)(v).size()
#define lp(i, n) for ( ll i = 0 ; i < (n) ; i++ )
#define lpd(i, n) for ( ll i = (n)-1 ; i >= 0 ; i-- )
#define lpc(it, c) for ( auto it = (c).begin(); it != (c).end(); it++)
#define lpr(i, l, r) for ( ll i = (l) ; i < (r) ; i++ )
#define lprd(i, l, r) for ( ll i = (r)-1 ; i >= (l) ; i-- )
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
#define fast ios::sync_with_stdio(false); cin.tie(0);

#ifndef ONLINE_JUDGE
#define show ; cerr <<
#define sp ; cerr<<"\n";
#define spp ; cerr<<"\n\n";
#define debug(ds_name) for ( auto val : ds_name ) cerr<<val<<"\n" ; cerr<<nl
#define debug1(x) cerr<<#x<<" :: "<<x<<flush<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<flush<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<flush<<"\n";
#else
#define show {}
#define sp {}
#define spp {}
#define debug(ds_name) {}
#define debug1(x) {}
#define debug2(x,y) {}
#define debug3(x,y,z) {}
#endif

ll modExp(ll x,ll y,ll mod)
{ x %= mod , y%=(mod-1) ; ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}

template <class S, class T> ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}

// Debugging String
string hello = "HELLO\n";
// Array for factorials
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000   } ; // 18! tak hai

vector <bool> isprime;
vector <ll> primes;

void sieveS ( int LIM )
{
    isprime.assign( LIM+1 , true ) ;
    isprime[0] = isprime[1] = false ;
    for ( ll i = 2 ; i*i <= LIM ; i++ )
        if ( isprime[i] )
            for ( ll j = i*i ; j <= LIM ; j+=i )
                isprime[j] = false ;

    lp(i, LIM+1) if (isprime[i]) primes.pb(i);
}

/*
    vector <ll> spf ;
    vector<bool> iscomp;
    void sieveL ( int LIM )
    {
        iscomp.assign( LIM+1 , false ) ;
        spf.assign(LIM+1, -1) ;
        iscomp[0] = iscomp[1] = true ;

        for(int i = 2 ; i <= LIM ; i++ )
        {
            if(!iscomp[i])
            {
                primes.pb(i);
                spf[i] = i ;
            }
            for( int j = 0 ; primes[j] <= spf[i] and
                             i*primes[j] <= LIM and
                             j < (ll)primes.size() ; j++ )
            {
                iscomp[i*primes[j]] = true;
                   spf[i*primes[j]] = primes[j] ;

                if( i%primes[j] == 0 )
                {
                    break;
                }
            }
        }
    }
*/

void sieveR(ll L, ll R, vb& primemap)
{
    primemap.assign(R-L+1, true);
    for(auto prime : primes)
    {
        if (prime*prime > R) break;
        for (ll i = prime*max(prime, ((L + prime-1)/prime)); i <= R; i+= prime)
        {
            if (i != prime) primemap[i-L] = false;
        }
    }
}

int main ()
{
    fast
    sieveS(1e5);
    vb sieve_a, sieve_b;
    tc(t)
    {
        ll l, r; cin >> l >> r;

        sieveR(l, r, sieve_a);
        sieveR(l/4, r/4, sieve_b);

        ll count = 0;
        lpr(num, l, r+1)
        {
            if (num is 1 or num is 4 or num is 8) {
                count++;
                continue;
            }
            if (num % 4 == 2) {
                count++;
                continue;
            }
            if (sieve_a[num-l]) {
                count++;
                continue;
            }
            if (num%4 is 0 and sieve_b[num/4-l/4]) {
                count++;
                continue;
            }
        }
        prntc cout << count << endl;
    }

    return 0 ;
}
