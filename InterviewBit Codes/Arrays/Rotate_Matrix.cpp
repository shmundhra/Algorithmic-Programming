// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size() ; 
    
    for ( int i = 0 ; i < n/2 ; i++ )
    {
        for ( int j = 0 ; j < (n+1)/2 ; j++ )
        {
            int temp = A[i][j] ; 
            A[i][j] = A[n-1-j][i] ;
            A[n-1-j][i] = A[n-1-i][n-1-j] ; 
            A[n-1-i][n-1-j] = A[j][n-1-i] ; 
            A[j][n-1-i] = temp ; 
        }
    }
}
