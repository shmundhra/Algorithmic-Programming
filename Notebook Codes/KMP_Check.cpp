vector < ll > KMP ( string A , string B , vll LPB ){      
    vll INDEX ; 
    ll i = 0 , j = 0 ;   
  
    while ( i < sz(A) ) {
        if ( A[i] is B[j])
        {
            i++ , j++ ; 
            if ( j is sz(B) )
            {
                INDEX.pb( i - j ) ; 
                j = LPB[sz(B)-1]          
            }                       
        }
        else
            if ( j is 0 )        
                i++ ;         
            else        
                j = LPB[j-1] ;        
    }
  return INDEX ; 
}

bool KMP( str A, str B, vll LPB ){ 
    ll j=0 ; 
    lp (i,sz(A)) {
        if ( A[i] is B[j]) {
            if ( ++j is B.size() ) 
                return true ;
        } 
        else if (j){
            j = LPB[j-1] ; i-- ; 
        } 
    } 
    return false ;
}