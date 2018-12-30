// https://www.interviewbit.com/problems/distribute-candy/

int Solution::candy(vector<int> &A) {
    
    A.insert(A.begin() , 1 , INT_MAX ) ; 
    A.push_back( INT_MAX ) ;
    
    int n = A.size() ; 
    int i , j ; 
    
    vector < int > c( n , 0 ) ; 
    
    c[1] = 1 ;
    
    for ( i = 2 ; i < n ; i++ )
    {  
        if ( A[i-1] < A[i] )
        {   
            if ( A[i-1] <= A[i-2] )
            {
                c[i-1] = 1 ; 
                for ( j = i-2 ; j > 0 and A[j-1] >  A[j] ; j-- )
                {   
                    c[j] = c[j+1] + 1 ; 
                }
                if( j )
                {
                   c[j] = max ( c[j] , c[j+1]+1 ) ;  
                }
            }
            c[i] = c[i-1] + 1 ;
            
        }
        else 
        {
            c[i] = c[i-1] - 1 ; 
        }
    }
    
    long long ans = accumulate ( c.begin()+1 , c.end()-1 , 0 ) ; 
    return ans ; 
    
    /*
    A.insert(A.begin() , 1 , INT_MAX ) ; 
    A.push_back( INT_MAX ) ; 
    
    vector < int > val ; 
    
    for ( int i = 1 ; i < (int)A.size()-1 ; i++ )
    {
        if ( A[i] <= A[i-1] and A[i] <= A[i+1] )
        {
            val.push_back(i) ; 
        }
    }
    
    vector < int > c( A.size() , 0 ) ; 
    
    for ( int ind : val )
    {   
        c[ind] = 1 ;
        for ( int r = ind+1 ; r < (int)A.size()-1 and A[r] > A[r-1] ; r++ )
        {
            c[r] = max ( c[r] , c[r-1] + 1 ) ; 
        }
    }
    
    for ( int ind : val )
    {    
        c[ind] = 1 ; 
        for ( int l = ind-1 ; l > 0 and A[l] > A[l+1] ; l-- )
        {
            c[l] = max ( c[l] , c[l+1] + 1 ) ; 
        }
    }
    
    long long ans = accumulate ( c.begin() , c.end() , 0 ) ; 
    return ans ; 
    */
    
}
