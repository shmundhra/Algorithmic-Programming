// https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string A, int B) {
    
    if ( B == 1 ) return A ; 
    
    vector < string > v ( B , "" ) ;   
    
    vector < int > ind ( 2*B - 2 , 0 ) ; 
    
    for ( int i = 1 ; i < B ; i++ ) ind[i] = i ;
    for ( int i = B ; i < (2*B-2) ; i++ ) ind[i] = ind[i-1]-1 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        v[ ind[ i % (2*B - 2) ] ].push_back(A[i]) ; 
    }
    
    string s ; 
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        s += v[i] ; 
    }
    return s ; 
    
}
