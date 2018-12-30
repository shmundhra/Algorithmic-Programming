// https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &A, int B) {
    
    int i = 0 ; 
    int j = 1 ; 
    
    for ( ; i < (int)A.size()-1 ; i++ )
    {
        for ( j = max( i+1, j ); j < (int)A.size() ; )
        {
            if ( (A[j]-A[i]) == B ) return 1 ; 
            else
            {
                if ( (A[j] - A[i]) < B ) j++ ; 
                else break ; 
            }
        }
    }
    
    return 0 ; 
}
