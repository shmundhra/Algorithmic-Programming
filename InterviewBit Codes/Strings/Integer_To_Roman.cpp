// https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int A) {
    
    vector < string > a ; 
    string s ; 
    
    a.push_back("") ; 
    s = "" ; 
    for ( int i = 1 ; i < 10 ; i++ )
    {
        if ( i < 4 or ( i > 5 and i < 9 ) )
        {
            s += "I" ; 
            a.push_back(s) ; 
        }
        else if ( i == 4 )
        {
            a.push_back("IV") ; 
        }
        else if ( i == 5 )
        {
            s = "V" ; 
            a.push_back(s) ; 
        }
        else 
            a.push_back("IX") ; 
    }
    
    a.push_back("") ; 
    s = "" ; 
    for ( int i = 1 ; i < 10 ; i++ )
    {
        if ( i < 4 or ( i > 5 and i < 9 ) )
        {
            s += "X" ; 
            a.push_back(s) ; 
        }
        else if ( i == 4 )
        {
            a.push_back("XL") ; 
        }
        else if ( i == 5 )
        {
            s = "L" ; 
            a.push_back(s) ; 
        }
        else 
            a.push_back("XC") ; 
    }
    
    a.push_back("") ; 
    s = "" ; 
    for ( int i = 1 ; i < 10 ; i++ )
    {
        if ( i < 4 or ( i > 5 and i < 9 ) )
        {
            s += "C" ; 
            a.push_back(s) ; 
        }
        else if ( i == 4 )
        {
            a.push_back("CD") ; 
        }
        else if ( i == 5 )
        {
            s = "D" ; 
            a.push_back(s) ; 
        }
        else 
            a.push_back("CM") ; 
    }
    
    a.push_back("") ;
    a.push_back("M") ;
    a.push_back("MM") ;
    a.push_back("MMM") ;
    
    string ans ;  
    for ( int k = 0 ; A ;  k++ )
    {
        string temp = a[ 10*k + A%10 ] ; 
        reverse ( temp.begin() , temp.end() ) ;
        ans += temp ; 
        A/=10 ; 
    }
    reverse ( ans.begin() , ans.end() ) ;
    
    return ans ; 
}
