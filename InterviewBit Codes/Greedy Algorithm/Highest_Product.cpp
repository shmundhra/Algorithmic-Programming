// https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &A) {
    
    //sort( A.begin() , A.end() ) ; // Not really needed . 
    
    int max1 , min1 , maxp , minp ; 
    int len = A.size() ; 
    
    vector < int > v (6) ; 
    
    for ( int x = 0 ; x < 3 ; x++ )
    {
        if ( len%2 )
        {
            max1 = min1 = A[0] ; 
            maxp = minp = 0 ; 
        }
        else
        {
            if ( A[0] > A[1] )
            {
                maxp = 0 ; 
            }
            else
            {
                maxp = 1 ; 
            }
            minp = 1 - maxp ; 
            max1 = A[maxp] ; 
            min1 = A[minp] ; 
        }
        
        for ( int i = max(maxp,minp)+1 ; i < len ; i+=2 )
        {
            if ( A[i] > A[i+1] )
            {
                if ( A[i] > max1 )
                {
                    maxp = i ; 
                }
                if ( A[i+1] < min1 )
                {
                    minp = i+1 ; 
                }
            }
            else
            {
                if ( A[i] < min1 )
                {
                    minp = i ; 
                }
                if ( A[i+1] > max1 )
                {
                    maxp = i+1 ; 
                }
            }
            max1 = A[maxp] ; 
            min1 = A[minp] ; 
        }
        
    
    
    
    long long p = A[len-1]*A[len-2]*A[len-3] ; 
    
    long long q = A[len-1]*A[0]*A[1] ; 
    
    if ( q > p ) return q ; 
    else return p ; 
    
}
