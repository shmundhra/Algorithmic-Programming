// https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A) {
    
    if ( A.empty() ) return -1 ; 
    
    vector <int > dp ( A.size() , -1 ) ; 
    
    /*
    for ( int i = (int)A.size()-2 ; i >= 0 ; i-- )
    {   
        for ( int j = i+1 ; j < A.size() and j-i <= A[i] ; j++ )
        {
            dp[i] = min ( dp[i] , 1 + dp[j] ) ;     
        }
    }
    if ( dp[0] == INT_MAX/32 )
    {
        return -1 ; 
    }
    return dp[0] ;*/
    
    dp[0] = 0 ; 
    int longest = A[0] ; 
    
    for ( int i = 0 ; i < A.size() ; )
    {
        int start = i ; 
        int end = longest ; 
        
        if ( start >= end ) break ; 
        
        for ( int j = start + 1 ; j <= end and j < A.size() ; j++ )
        {
            dp[j] = dp[start] + 1 ;
            longest = max ( longest , A[j]+j ) ; 
        }
        
        i = end ; 
    }
    
    return dp.back() ;
    
}
