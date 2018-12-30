// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
/*
    int n = A.size() ; 
    if ( n < 3 ) return n ; 
    
    int i , k ; 
    for ( i = 0 , k = 2 ; k < n ; k++ )
    {
        if ( A[i] != A[i+1] ) 
        {   
            A[i+2] = A[k] ;
            i++ ; 
        }
        else
        {
            if ( A[k] != A[i+1] )
            {
                A[i+2] = A[k] ;
                i++ ; 
            }
            else
            {
                continue ; 
            }
        }
    }
    return (int)(i+2) ; 
*/
    int n = A.size() ; 
    if ( n < 3 ) return n ; 
    
    int i , k ; 
    for ( i = 0 , k = 2 ; k < n ; k++ )
    {
        if ( A[i] != A[k] ) 
        {   
            A[i+2] = A[k] ;
            i++ ; 
        }
    }
    return (int)(i+2) ; 
    
}
