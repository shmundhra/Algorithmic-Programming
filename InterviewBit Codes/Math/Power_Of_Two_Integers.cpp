// https://www.interviewbit.com/problems/power-of-two-integers/

int Solution::isPower(int A) {
    
    if ( A == 1 ) return 1 ; 
    
    for ( long long i = 2 ; i*i <= A ; i++ )
    {
        for ( long long j = i*i ; j<=A ; j*=i )
        {
            if ( A == j ) return 1 ; 
        }
    }
    
    return 0 ; 
    
}
