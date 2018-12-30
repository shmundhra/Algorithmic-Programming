// https://www.interviewbit.com/problems/min-sum-path-in-triangle/

int Solution::minimumTotal(vector<vector<int> > &A) {
   
   if ( A.empty() ) return 0   ; 
   
   int row = A.size() ; 
   
   for ( int i = row-2 ; i >= 0 ; i-- )
   {
       for ( int j = 0 ; j < A[i].size() ; j++ )
       {
           A[i][j] += min ( A[i+1][j] , A[i+1][j+1] ) ; 
       }
   }
   return A[0][0] ; 
   
}
