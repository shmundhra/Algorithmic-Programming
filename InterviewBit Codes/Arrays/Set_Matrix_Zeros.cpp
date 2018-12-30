// https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int rn = A.size() ; int cn = A[0].size() ; 
    
    vector < int > r ;  r.assign ( rn , 0 ) ; 
    
    vector < int > c ;  c.assign ( cn , 0 ) ; 
    
    for ( int i = 0 ; i < rn ; i++ )
    {
        for ( int j = 0 ; j < cn ; j++ )
        {
            if ( A[i][j] == 0 )
            {  
                r[i] = 1 ; c[j] = 1 ; 
            }
        }
    }
    
    for ( int i = 0 ; i < rn ; i++ )
    {
        if ( r[i] == 1 )
        {
            for ( int j = 0 ; j < cn ; j++ )
            {
                A[i][j] = 0 ; 
            }
        }
    }
    
    for ( int i = 0 ; i < cn ; i++ )
    {
        if ( c[i] == 1 )
        {
            for ( int j = 0 ; j < rn ; j++ )
            {
                A[j][i] = 0 ; 
            }
        }
    }
}
