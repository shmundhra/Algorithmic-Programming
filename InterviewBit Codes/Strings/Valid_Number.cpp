// https://www.interviewbit.com/problems/valid-number/

int Solution::isNumber(const string A) {
    
    int i , j ; 
    
    for ( i = 0 ; i < A.size() ; i++ ) if ( A[i] != ' ') break ; 
    for ( j = A.size()-1 ; j >= 0 ; j-- ) if ( A[j] != ' ') break ; 
    if ( i > j ) return 0 ; 
    string a = string(A.begin()+i , A.begin()+j+1 ) + "#" ;  
    
    int start = 0 ; 
    if ( a[0] == '+' || a[0] == '-' ) start = 1 ; 
    
    if ( !isdigit( a[start] ) && a[start]!= '.' ) return 0 ;
    
    int flag = 0 ; int decB = 0 ; int expB = 0 ;
    
    for ( i = start ; i < a.size()-1 ; i++ )
    {   
        if ( !isdigit( a[i] )  )
        {
            if ( a[i] == '.' ) 
            {   
                if ( decB == 0 ) decB = 1 ; 
                else return 0 ; 
                
                if ( !isdigit( a[i+1] ) ) return 0 ;
                else
                {
                   continue ;  
                }
                
            }
            else if ( a[i] == 'e' )
            {   
                flag = 0 ; 
                if ( expB == 0 ) expB = 1 ; 
                else return 0 ; 
                
                decB = 1 ;
                
                if ( !isdigit( a[i+1] ) )
                {
                    if ( a[i+1] == '+' || a[i+1] == '-' )
                    {
                        i++ ; 
                        continue ; 
                    }
                    else
                    {
                        return 0 ; 
                    }
                }
                
            }
            else return 0 ; 
            
        }
        else
        {
            flag = 1 ; 
        }
    }
    
    return flag ; 
}
