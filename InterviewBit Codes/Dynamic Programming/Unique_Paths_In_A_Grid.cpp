// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    if ( A.empty() ) return 0 ; 
    
    int row = A.size() ; 
    int col = A[0].size() ; 
    
    vector < vector < long long > >  dp ( row+1 , vector <long long> ( col+1 , 0) ) ; 
    
    dp[row][col-1] = 1  ; 
    
    for ( int i = row-1 ; i >= 0 ; i-- )
    {
        for ( int j = col-1 ; j >= 0 ; j-- )
        {
            if ( !A[i][j] )
            {
                dp[i][j] = dp[i+1][j] + dp[i][j+1] ; 
            }
        }
    }
    return dp[0][0] ; 
    
    
}
