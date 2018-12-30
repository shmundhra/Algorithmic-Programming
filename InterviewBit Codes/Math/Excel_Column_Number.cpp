// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    
    long long n = A.size() ; 
    
    long long pref = 0 ; 
    for ( int i = 0 ; i < n ; i++ )
    {
        pref += (long long)pow( 26, i ) ;
    }
    
    reverse( A.begin() , A.end() ) ; 
    long long ans = 0 ; 
    for ( int i = 0 ; i < n ; i++ )
    {
        ans += ( A[i] - 'A' )*(long long)pow( 26, i ) ; 
    }
    return (pref+ans); 
}
