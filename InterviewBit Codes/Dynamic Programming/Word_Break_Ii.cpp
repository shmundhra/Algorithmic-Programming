// https://www.interviewbit.com/problems/word-break-ii/

unordered_map < string , int > M ; 
vector < vector <int>  > dp ; 
vector < string > ans ; 

void print ( string &A , int start , string aux )
{
    if ( start == (int)A.size() )
    {   
        aux.pop_back() ; 
        ans.push_back(aux) ; 
        return ; 
    }
    
    string tmp ; 
    for ( int i = 0 ; i < dp[start].size() ; i++ , tmp.clear() )
    {
        tmp = string ( A.begin() + start , A.begin() + dp[start][i] ) + " " ; 
        
        print ( A , dp[start][i] , aux + tmp ) ; 
    }
}
int solve ( string &A , int start )
{
    if ( dp[start].empty() ) 
    {   
        string tmp = "" ; 
        
        for ( int i = start ; i < (int)A.size() ; i++ )
        {
            tmp += A[i] ; 
            if ( M.find(tmp) != M.end() )
            {
                solve ( A , i+1 ) ;
                    
                if ( dp[i+1][0] != -1 ) dp[start].push_back(i+1) ; 
            }
        }
        
        if ( dp[start].empty() ) dp[start].push_back(-1) ; 
    }
}


vector<string> Solution::wordBreak(string A, vector<string> &B) {
    
    //A.pop_back() ;
     
    int n = A.size() ; 
    dp.clear() ; dp.assign( n+1 , vector < int >(0) ) ; dp[n].push_back(n) ; 
    
    M.clear() ; for ( auto s : B ) M[s]++ ; 
    
    solve ( A , 0 ) ; 
    
    ans.clear() ;  if ( dp[0][0] != -1 ) print( A , 0 , "" ) ; 
    
    sort ( ans.begin() , ans.end() ) ; 
    
    return ans ; 
    
}