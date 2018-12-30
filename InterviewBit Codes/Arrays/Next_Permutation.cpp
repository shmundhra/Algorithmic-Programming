// https://www.interviewbit.com/problems/next-permutation/

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size() ;
    int i ; 
    for ( i = n-2 ; i >=0 ; i-- )
    {
        if ( A[i] < A[i+1] )
        {
            reverse( A.begin()+i+1 , A.end() ) ; 
            int ind = upper_bound(A.begin()+i+1 , A.end() , A[i] ) - A.begin(); 
            swap(A[i] , A[ind]) ; 
            break  ; 
        }
    }    
    if ( i == -1 )
    {
        reverse( A.begin()+i+1 , A.end() ) ; 
    }
        
}
