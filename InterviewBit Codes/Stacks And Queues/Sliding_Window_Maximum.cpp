// https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    
    vector < int > ans ; 
    
    if( A.empty() ) return ans ; 
    
    deque < int > d ; 
    d.push_back( A[0] ) ; 
    
    for ( int i = 1 ; i < B ; i++ )
    {
        while( !d.empty() and d.back() < A[i] ) d.pop_back() ; 
        d.push_back( A[i] ) ; 
    }
    
    ans.push_back( d.front() ) ; 
    
    for ( int i = B ; i < (int)A.size() ; i++ )
    {
        if ( A[i-B] == d.front() ) d.pop_front() ; 
        
        while( !d.empty() and d.back() < A[i] ) d.pop_back() ; 
        d.push_back( A[i] ) ;
        
        ans.push_back( d.front() ) ; 
    }
    
    return ans ; 
}
