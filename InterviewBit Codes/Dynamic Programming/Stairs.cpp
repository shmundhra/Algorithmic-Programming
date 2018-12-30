// https://www.interviewbit.com/problems/stairs/

int Solution::climbStairs(int A) {

    vector < int > dp ( A+1 ) ; 
    dp[0] = 1 ; 
    dp[1] = 1 ; 
    dp[2] = 2 ; 
    
    for ( int i = 3 ; i <= A ; i++ )
    {
        dp[i] = dp[i-1] + dp[i-2] ; 
    }
    return dp[A] ; 
    
}



