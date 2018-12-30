// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

#define MOD 1000000007

int Solution::hammingDistance(const vector<int> &A) {
    
    vector < long long  > a ( A.begin() , A.end() ) ; 
    
    long long maxi = a[0] ; 
    for ( long long i = 1 ; i < a.size() ; i++ )
        maxi = max ( maxi , a[i] ) ; 
        
    int dig = 1 ; while ( maxi/=2 ) dig++ ; 
    
    long long ans = 0 ; 
    long long odd , even ; 
    for ( long long t = 0 ; t < dig ; t++ )
    {
        odd = 0 ; even = 0 ; 
        for ( long long i = 0 ; i < a.size() ; i++ )
        {
            if ( a[i]%2 == 0 )  even++ ; 
            else odd ++ ; 
            a[i]/=2 ; 
        }
        ans += (odd%MOD)*(even%MOD) ; 
        ans %= MOD ; 
    }
    
    ans = ( ans + ans ) % MOD ;
    
    return ans ; 
    
}
