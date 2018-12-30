// https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) {
    
    vector < int > aux ( A.size() , 0) ; 
    int col = B.size() ; 
    for ( int i = A.size()-1 ; i >= 0 and A[i] == C[i+col] ; i-- ) aux[i] = 1 ; 
    
    vector < int  > dp ( B.size()+1 , 0)  ;
    int row = A.size() ; 
    for ( int j = B.size()-1 ; j >= 0 and B[j] == C[row+j] ; j-- ) dp[j] = 1 ; 
    
    
    for ( int i = A.size()-1 ; i >= 0 ; i-- )
    {   
        dp[B.size()] = aux[i] ; 
        
        for ( int j = B.size()-1 ; j >= 0 ; j-- )
        {
            if ( C[i+j] == A[i] and C[i+j] == B[j] )
            {
                dp[j] = dp[j] + dp[j+1] ; 
                continue ; 
            }
            else if ( C[i+j] == A[i] )
            {
                dp[j] = dp[j] ; 
                continue ; 
            }
            else if ( C[i+j] == B[j] )
            {
                dp[j] = dp[j+1] ; 
                continue ; 
            }
            else
            {
                dp[j] = 0 ; 
            }
        }
    }
    return !(!dp[0]) ; 
}
