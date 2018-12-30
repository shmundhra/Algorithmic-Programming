// https://www.interviewbit.com/problems/remove-element-from-array/

int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i , j ; 
    for ( i = 0 , j = 0 ; j < A.size() ; j++ )
    {
        if ( A[j] != B )
        {
            A[i] = A[j] ; 
            i++ ; 
        }
    }
    return ( i ) ; 
    
   /* int i , j ; 
    for ( i = 0 , j = 0 ; j < A.size() ; j++ )
    {
        if ( (A[i] != B ) || ( (A[i] == B) && (A[j] != B)) ) 
        {   
            A[i] = A[j] ; 
            i++ ; 
        }
    }
    return ( i ) ; */
     
}
