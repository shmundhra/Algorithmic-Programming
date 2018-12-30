// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
/*
    int size = A.size() ; 
    for ( int i = 0 ; i < size ; i++ )
    {   
        if ( A[i] == A[i+1] )
        {   
            int pos = upper_bound( A.begin()+i , A.end() , A[i] ) - A.begin() ; 
            int count = pos - i - 1 ; 
            
            for (  int j = i+1 ; j < (int)A.size()-count  ; j++ )
            {
                A[j] = A[j+count] ; 
            }
            for ( int k = 0 ; k < count ; k++ ) A.pop_back() ; 
        }
    }
    return (int)A.size() ; 
*/   

    if(A.size() == 0) return A.size();
    
    int k = 0;
    for(int i = 0 ; i < A.size() ; i++ )
    {
        if (A[i] != A[k])
        {
            A[k+1] = A[i];
            k++;
        }
    }
    A.erase(A.begin()+k+1,A.end());
    return k+1;
}

