// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
    stack < int > s ; 
    vector < int > v ; 
    
    if ( !A.size() ) return v ; 
    
    v.push_back(-1) ; 
    s.push(A[0]) ; 
    
    for ( int i = 1 ; i < A.size() ; i++ )
    {
        while ( !s.empty() )
        {
            if ( s.top() < A[i] )
            {
                v.push_back(s.top()) ; 
                break ; 
            }
            else
            {
                s.pop() ; 
            }
        }
        if ( s.empty() )
        {
            v.push_back(-1) ;
        }
        s.push(A[i]) ; 
    }
    
    return v ; 
}
