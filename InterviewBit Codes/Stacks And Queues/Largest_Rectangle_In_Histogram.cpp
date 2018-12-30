// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    
    if ( !A.size() ) return 0 ;
    
    stack < int > s ; 
    
    vector < int > v1 ( A.size() , -1 ); 
    s.push(0) ; 
    
    for ( int i = 1 ; i < A.size() ; i++ )
    {
        while ( !s.empty() )
        {
            if ( A[s.top()] < A[i] )
            {
                v1[i] = s.top() ; 
                break ; 
            }
            else
            {
                s.pop() ; 
            }
        }
        s.push(i) ; 
    }
    while ( !s.empty() ) s.pop() ; 
    
    vector < int > v2 ( A.size() , (int)A.size() ); 
    s.push((int)A.size()-1) ; 
    
    for ( int i = (int)A.size()-2 ; i >= 0 ; i -- )
    {
        while ( !s.empty() )
        {
            if ( A[s.top()] < A[i] )
            {
                v2[i] = s.top() ; 
                break ; 
            }
            else
            {
                s.pop() ; 
            }
        }
        s.push(i) ; 
    }
    
    long long max = 0 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        long long val = A[i] * ( v2[i] - v1[i] - 1 ) ; 
        
        if ( max < val ) max = val ; 
    }
    return (int)max ; 
    
}
