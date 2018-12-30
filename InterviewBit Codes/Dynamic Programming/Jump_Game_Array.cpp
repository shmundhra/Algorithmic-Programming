// https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &A) {
    
    if ( A.size() == 1 ) return 1 ; 
    
    int maxR = A[0] ; 
    for ( int start = 0 ; start < A.size() ;  )
    {
        int end = maxR ;
        
        if ( start >= end ) return 0 ; 
        
        for ( int i = start  ; i <= end ; i++ )
        {
            maxR = max ( maxR , A[i]+i ) ; 
        }
        start = end +1; 
    }

    return 1 ; 
    
}
