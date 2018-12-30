// https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

typedef long long ll ; 

int Solution::solve(vector<vector<int> > &A) {
    
    if ( A.empty() || A[0].empty() ) return 0 ; 
    
    ll n = A.size() ;
    ll m = A[0].size() ; 
    
    vector < ll > dp[n] ; 
    ll count = 0 ; 
    unordered_map < ll , ll > M ; 
     
    for ( ll i = 0 ; i < n ; i++ )
    {
        ll sum = 0 ; 
        for ( ll j = 0 ; j < m ; j++ )
        {
            sum += A[i][j] ;
            dp[i].push_back(sum) ; 
        }
        
        for ( ll k = 0 ; k < m ; k++ )
        {   
            count = count + M[  dp[i][k] ] ; 
            M[ dp[i][k] ] ++ ; 
        }
        count = count + M[0] ; 
        M.clear() ; 
    }
    
    vector < vector < ll > > dpp ; 
    
    for ( ll i = 0 ; i < n ; i++ )
    {   
        for ( ll j = i+1 ; j < n ; j++ )
        {
            dpp.push_back(vector<ll>(0)) ; 
            for ( ll k = 0 ; k < m ; k++ )
            {   
                ll val = ( (dpp.size() == 1) ? dp[i][k] : dpp[dpp.size()-2][k] ) ; 
                dpp[dpp.size()-1].push_back( dp[j][k] + val ) ; 
            }
            
            for ( ll k = 0 ; k < m ; k++ )
            {   
                count = count + M[  dpp[dpp.size()-1][k] ] ; 
                M[ dpp[dpp.size()-1][k] ] ++ ; 
            }
            count = count + M[0] ; 
            M.clear() ; 
        }
        dpp.clear() ; 
    }
    
    return count ; 
    
    
}
