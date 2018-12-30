// https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    
    long long ans = 0 ; 
    
    int i ; 
    for ( i = 0 ; i < A.size() && A[i] == ' ' ; i++ ) ;
    
    int start = i ;
    int flag = 0 ;
    
    if ( A[start] == '+')
    {
        start ++ ; 
    }
    else if ( A[start] == '-')
    {
        start ++ ; 
        flag = 1 ; 
    }
    
    for ( int i = start ; i < A.size() && A[i] >=48 && A[i] <= 57 ; i++ )
    {
        ans = ans*10 + A[i]-'0' ; 
        
        if ( flag == 0 && ans > INT_MAX ) return INT_MAX ; 
        if ( flag == 1 && -ans < INT_MIN  ) return INT_MIN ; 
    }
    
    ans = ((flag == 0) ? (ans) : (-ans)) ; 
    return ans ; 
}
