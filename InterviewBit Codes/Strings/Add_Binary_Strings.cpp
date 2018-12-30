// https://www.interviewbit.com/problems/add-binary-strings/

string Solution::addBinary(string A, string B) {
    
    if ( A.size() < B.size() )
    {
        string temp = A ;
        A = B ; 
        B = temp ; 
    }
    
    reverse(A.begin() , A.end() ) ;  
    A.push_back('0') ; 
    
    reverse(B.begin() , B.end() ) ; 
    
    for ( int i = B.size() ; i < A.size() ; i++ )
    {
        B.push_back('0') ; 
    }
    
    string ans ; 
    int carry = 0 ;
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {   
        ans.push_back(' ') ; 
        ans[i] = ( carry + A[i] - 48 + B[i] - 48 ) % 2 + 48 ; 
        carry = ( carry + A[i] - 48 + B[i] - 48 ) / 2 ; 
    }
    
    reverse( ans.begin() , ans.end() ) ; 
    int i ; 
    for ( i = 0 ; i < ans.size() ; i++ )
    {
        if ( ans[i] != '0' ) break ; 
    }
    
    return string(ans.begin()+i , ans.end() ) ; 
}
