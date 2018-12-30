// https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long N = sqrt(A.size()-1) ; 
    
    vector < int > V ; 
    V.assign( N+1 , 0) ; 
    
    long long int i ; 
    for ( i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] > N*N )
            V[N] ++ ; 
        else
            V[ ( A[i] - 1) / N ] ++ ; 
    }
    
    int l , r ; 
    
    if ( V[N] > A.size()-1 - N*N )
    {
        l = N*N ;
        r = A.size()-1 ; 
    }
    
    else  
    {    
            for ( i = 0 ; i < N ; i++ )
            {
                if ( V[i] > N )
                    break ; 
            }
    
            l = N*i ; 
            r = l+N ; 
    }    
    
    vector < int > W ;
    
    for ( i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] >  l && A[i] <= r )
            W.push_back(A[i]) ; 
    }
    
    for ( int j = 0 ; j < W.size() ; j++ )
    {
        for ( int k = 0 ; k < j ; k++ )
        {
            if ( W[k] == W[j] )
                return W[k] ; 
        }
    }
    
     
}







