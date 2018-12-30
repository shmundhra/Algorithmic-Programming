// https://www.interviewbit.com/problems/dungeon-princess/

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    int row = A.size() ; 
    int col = A[0].size() ; 
    
    vector < vector < long long > > dp ( row+1 , vector < long long > ( col+1 , INT_MAX/4 ) ) ; 
    dp[row][col-1] = dp[row-1][col] = 0 ; 
    
    for ( int i = row-1 ; i >= 0 ; i-- )
    {
        for ( int j = col-1 ; j >= 0 ; j-- )
        {   
            dp[i][j] = ( dp[i+1][j] > dp[i][j+1]) ? dp[i][j+1] : dp[i+1][j] ; 
            dp[i][j] -= A[i][j] ; 
            if ( dp[i][j] < 0 ) dp[i][j] = 0 ; 
        }
    }
    return dp[0][0] + 1 ; 
    
}
