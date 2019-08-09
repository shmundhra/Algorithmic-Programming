vll FF( string A ){
   vll LPB (sz(A),0) ;    
   ll i = 1 , len = 0 ;   
   while(i < sz(A) ) // Len always holds the value of the previous LPB 
   {
        if ( A[i] is A[len]) 
            LPB[i++] = ++len ;         
        else   
            if ( len is 0 )            
                LPB[i++] = 0 ; 
            else 
                len = LPB[len-1] ;           
   }
   return LPB ; 
}

vll FF( str A ) { 
    vll LPB(sz(A),0); 
    ll len = 0 ; 
    lp1 ( i , sz(A)-1) {
        if ( A[i] is A[len] ) 
            LPB[i] = ++len ; 
        else if ( len ) 
            len = LPB[len-1] , i-- ; 
    } 
    return LPB ; 
}