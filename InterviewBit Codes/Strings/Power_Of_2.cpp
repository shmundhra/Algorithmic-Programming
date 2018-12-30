// https://www.interviewbit.com/problems/power-of-2/

int Solution::power(string A) {
    
    if ( A == "0" || A == "1" ) return 0 ; 
    
    vector < int > Divi ;
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        Divi.push_back(A[i]-48) ; 
    }
    int count = 0 ; 
    while( 1 )
    {   
        if ( Divi.size() == 1 && Divi[0] == 1 ) break ; 
        
        //cout<<count++<<". ";
        //for ( int p = 0 ; p < divi.size(); p++ ) cout<<divi[p] ; cout<<endl ; 
        vector < int > quot ; 
        long carry = 0 ; 
        long long divi = 2 ; 
        for ( int i = 0 ; i < Divi.size() ; i++ )
        {   
            quot.push_back( ( carry*10+ Divi[i] )/divi ) ; 
            carry = ( carry*10+ Divi[i] ) % divi ; 
        }
        
        if ( carry != 0 )
        {
            return 0 ; 
        }
        Divi.clear() ; 
        
        int i ; 
        for ( i = 0 ; i < quot.size() ; i++ )
        {
            if ( quot[i] != 0 )
                break ; 
        }
        Divi.assign(quot.begin()+i , quot.end() ) ; 
    }
    
    return 1 ; 
    
}
