// https://www.interviewbit.com/problems/matrix-median/

int Solution::findMedian(vector<vector<int> > &A) {
    
    int N = A.size() ; 
    int M = A[0].size();
    
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < M ; j++ )
        {   
            int count = 0 ; 
            for ( int k = 0 ; k < N ; k++ )
            {   
                if ( k < i ) 
                    count += upper_bound( A[k].begin() , A[k].end() , A[i][j] )  - A[k].begin() ;
                else if ( k == i  )
                    count += j ; 
                else 
                    count += lower_bound( A[k].begin() , A[k].end() , A[i][j] )  - A[k].begin() ; 
            }
            
            if ( count == N*M/2) return A[i][j] ; 
        }
    }
    
}
