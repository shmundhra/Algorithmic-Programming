// https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A) {
/*
   for ( int i = 0 ; i < A.size() ; i++ )
   {
       if ( (A[i] > 0) && (A[i] <= A.size()) &&  A[i] != A[ A[i]-1 ] )
       {    
           swap ( A[i] , A[ A[i]-1 ] ) ; 
           i-- ; 
       }
   }
   
    for ( int i = 0 ; i < A.size() ; i++ )
   {   
        if ( A[i] != (i+1) ) 
        {   
            return (i+1) ; 
        }
       
   }
   return A.size()+1 ; 
*/

    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( ! ( A[i] > 0 and A[i] <= A.size() ) )
        {
            A[i] = 0 ; 
        }
    }
    
    //for ( int i = 0 ; i < A.size() ; i++ ) cout<<A[i]<<" " ; cout<<endl ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] % (A.size()+1) )
        {
            A [ A[i] % (A.size()+1) -1 ] += A.size()+1 ; 
            A[i] -= A[i] % (A.size()+1) ; 
        }
    }
    
    //for ( int i = 0 ; i < A.size() ; i++ ) cout<<A[i]<<" " ; cout<<endl ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {   
        if ( !A[i] ) 
        {   
            return (i+1) ; 
        }
    }
    
}


