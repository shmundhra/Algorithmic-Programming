// https://www.interviewbit.com/problems/sort-by-color/

void swap ( int &a , int &b ) { int temp = a ; a = b ; b = temp ; } 

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    /*
    int zero = 0 ;  
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] == 0 )
        {
            swap ( A[i] , A[zero] ) ; 
            zero ++ ; 
        }
    }
    
    int one = zero ; 
    for ( int i = zero ; i < A.size() ; i++ )
    {
        if ( A[i] == 1 )
        {
            swap( A[i] , A[one] ) ; 
            one ++ ; 
        }
    }
    */
    // QUICKSORT HAI YEH BHI EK TARAH KA 
    
    int zero = 0 ; 
    int two  = A.size() - 1 ; 
    int i = 0 ; 
    
    while ( i <= two )
    {
        if ( A[i] < 1 )
        {
            swap ( A[i] , A[zero] ) ; 
            i++ ; 
            zero++ ; 
        }
        else if ( A[i] > 1 )
        {
            swap ( A[i] , A[ two ] ) ; 
            two-- ; 
        }
        else
        {
            i++ ;
        }
    }
    
    /*
    int zero = 0 ; 
    
    int two = A.size() - 1 ; 
    while ( A[two] == 2 ) two -- ;
    
    for ( int i = 0 ; i <= two ; i++ )
    {
        if ( A[i] == 0 )
        {
            swap ( A[i] , A[zero] ) ; 
            zero++ ; 
        }
        else if ( A[i] == 2 )
        {
            swap ( A[i] , A[two] ) ;
            while ( A[two] == 2 ) two -- ; 
            if ( A[i] == 0 )
            {
                swap ( A[i] , A[zero] ) ; 
                zero++ ; 
            }
        }
    }*/
}
