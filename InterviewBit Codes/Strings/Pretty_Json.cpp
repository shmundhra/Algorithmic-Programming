// https://www.interviewbit.com/problems/pretty-json/

vector<string> Solution::prettyJSON(string A) {
    
    stack < string > st ; 
    st.push("");
    vector < string > ans ; 
    string temp ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] == '[' || A[i] == '{')
        {
            string s = st.top(); 
            if( !temp.empty() )
            {
                ans.push_back(s+temp) ;
                temp.clear() ;
            }
            ans.push_back( s + A[i] ) ; 
            st.push( s + "\t") ; 
            
        }
        else if ( A[i] == ']' || A[i] == '}')
        {   
            string s = st.top() ; 
            if( !temp.empty() )
            {
                ans.push_back(s+temp) ;
                temp.clear() ;
            }
            st.pop() ; 
            
            s = st.top(); 
            ans.push_back( s + A[i] ) ; 
           
        }
        else if  ( A[i] == ',' )
        {   
            if( temp.empty() )
            {
               ans[ans.size()-1].push_back(A[i]) ;  
            }
            else
            {
                string s = st.top(); 
                temp += A[i] ; 
                ans.push_back(s+temp) ; 
                temp.clear() ;
            }
        }
        else if ( A[i] == ' ') 
            continue ; 
        else
        {
            temp += A[i] ; 
        }
        
    }
    return ans ; 
    
}
