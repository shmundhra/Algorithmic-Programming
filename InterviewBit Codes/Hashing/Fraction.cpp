// https://www.interviewbit.com/problems/fraction/

string Solution::fractionToDecimal(int A, int B) {
    
    if ( A == 0 ) return "0" ; 
    
    if ( B == 0 ) return "" ; 
    
    long a = A > 0 ? A : -(long)A ;
    long b = B > 0 ? B : -(long)B ; 
    
    long long quo = a / b ; 
    string Q = to_string(quo) ; 
    
    a %= b ;
    string D = "" ; 
    
    unordered_map < long long , int > m ; 
    
    while(a)
    {
        long long d = (10*a)/b ;  
        long long r = (10*a)%b ; 
        
        if ( m.find(a) == m.end() )
        {
            m[a] = D.size() ; 
            D.push_back( d + '0' ) ; 
            a = r ; 
        }
        else
        {
            break ; 
        }
    }
    string ans ; 
    
    if ( D == "" ) ans = Q ; 
    
    else if ( a == 0 ) 
    {
        ans = Q + "." + D ; 
    }
    else
    {
        ans = Q + "." + string(D.begin() , D.begin() + m[a] ) + "(" + string(D.begin() + m[a] , D.end() ) + ")" ; 
    }
    
    if ( (A>0)*(B>0) + (A<0)*(B<0) == 0 )
        ans = '-' + ans ; 
        
    return ans ; 
}
