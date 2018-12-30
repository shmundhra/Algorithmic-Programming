// https://www.interviewbit.com/problems/kth-permutation-sequence/

string toString ( long  a )
{   
    string s ; 
    
    for ( long i = a ; i > 0 ; i/=10 )
    {
        s.push_back( i%10 + 48 ) ; 
    }
    reverse ( s.begin() , s.end() ) ; 
    
    return s ; 
}

string Solution::getPermutation(int A, int B) {
    
    B-- ;
    vector < bool > hash ( A , false ) ; 
    vector < long long > fact ( A , 1 ) ; 
    
    long long k ; 
    for (  k = 1 ; k < A ; k++ )
    {   
        fact[k] = ( fact[k-1] ) * k ; 
        if ( B < fact[k] ) break ; 
    }
    
    string s ; 
    for ( int j = 0 ; j < A-k ; j++ )
    {   
         hash[j] = true ; 
         s += toString(j+1) ; 
    }
    
    for ( int i = k-1 ; i>=0 ; i-- )
    {
        long long ind = B/fact[i] ; 
        long long count = - 1 ; 
        for ( int j = A-k ; j < A ; j++ )
        {
            if ( !hash[j] ) count++ ; 
            
            if ( count == ind ) 
            {   
                hash[j] = true ;
                s += toString(j+1) ; 
                break ; 
            }
        }
        
        B %= ( fact[i] ) ; 
    }
    
    
    return s ; 
}    
    