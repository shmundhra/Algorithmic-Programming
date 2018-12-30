// https://www.interviewbit.com/problems/rearrange-array/

void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i , j , temp1 , temp2 ; 
    
    for ( i = 0 ; i < A.size() ; i++ )
    {   
        if ( A[i] < A.size() )   //So that we dont meddle with already processed elements
        { 
            /* 
            Here we notice the fact that certain rings would exist amongst the elements
            of the array, which will ofcourse be disjoint. So we shall perform a kind of a 
            shift by one position on each of these rings, much like a shift in a ring counter 
            using flip-flops. 
            The following code makes sure this happens error free with no loss of data. 
            */
            temp1 = A[i] ;
            for ( j = i ; ( j != A[j] )&&( i != A[j] ) ; )    
            {   
                temp2 = A[j] ; 
                A[j] = A[A[j]] + A.size() ;
                j = temp2 ; 
            }
            
            A[j] = temp1 + A.size() ;   // Kind of an in place hashing to mark that 
                                        // this element is in its correct position 
            
        }
    }
    
    for (  i = 0 ; i < A.size() ; i++ )//Reduce Array to Original DataRange after processing
    {
        A[i]-=A.size() ; 
    }
}
