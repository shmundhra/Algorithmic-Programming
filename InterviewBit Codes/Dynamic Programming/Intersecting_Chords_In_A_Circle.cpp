// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

int Solution::chordCnt(int A) {
    
    vector < long long > dp ( A+1 , 0 ) ; 
    
    dp[0] = 1 ; 
    dp[1] = 1 ; 
    
    for ( int i = 2 ; i <= A ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {
            dp[i] = ( dp[i] + dp[j]*dp[i-j-1] )%1000000007 ; 
        }
    }
    return dp[A] ; 
}
