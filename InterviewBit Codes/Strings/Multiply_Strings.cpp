// https://www.interviewbit.com/problems/multiply-strings/

string Solution::multiply(string A, string B) {
    
    if ( !A.compare("0") || !B.compare("0")  )  return "0" ; 
    
    reverse( A.begin() , A.end() ) ; reverse( B.begin() , B.end() ) ;
    
    //cout<<A.size()<<" "<<B.size()<<" " ; 
    
    //cout<<A<<" "<<B<<"% "  ; 
    
    string ans ( A.size()+B.size()+2 , '0' ) ; 
    
    for ( int i = 0 ; i < B.size() ; i++ )
    {  
        
        for ( int j = 0 ; j < A.size() ; j++ )
        {   
            //cout<<ans<<endl ;
            int value =  (B[i]-48)*(A[j]-48) ;
            //cout<<value<<" " ; 
            
            int k = 0 ; 
            while ( value )
            {
                int num = ans[i+j+k]-48+value ; 
                ans[i+j+k] = num%10 + 48 ;
                value = num / 10 ; 
                k++ ; 
            }
        }
    }
    
    while ( ans[ans.size()-1] == '0' ) ans.pop_back() ; 
    
    reverse ( ans.begin() , ans.end() ) ; 
    
    return ans ; 
    
    
    
}
