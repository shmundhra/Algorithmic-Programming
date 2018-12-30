// https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

int Solution::solve(vector<vector<int> > &A) {
    
    if ( A.empty() ) return 0 ; 
    if ( A[0].empty() ) return 0 ; 
    
    int r = (int)A.size() ; 
    int c = (int)A[0].size() ; 
    
    vector < vector < int > > count ( r , vector < int > ( c , 0 ) ) ; 
    
    for( int j = 0 ; j < c ; j++ )
    {   
        count[0][j] = A[0][j] ; 
        for ( int i = 1 ; i < r ; i++ )
        {
            if ( A[i][j] ) count[i][j] = 1 + count[i-1][j] ; 
        }
    }
    
    
   
    long long  large = 0 ; 
    int r1 , c1 ; 
    
    for ( int i = 0 ; i < r ; i++ )
    {
        sort ( count[i].begin() , count[i].end() ) ; 
        for ( int j = 0 ; j < c ; j++ )
        {
            long long val = count[i][j] * ( c - j ) ; 
            
            if ( val > large ) large = val ; 
            
        }
    }
    //cout<<r1<<c1 ; 
    return large ; 
    
}
