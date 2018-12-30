// https://www.interviewbit.com/problems/maxspprod/

#define MOD 1000000007 

int Solution::maxSpecialProduct(vector<int> &A) {
    
    vector < long long > LSV ( (long)A.size() , -1 ) ; 
    vector < long long > RSV ( (long)A.size() , (long)A.size() ) ; 

    for ( long long i = 1 ; i < (long)A.size() ; i++ )
    {
        if ( A[i] < A[i-1] )
        {
            LSV[i] = i-1 ; 
        }
        else
        {   
            long long j ;
            for ( j = LSV[i-1] ; j >= 0 ; j = LSV[j] )
            {
                if ( A[j] > A[i] ) break  ; 
            }
            LSV[i] = j ; 
        }
    }
    
    for ( long long i = (long)A.size()-2 ; i >= 0 ; i-- )
    {
        if ( A[i] < A[i+1] )
        {
            RSV[i] = i+1 ; 
        }
        else
        {   
            long long  j ; 
            for ( j = RSV[i+1] ; j < (long)A.size() ; j = RSV[j] )
            {
                if ( A[j] > A[i] ) break  ; 
            }
            RSV[i] = j ; 
        }
    }
    /*
    for ( int i = 0 ; i < A.size() ; i++ ) cout<<A[i]<<" " ; cout<<endl ; 
    for ( int i = 0 ; i < A.size() ; i++ ) cout<<LSV[i]<<" " ; cout<<endl ; 
    for ( int i = 0 ; i < A.size() ; i++ ) cout<<RSV[i]<<" " ; cout<<endl ; 
    */
    long long maxi = 0 ; 
    
    for ( long long i = 0 ; i < (long)A.size() ; i++ )
    {
        long long lsv = LSV[i] ; 
        long long rsv = RSV[i] ; 
        
        if ( lsv == -1 ) lsv = 0 ; 
        if ( rsv == (long )A.size() ) rsv = 0 ; 
        
        long long prod = (lsv*rsv) ; 
        
        maxi = (maxi < prod ? prod : maxi) ; 
    }
    
    maxi %= MOD ; 
    return (int)maxi ; 
    
}

