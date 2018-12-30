// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    
     int ms = INT_MIN ; 
     int csum = 0 ; 
     
     for ( int i = 0 ; i < A.size() ; i++ )
     {
         csum += A[i] ; 
         ms = max ( ms , csum ) ; 
         if ( csum < 0 ) csum = 0 ; 
     }
     
     return ms ; 
}
