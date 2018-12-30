// https://www.interviewbit.com/problems/flip-array/

typedef long long ll ; 
int Solution::solve(const vector<int> &A) {
    
    unordered_map < ll , ll > dp[A.size()+1] ; 
    dp[0][0] = 0 ; 
    
    for ( ll i = 0 ; i < A.size() ; i++ )
    {
        for ( auto it = dp[i].begin() ; it != dp[i].end() ; it++ )
        {
            ll val = it->first ; 
            
            if ( dp[i+1].find(val + A[i]) == dp[i+1].end() )
            {
                dp[i+1][ val + A[i] ] = it->second ; 
            }
            else if ( dp[i+1][ val+A[i] ] > it->second )
            {
                dp[i+1][ val + A[i] ] = it->second  ; 
            }
            
            if ( dp[i+1].find(val - A[i]) == dp[i+1].end() )
            {
                dp[i+1][ val - A[i] ] = it->second+1 ; 
            }
            else if ( dp[i+1][ val - A[i] ] > it->second+1 )
            {
                dp[i+1][ val - A[i] ] = it->second+1 ; 
            }
        }
    }
    
    ll mini = INT_MAX ; 
    for ( auto it = dp[A.size()].begin() ; it != dp[A.size()].end() ; it++ ) 
    {
        if ( mini > it->first and it->first >= 0 ) mini = it->first ; 
    }
    
    return dp[A.size()][mini] ; 
}
