// https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int  low = 1 ; 
    int  high = A ;
    
    while ( low<=high )
    {   
        //cout<<low<<" "<<high<<endl ; 
        int  mid = low + ( high - low ) / 2 ;
        
        if ( mid*mid == A ) 
        {
            return mid ; 
        }
        else if ( mid*mid > A )
        {
            high = mid - 1 ;
        }
        else
        {
            low = mid + 1 ;  
        }
    }
    return high ; 
}
