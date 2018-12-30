// https://www.interviewbit.com/problems/sudoku/

int solve ( vector<vector<char> > &V , int x , int y  )
{   
    int nx , ny ; 
    
    if ( x == 9 ) 
    {   
        /*
        for ( int i = 0 ; i < 9 ; i++ )
        {
            for ( int j = 0 ; j < 9 ; j++ )
            {
                cout<<V[i][j] ; 
            }
            cout<<" " ; 
        }
        exit(0) ; 
        */
        return 1 ; 
    }
    
    if ( y == 8 )
    {
        nx = x+1 ; 
        ny = 0   ; 
    }
    else
    {
        nx = x   ; 
        ny = y+1 ;
    }
    
    if ( V[x][y] != '.' ) 
    {
        return solve ( V , nx , ny ) ; 
    }
    
    vector < bool > hash ( 10 , false ) ; hash[0] = true ; 
    
    for ( int i = 0 ; i < 9 ; i++ )
        if ( V[x][i] != '.' ) 
            hash[ V[x][i] - 48 ] = true ; 
    
    for ( int i = 0 ; i < 9 ; i++ )
        if ( V[i][y] != '.' )
            hash[ V[i][y] - 48 ] = true ; 
        
    int bx = (x/3)*3 ; int by = (y/3)*3 ; 
    
    for ( int i = 0 ; i < 3 ; i++ )
        for ( int j = 0 ; j < 3 ; j++ )
            if ( V[bx+i][by+j] != '.' ) 
                hash[ V[bx+i][by+j] - 48 ] = true ; 
                
    //for ( int i = 1 ; i < 10 ; i++ )  cout<<(int)hash[i] ; cout<<endl ; 
            
    for ( int i = 1 ; i < 10 ; i++ )
    {
        if ( hash[i] == false )
        {   
            //cout<<x<<y<<" "<<i<<endl ; 
            V[x][y] = i + 48 ; 
            if ( solve ( V , nx , ny ) ) return 1 ; 
        }
    }
    V[x][y] = '.' ; 
    return 0 ; 
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    
    solve ( A , 0 , 0 ) ; 
}
