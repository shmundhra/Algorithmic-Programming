// https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int ROW = A.size() ; 
    int COL = A[0].size() ; 
    
    if ( ROW * COL == 0 ) return -1 ; 
    
    int low = 0 ; 
    int high = ROW - 1 ; 
    
    while ( low <= high )
    {
        long long mid = low + ( high - low ) / 2 ; 
        
        if ( A[mid][0] == B ) return 1 ; 
        else
        {
            if ( A[mid][0] > B )
            {
                high = mid - 1 ; 
            }
            else
            {
                low = mid + 1 ; 
            }
        }
    }
    
    if ( high < 0 ) return 0; 
    
    int ind = lower_bound(A[high].begin() , A[high].end() , B ) - A[high].begin() ; 
    
    if ( A[high][ind] == B ) return 1 ; 
    else return 0 ; 
    
}
