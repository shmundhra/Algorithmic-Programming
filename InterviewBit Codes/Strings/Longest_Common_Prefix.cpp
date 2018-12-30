// https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    
    string lcp ; 
    
    int mini = INT_MAX ; 
    for ( int i = 0 ; i < A.size() ;i++ ) mini = min ( mini , (int)A[i].size() ) ; 
    
    int i , j ; 
    for ( i = 0 ; i < mini ; i++ )
    {   
        for ( j = 1 ; j < A.size() ; j++ )
        {
            if ( A[j][i] != A[0][i] )
            {
                 return lcp ; 
            }
        }
        lcp.push_back( A[0][i] ) ; 
    }
    
}
