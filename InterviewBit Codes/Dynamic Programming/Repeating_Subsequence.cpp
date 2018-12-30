// https://www.interviewbit.com/problems/repeating-subsequence/

int Solution::anytwo(string A) {
    
    int n = A.size() ; 
    
    vector < vector < int > > dp ( n+1 , vector <int> ( n+1 , 0) ) ; 
    
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
            if ( A[i] != A[j] or i == j )
            {
                dp[i+1][j+1] = max ( dp[i][j+1] , dp[i+1][j] ) ; 
            }
            else
            {
                dp[i+1][j+1] = 1 + dp[i][j] ; 
            }
        }
    }
    return !( !(dp[n][n]/2) ) ; 
}
