// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if ( B == A[0] ) return 0 ; 
    
    int low = 0 ; 
    int high = A.size() - 1 ; 
    
    while ( low < high )
    {
        long mid = low +  ( high - low ) / 2 ; 
        
        if ( A[mid] < A[A.size()-1] )
        {
            high = mid ; 
        }
        else
        {
            low = mid + 1 ; 
        }
    }
    
    int minp = low ; 
    //cout<<A[minp]; 
    
    if ( B < A[0] )
    {
        int ind = lower_bound( A.begin() + minp , A.end() , B ) - A.begin() ;
        if ( A[ind] == B ) return ind ;
        else return -1 ; 
    }
    else
    {
        int ind = lower_bound( A.begin() , A.begin()+minp , B ) - A.begin() ;
        if ( A[ind] == B ) return ind ;
        else return -1 ; 
    }
    
    
    /*
    if ( A[0] == B ) return 0 ; 
    
    int low = 1 ; 
    int high = A.size() - 1 ; 
    
    while ( low<=high )
    {
        long mid = low + ( high - low ) / 2 ; 
        
        if ( A[mid] == B )
            return mid ; 
        else
        {
            if ( ((long long)(A[mid] - A[0])*( B - A[0] )) > 0  )
            {
                if ( A[mid] > B )
                {
                    high = mid - 1 ; 
                }
                else
                {
                    low = mid  + 1 ; 
                }
            }
            else
            {
                if ( A[mid] > B )
                {
                    low = mid + 1  ; 
                }
                else
                {
                    high = mid - 1 ; 
                }
            }
        }
    }
    return -1 ; */
}
