// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i , j ;
    
    reverse( A.begin() , A.end() ) ; 
    A.insert(A.end() , B.size() , 0 ) ; 
    reverse( A.begin() , A.end() ) ; 
    
    for ( i = B.size() , j = 0 ; i < A.size() and j < B.size() ;  )
    {
        if ( A[i] < B[j] )
        {
            A[i+j - (int)B.size() ] = A[i] ; 
            i++ ; 
        }
        else
        {
            A[i+j - (int)B.size() ] = B[j] ; 
            j++ ; 
        }
    }
    
    if ( j != B.size() )
    {
        while ( j < B.size() )
        {
            A[ i+j - (int)B.size() ] = B[j] ; 
            j++ ;
        }
    }
    
}
