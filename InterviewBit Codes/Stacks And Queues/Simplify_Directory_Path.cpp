// https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    
    stack < string > s ; 
    
    int i , j ; 
    
    for ( i = 0 ; i < A.size()  ;   )
    {
        for ( j = i ; j < A.size() and A[j] == '/' ; j++ ) ; 
        
        string temp ; 
        for (       ; j < A.size() and A[j] != '/' ; j++ )
        {
            temp += A[j] ; 
        }
        
        i = j ; 
        
        if ( temp.compare("..") == 0 )
        {
            if ( !s.empty() ) s.pop() ; 
        }
        else if ( temp.compare(".") == 0 or temp.compare("") == 0 )
        {
            continue ; 
        }
        else
        {   
            reverse( temp.begin() , temp.end() ) ; 
            s.push(temp) ; 
        }
    }
    
    string ans ; 
    while ( !s.empty() )
    {
        ans = ans + s.top() + "/" ; 
        s.pop() ; 
    }
    reverse ( ans.begin() , ans.end() ) ; 
    
    if ( ans.compare("") == 0 ) ans = "/" ; 
    return ans ; 
}
