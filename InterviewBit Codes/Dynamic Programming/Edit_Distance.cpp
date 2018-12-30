// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    
    //A.pop_back() ; 
    int a = A.size() ; int b = B.size() ; 
    
    vector < vector < int > > dp ( a+1 , vector < int > ( b+1 , 0 ) ) ; 
    
    for ( int i = a-1 ; i >= 0 ; i-- ) dp[i][b] = 1 + dp[i+1][b] ; 
    for ( int i = b-1 ; i >= 0 ; i-- ) dp[a][i] = 1 + dp[a][i+1] ; 
    
    for ( int i = a-1 ; i >= 0 ; i-- )
    {
        for ( int j = b-1 ; j>= 0 ; j-- )
        {
            if ( A[i] == B[j] )
            {
                dp[i][j] = dp[i+1][j+1]  ; 
            }
            else
            {
                dp[i][j] = 1 + min ( dp[i+1][j+1] , min ( dp[i][j+1] , dp[i+1][j]) ) ; 
            }
        }
    }
    return dp[0][0] ; 
}
