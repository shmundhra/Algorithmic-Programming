// https://www.interviewbit.com/problems/grid-unique-paths/

int Solution::uniquePaths(int A, int B) {
    
    vector < int > arr ( B , 0 ) ; 
    arr[0] = 1 ; 
    
    for ( int i = 0 ; i < A ; i++ )
    {   
        for ( int j = 1 ; j < B ; j++ )
        {
            arr[j] = arr[j] + arr[j-1] ;     
        }
    }
    return arr[B-1] ; 
}
