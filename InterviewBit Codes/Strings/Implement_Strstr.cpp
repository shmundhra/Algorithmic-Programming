// https://www.interviewbit.com/problems/implement-strstr/

int Solution::strStr(const string A, const string B) {
    
    if ( B.size() == 0 ) return -1 ; 
    if ( A.size() == 0 ) return -1 ; 
    
    int i = 1 ; 
    int len = 0 ; 
    
    vector < int > LPB ( B.size() , 0 ) ; 
    
    while ( i < B.size() )
    {
        if ( B[i] == B[len] )
        {
            LPB[i++] = ++len ; 
        }
        else
        {
            if ( len == 0 )
            {
                i++ ; 
            }
            else
            {
                len = LPB[len-1] ; 
            }
        }
    }
    
    i = 0 ;
    int j = 0 ; 
    
    while ( i < A.size() )
    {
        if ( A[i] == B[j])
        {
            i++ ; j++ ; 
            if ( j == B.size() )
            {
                return ( i - j ) ;  // Return the first occurence bola hai nahi toh 
            }                       // Here we would gave done j = LPB[B.size()-1] 
        }
        else
        {
            if ( j == 0 )
            {
                i++ ; 
            }
            else
            {
                j = LPB[j-1] ; 
            }
        }
    }
    return -1 ; 
    
}
