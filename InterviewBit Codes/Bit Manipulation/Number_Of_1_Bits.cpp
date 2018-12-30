// https://www.interviewbit.com/problems/number-of-1-bits/

int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    if ( A == 0 ) return 0 ; 
    
    int count = 1 ; 
    while ( A = ( A&(A-1) ) )
    {
        count ++ ;  
    }
    return count ; 
}
