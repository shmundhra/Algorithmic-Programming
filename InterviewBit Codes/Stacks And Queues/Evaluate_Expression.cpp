// https://www.interviewbit.com/problems/evaluate-expression/

long long num ( string s )
{
    long ans = 0 ; 
    int flag = 0 ; 
    
    if(s[0] == '-' ) flag = 1 ; 
    
    for ( int i = flag  ; i < s.size() ; i++ )
    {
        ans = ans*10 + s[i]-48 ; 
    }
    
    return flag ? -ans : ans ;
}

int Solution::evalRPN(vector<string> &A) {
    
    stack <long long> s ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if (A[i].compare("*") == 0 )
        {
            long long a = (s.top()) ; s.pop() ; 
            long long b = (s.top()) ; s.pop() ; 
            s.push(b*a) ; 
        }
        else if (A[i].compare("+") == 0 )
        {
            long long a = (s.top()) ; s.pop() ; 
            long long b = (s.top()) ; s.pop() ; 
            s.push(b+a) ; 
        }
        else if (A[i].compare("-") == 0 )
        {
            long long a = (s.top()) ; s.pop() ; 
            long long b = (s.top()) ; s.pop() ; 
            s.push(b-a) ; 
        }
        else if (A[i].compare("/") == 0 )
        {
            long long a = (s.top()) ; s.pop() ; 
            long long b = (s.top()) ; s.pop() ; 
            s.push(b/a) ; 
        }
        else
        {
            s.push( num(A[i]) ) ; 
        }
    }
    
    return s.top() ; 
}
