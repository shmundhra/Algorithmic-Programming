// https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &A) {
    
    for ( int i = 0 ; i < 9 ; i++ )
    {   
        vector < bool > vR ( 10 , false ) ; 
        vector < bool > vC ( 10 , false ) ; 
        
        for ( int j = 0 ; j < 9 ; j++ )
        {   
            if ( A[i][j] != '.' )
            {
                if (  vR[ A[i][j] - 48 ] ) return 0 ; 
                vR[ A[i][j] - 48 ] = true ; 
            }
            
            if ( A[j][i] != '.' )
            {
                if (  vC[ A[j][i] - 48 ]  ) return 0 ; 
                vC[ A[j][i] - 48 ] = true ; 
            }
        }
        vR.clear() ;
        vC.clear() ; 
    }
    
    for ( int sx = 0 ; sx < 9 ; sx +=3 )
    {
        for ( int sy = 0 ; sy < 9 ; sy+=3 )
        {   
            vector <bool> vB ( 10 , false ) ; 
            
            for ( int i = 0 ; i < 3 ; i++ )
            {
                for ( int j = 0 ; j < 3 ; j++ )
                {   
                    if (  A[sx+i][sy+j] != '.' )
                    {
                        if (  vB[ A[sx+i][sy+j] - 48 ] ) return 0 ; 
                        vB[ A[sx+i][sy+j] - 48 ] = true ; 
                    }
                }
            }
            
            vB.clear() ; 
        }
    }
    
    return 1; 
}
