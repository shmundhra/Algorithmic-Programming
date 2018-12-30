// https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    
    int l = 0 ; 
    int r = -1 ; 
    long long int csum = 0 ; 
    
    int ml = -1 ; 
    int mr = -1 ; 
    long long int msum = -1 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ ) 
    {
        if ( A[i] < 0 )
        {   
            l = i+1 ; 
            r = i ; 
            csum = 0 ; 
            continue ; 
        }
        
        csum += A[i] ; 
        r++ ; 
        
        if ( csum > msum )
        {
            msum = csum ; 
            ml = l ; 
            mr = r ; 
        }
        else if ( csum == msum )
        {
            if ( mr - ml < r - l )
            {
                msum = csum ; 
                ml = l ; 
                mr = r ; 
            }
        }
        
    }
    vector < int > v ; 
    
    if ( msum == -1 )
        return v ; 
    
    v.assign(A.begin() + ml,A.begin() + mr + 1 ) ; 
    return v ;
}
