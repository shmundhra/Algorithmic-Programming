// https://www.interviewbit.com/problems/window-string/

string Solution::minWindow(string A, string B) {
    
    A.push_back('#') ; 
    
    vector < int > hashT ( 257 , 0 ) ; 
    for ( int i = 0 ; i < B.size() ; i++ ) hashT[ B[i] ] ++ ; 
    
    int len = 0 ; 
    for ( int i = 0 ; i < 257  ; i++ )
    {
        if ( hashT[i] ) len++ ; 
    }
    
    vector < int > hashW ( 256 , 0 ) ; 
    
    int check = 0 ; 
    int minl = INT_MAX ; 
    int L = 0 ; 
    int R = 0 ; 
    
    for ( int l = 0 , r = 0 ; l <=r and r < A.size() ; )
    {
        if ( check == len ) 
        {
            if ( minl > (r-l) ) 
            {   
                L = l ; 
                R = r ; 
                minl = r-l ; 
            }
            
            if (  hashW [ A[l]] == hashT [ A[l] ]  ) check -- ; 
            
            hashW[ A[l] ] -- ; 
            l++ ; 
        }
        else
        {   
            hashW [ A[r] ] ++ ; 
            if (  hashW [ A[r] ] == hashT [ A[r] ]  ) check++ ; 
            r++ ; 
        }
    }
    return string ( A.begin() + L , A.begin() + R ) ; 
}
