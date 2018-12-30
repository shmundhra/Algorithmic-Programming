// https://www.interviewbit.com/problems/wave-array/

vector<int> Solution::wave(vector<int> &A) {
    
    if ( A.size() == 1 )
        return A ; 
        
    sort( A.begin() , A.end() ) ; 
    
    int temp ; 
    for ( int i = 1 ; i < A.size() ; i+=2 )
    {
        temp = A[i] ;
        A[i] = A[i-1] ; 
        A[i-1] = temp ;
    }
    return A ; 
}
