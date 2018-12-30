// https://www.interviewbit.com/problems/substring-concatenation/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {

    vector < int > ans ; 
    
    unordered_map< string , int > m ; 
    for ( int i = 0 ; i < B.size() ; i++ )
    {
        m[ B[i] ] ++ ; 
    }
    
    int total = 0 ; 
    for ( auto it = m.begin() ; it != m.end() ; it++ )
        total += (!(!(it->second))) ; 
        
    int l = B[0].size() ; 
    
    for ( int start = 0 ; start < l ; start ++ ) 
    {   
        int count = 0 ; 
        unordered_map< string , int > h ; 
        
        //cout<<"\n" ; 
        
        for ( int i = start , j = start ; i <= j and j <= A.size() ;   )
        {   
            //cout<<"\n"<<i<<"START  " ; 
            
            string s = string( A.begin()+j , A.begin()+j+l ) ; 
            
            //cout<<i<<" "<<j<<"->"<<s ; 
            
            if ( m.find(s) != m.end() ) 
            {   
                //cout<<j<<"T  " ; 
                
                h [ s ] ++ ;
                
                if ( h[s] >  m[s] ) 
                {   
                    //cout<<"Extra" ;
                    while ( i < j and h[s] != m[s] ) 
                    {   
                        string temp = string ( A.begin()+i , A.begin()+i+l ) ;
                        
                        if ( h[temp] == m[temp] ) count-- ; 
                        
                        h[temp]-- ; 
                        
                        i += l ;
                    }
                    //cout<<i<<"%%"<<j<<"  " ; 
                    j+=l ; 
                }
                    
                else if ( h[s] == m[s] ) 
                {
                    count ++ ; 
                    j+=l ;
                    
                    if ( count == total ) 
                    {
                        ans.push_back(i);
                        
                        string temp = string ( A.begin()+i , A.begin()+i+l ) ; 
                        h[temp]-- ; 
                        count-- ; 
                        i += l ;
                    }
                     
                }
                else j+=l ; 
            }
            
            else
            {   
                //cout<<"F  " ;
                count = 0 ; 
                while( i < j )
                {
                    string temp = string ( A.begin()+i , A.begin()+i+l ) ; 
                    if ( m.find(temp) != m.end() )
                    {
                        h[temp]-- ; 
                    }
                    i += l ; 
                }
                i+=l ;
                j+=l ;
            }
        }
    }   
    return ans ; 
}
