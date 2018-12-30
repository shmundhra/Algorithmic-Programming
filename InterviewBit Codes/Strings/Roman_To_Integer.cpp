// https://www.interviewbit.com/problems/roman-to-integer/

int Solution::romanToInt(string A) {
    
    int ans = 0 ;
    
    int i = 0 ; 
    for ( ; i < A.size() ; i++ )
    {
        if ( A[i] != 'M') break ; 
    }
    
    ans += 1000*(i-0) ; 
    
    int j = i ; 
    for ( ; j < A.size() ; j++ )
    {
        if ( A[j] != 'D') break ; 
    }
    
    ans += 500*(j-i) ; 
    
    int k = j ; 
        if ( k < A.size()-1 )
        {
            if ( A[k] == 'C' and A[k+1] == 'M' ) 
            {
                ans += 900 ; 
                k+=2 ; 
                
            }
            else if ( A[k] == 'C' and A[k+1] == 'D' ) 
            {
                ans += 400 ; 
                k+=2 ; 

            }
        }
    
    
    int l = k ; 
    for ( ; l < A.size() ; l++ )
    {
        if ( A[l] != 'C') break ; 
    }
    ans += 100*(l-k) ; 
    
    int m = l ;
    for ( ; m < A.size() ; m++ )
    {
        if ( A[m] != 'L') break ; 
    }
    
    ans += 50*(m-l) ; 
    
    int n = m ; 
        if ( n < A.size()-1 )
        {
            if ( A[n] == 'X' and A[n+1] == 'C' ) 
            {
                ans += 90 ; 
                n+=2 ; 
                
            }
            else if ( A[n] == 'X' and A[n+1] == 'L' ) 
            {
                ans += 40 ; 
                n+=2 ; 
                
            }
        }
        
    int o = n ; 
    for ( ; o < A.size() ; o++ )
    {
        if ( A[o] != 'X') break ; 
    }
    ans += 10*(o-n) ; 
    
    int p = o ;
    for ( ; p < A.size() ; p++ )
    {
        if ( A[p]!='V') break ; 
    }
    
    ans += 5*(p-o) ;
    
    int q = p; 
        if ( q < A.size()-1 )
        {
            if ( A[q] == 'I' and A[q+1] == 'X' ) 
            {
                ans += 9 ; 
                q+=2 ; 
               ; 
            }
            else if ( A[q] == 'I' and A[q+1] == 'V' ) 
            {
                ans += 4 ; 
                q+=2 ; 
                
            }
        }
        
    int r = q ; 
    for ( ; r < A.size() ; r++)
    {
        if ( A[r] != 'I') break ; 
    }
    ans += 1*(r-q) ; 
    
    return ans ; 
    
}
