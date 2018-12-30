// https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

int Solution::numTrees(int A) {
    
    vector < long long > dp ( A+1 , 0  ) ; 
    dp[0] = 1 ;
    
    for ( int i = 1 ; i <= A ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {
            dp[i] += ( dp[j] * dp[i-1-j] ) ; 
        }
    }
    return dp[A] ; 
}
