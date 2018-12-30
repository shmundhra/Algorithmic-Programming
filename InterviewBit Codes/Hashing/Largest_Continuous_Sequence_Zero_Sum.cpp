// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &A) {
    
    unordered_map < long int , int > m ; 
    
    int l = 0 ; 
    int r = 0 ; 
    
    int sum = 0 ; 
    m[0] = -1 ; 
    
    for ( int i = 0 ; i < (int)A.size() ; i++ )
    {
        sum += A[i] ;
        
        if ( m.find( sum ) == m.end() )
        {
            m[ sum ] = i ; 
        }
        else
        {
            if ( i - m[ sum ] > r - l )
            {
                r = i ; 
                l = m[ sum ] ; 
            }
        }
    }

    return vector <int> ( A.begin() + l + 1 , A.begin() + r + 1 ) ; 
}

