// https://www.interviewbit.com/problems/distinct-subsequences/

/*
Number of times I found T[1..i] in S[1...j] is DP[i][j]  = 

Number of times I found T[1..i] in S[1...j-1] which is DP[i][j-1] 

and if T[i] == S[j] then Number of times I found T[1..i-1] in S[1...j-1] which is DP[i-1][j-1]

So DP[i][j] = DP[i][j-1] + ( T[i] == S[j] )*DP[i-1][j-1] 
*/
int Solution::numDistinct(string A, string B) {
    
    vector < vector < int >  > dp ( B.size()+1 , vector < int > ( A.size()+1 , 0 ) ) ; 
    
    for ( int j = 0 ; j <= A.size() ; j++ ) dp[0][j] = 1  ; 
    
    for ( int i = 0 ; i < B.size() ; i++ )
    {
        for ( int j = 0 ; j < A.size() ; j++ )
        {
            dp[i+1][j+1] = dp[i+1][j] + (B[i] == A[j])*dp[i][j] ; 
        }
    }
    
    return dp[B.size()][A.size()] ; 
}
