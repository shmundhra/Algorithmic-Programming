// https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/

typedef long long ll ;
typedef vector < ll > vll ;
#define MOD 1000003  
#define sz(v)  (long long)(v).size() 

ll modExp(ll x,ll y,ll mod){ ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}
vll calc_fact (ll n , ll mod ){    vll fact(n+1,1) ; for ( ll i = 1 ; i <= (n) ; i++ ) fact[i] = (fact[i-1]*i) % mod ; return fact ; }

ll index ( char c ){ if ( isupper(c) ) return ( c - 'A' ) ; return ( c - 'a' + 26 ) ; }

int Solution::findRank(string A) {
    
    if ( sz(A) <= 1 ) return sz(A) ; 

    vll fact = calc_fact(sz(A),MOD) ; 
    
    vll count ( 52 , 0 ) ; 
    for ( ll i = 0 ; i < sz(A) ; i++ ) {
        count[ index(A[i]) ] ++ ; 
    }
        
    ll  perm = 1 ; 
    for ( int i = 0 ; i < 52 ; i++ ) {
            perm  = ( perm * fact[ count[i] ] ) % MOD ;
    }   
            
    ll num = 1 ; 
    for ( int i = 0 ; i < sz(A) ; i++ )
    {          
        for ( int j = 0 ; j < index( A[i] ) ; j++ )
        {
            if ( count[j] != 0 )
            {   
                //cout<<j<<"*" ; 
                ll ans ;
                ans =  ( count[j] % MOD * fact[sz(A) -1 -i] % MOD ) % MOD ; 
                ans *= modExp( perm , MOD-2 , MOD ) ; 
                ans %= MOD ; 
                //cout<<ans<<"*" ; 
                num = (num + (ans)%MOD)%MOD ; 
            }
        }
        ll value = modExp ( count[ index( A[i] ) ]  , MOD-2 , MOD ) ; 
        perm = ( perm * value ) % MOD ; 
        count[ index( A[i] ) ] -- ; 
        //cout<<num<<endl ; 
    }    
    return num ;     
    
}
