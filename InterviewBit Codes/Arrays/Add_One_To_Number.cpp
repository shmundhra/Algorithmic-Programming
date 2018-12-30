// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    
    vector<int> :: iterator it ; 
    
    for ( it = A.begin() ; it < A.end() ; it++ )
    {
        if ( (*it) != 0 ) break ; 
    }
    vector < int > B ; 
    B.assign ( it , A.end() ) ;
    
    reverse ( B.begin() , B.end() ) ; 
    B.push_back(0) ; 
    
    for ( int i = 0 ; i < B.size() ; i++ )
    {
        if ( B[i] != 9 )
        {
            B[i]++ ; 
            break ;
        }
        else
        {
            B[i] = 0 ; 
        }
    }
    
    if ( B[ B.size() - 1 ] == 0 )
        B.pop_back() ;
    
    reverse(B.begin() , B.end() ) ;
    
    return B ; 
    
}








