// https://www.interviewbit.com/problems/generate-all-parentheses-ii/

int solve ( vector<string> &ans , string &s , int A , int maxcount , int count , int pos )
{   
    if ( pos == 2*A )
    {
        ans.push_back(s) ; 
        return 0 ; 
    }
    if ( maxcount > 0 )
    {
        s[pos] = '(' ; 
        solve ( ans , s , A , maxcount-1 , count+1 ,  pos+1 ) ; 
    }
    if  ( count > 0 )
    {
        s[pos] = ')' ; 
        solve ( ans , s , A , maxcount , count-1 ,  pos+1 ) ;
    }
   
}
vector<string> Solution::generateParenthesis(int A) {
    
    vector<string> ans ; 
    string s( 2*A , ' ') ; 
    solve ( ans , s , A , A , 0 , 0) ; 
    return ans ; 
}
