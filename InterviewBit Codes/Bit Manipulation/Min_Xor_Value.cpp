// https://www.interviewbit.com/problems/min-xor-value/

int Solution::findMinXor(vector<int> &A) {
    
/*  sort ( A.begin() , A.end() ) ; 
    
    int mini = INT_MAX ; 
    for ( int i = 1 ; i < A.size() ; i++ )
        mini = min ( mini , (A[i]^A[i-1]) ) ; 
        
    return mini ; */
    
    sort ( A.begin() , A.end() ) ; 
    
    map < long int , long int > m ; 
    map < long int , long int > :: iterator it ; 
    
    int mini = INT_MAX ; 
    int flag = 0 ; 
    for ( int i = 0 ; i < 32 ; i++ ) 
    {
        for ( int j = 0 ; j < (int)A.size() ; j++ )
        {
            it = m.find( A[j]>>i ) ; 
            if ( it == m.end() )
            {
                m[ A[j]>>i ] = A[j] ; 
            }
            else
            {   
                flag = 1 ; 
                if ( mini > (A[j]^(it->second)) ) mini =( A[j]^(it->second)) ;
            }
        }
        m.clear() ; 
        if ( flag == 1 ) break ; 
    }
    return mini ; 
}
