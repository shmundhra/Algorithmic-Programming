// https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int A) {
    
    string s ; 
    do
    {
        s.push_back( (--A)%26 + 'A' ) ; 
    }while(A/=26) ; 
    
    reverse( s.begin() , s.end() ) ;
    return s ; 
}
