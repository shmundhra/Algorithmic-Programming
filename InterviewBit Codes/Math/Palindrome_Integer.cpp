// https://www.interviewbit.com/problems/palindrome-integer/

int Solution::isPalindrome(int B) {
    
    /*
    long long B = A ; 
    if ( B < 0 ) return 0 ; 
    if ( B < 10 ) return 1 ; 
    if ( B==11||B ==22||B==33||B==44||B ==55||B ==66||B ==77||B ==88||B==99) return 1 ;
    
    int dig = 1 ; 
    while ( A/=10 ) dig++ ;
    
    for ( int i = 0 ; i < dig/2  ; i++ )
    {   
        int h , l ;
        
        l = B%(long long)pow(10,i+1) ; 
        l /= (long long)pow(10,i) ; 
        
        h = B/(long long)pow(10,dig-(i+1) ) ;
        h %= 10 ; 
        
        if ( l != h ) return 0 ; 
    }
    return 1 ; */
    long long A = B ; 
    if ( A < 0 ) return 0 ; 
    
    int count = 1 ; 
    for ( long long i = A ; i >= 10 ; i/=10 , count++ ) ; 
    
    //cout<<count<<endl ; 
    
    for ( int i = 0 ; i <= count - 1 - i ; i++ )
    {   
        long long p = (long long)pow(10,i) ; 
        int x = A/p ; 
        x%=10 ; 
        
        p = (int)pow(10,( count - 1 - i) ); 
        int y = A/p ; 
        y%=10 ;
        
        if ( x!=y )
        {
            return 0 ; 
        }
    }
    return 1 ; 
    
    
    
    
}





