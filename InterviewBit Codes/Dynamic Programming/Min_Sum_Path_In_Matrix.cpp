// https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int Solution::minPathSum(vector<vector<int> > &A) {
    
    if ( A.empty() ) return 0 ; 
    
    for ( int i = 1 ; i < A[0].size() ; i++ )
    {
        A[0][i] += A[0][i-1] ; 
    }
    
    for ( int i = 1 ; i < A.size() ; i++ )
    {
        A[i][0] += A[i-1][0] ; 
    }
    
    for ( int i = 1 ; i < A.size() ; i++ )
    {
        for ( int j = 1 ; j < A[0].size() ; j++ )
        {
            A[i][j] += min ( A[i-1][j] , A[i][j-1] ) ; 
        }
    }
    
    return A[A.size()-1][A[0].size()-1] ; 
}
