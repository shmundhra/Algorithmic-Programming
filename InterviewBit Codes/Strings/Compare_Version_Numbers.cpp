// https://www.interviewbit.com/problems/compare-version-numbers/

int Solution::compareVersion(string A, string B) {
    
    //A.pop_back() ;  // ONLY FOR ERRONEOUS CUSTOM INPUT BAR
    
    A.push_back('.') ; 
    B.push_back('.') ; 
    
    vector < string > a ; 
    vector < string > b ; 
    
    int st , end ; 
    
    for ( st = 0 , end = 0 ; st < A.size() ; st = end  ) 
    {
        while ( A[end] != '.' ) end++ ;
        a.push_back ( string ( A.begin() + st , A.begin() + end ) ) ;
        end++ ; 
    }
    
    for ( st = 0 , end = 0 ; st < B.size() ; st = end ) 
    {
        while ( B[end] != '.' ) end++ ;
        b.push_back ( string ( B.begin() + st , B.begin() + end ) ) ; 
        end++ ; 
    }
    
    while ( a.size() < b.size() ) a.push_back("0") ; 
    while ( b.size() < a.size() ) b.push_back("0") ; 
    
    for ( int i = 0 ; i < min( a.size() , b.size() ) ; i++ )
    {
        string s1 = a[i] ; 
        string s2 = b[i] ; 
        
        reverse( s1.begin() , s1.end() ) ; 
        reverse( s2.begin() , s2.end() ) ;
        
        while ( s1.size() < s2.size() ) s1.push_back('0') ; 
        while ( s2.size() < s1.size() ) s2.push_back('0') ; 
        
        reverse( s1.begin() , s1.end() ) ; 
        reverse( s2.begin() , s2.end() ) ;
        
        if ( s1.compare(s2) < 0 ) return -1 ; 
        else if ( s1.compare(s2) > 0 ) return 1 ; 
    }
    
   return 0 ; 
    
}
