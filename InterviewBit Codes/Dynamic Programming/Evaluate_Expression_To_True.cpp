// https://www.interviewbit.com/problems/evaluate-expression-to-true/

#define MOD 1003   

int Solution::cnttrue(string A) {
    
    int n = A.size() ; 
    if(!n) return 0 ; 
    
    vector < vector < int >  > dpF ( n , vector < int > ( n , -1 ) )  ;
    vector < vector < int >  > dpT ( n , vector < int > ( n , -1 ) )  ; 
    
    for ( int i = 0 ; i < n ; i += 2 ) dpT[i][i] = ( A[i] == 'T' ) ;  
    for ( int i = 0 ; i < n ; i += 2 ) dpF[i][i] = ( A[i] == 'F' ) ;  
    
    for ( int len = 2 ; len < n ; len+=2 )
    {
        for ( int st = 0 ; st+len < n ; st += 2 )
        {   
            int countT = 0 ; int countF = 0 ;
            
            for ( int pt = st ; pt < st+len ; pt += 2  )
            {
                switch ( A[pt+1] )
                {
                    case '|' : countF = (countF + ( dpF[st][pt] * dpF[pt+2][st+len] ) %MOD ) % MOD ; 
                               countT = (countT + ( dpT[st][pt] * dpF[pt+2][st+len] ) %MOD + ( dpF[st][pt] * dpT[pt+2][st+len] ) %MOD + ( dpT[st][pt] * dpT[pt+2][st+len] ) %MOD )%MOD ;     
                               break ; 
                               
                    case '&' : countT = (countT + ( dpT[st][pt] * dpT[pt+2][st+len] ) %MOD ) % MOD ; 
                               countF = (countF + ( dpT[st][pt] * dpF[pt+2][st+len] ) %MOD + ( dpF[st][pt] * dpT[pt+2][st+len] ) %MOD + ( dpF[st][pt] * dpF[pt+2][st+len] ) %MOD )%MOD ;     
                               break ;   
                             
                    case '^' : countT = (countT + ( dpT[st][pt] * dpF[pt+2][st+len] ) %MOD + ( dpF[st][pt] * dpT[pt+2][st+len] )%MOD )%MOD ; 
                               countF = (countF + ( dpT[st][pt] * dpT[pt+2][st+len] ) %MOD + ( dpF[st][pt] * dpF[pt+2][st+len] )%MOD )%MOD ;     
                               break ; 
                    
                    default : break ; 
                }
            }
            
            dpT[st][st+len] = countT ; dpF[st][st+len] = countF ; 
        }
    }
    return dpT[0][n-1] ; 
    
}
