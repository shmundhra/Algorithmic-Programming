// https://www.interviewbit.com/problems/valid-ip-addresses/

bool valid ( string s )
{
    if ( s[0] == '0' and s.size() != 1 ) return false ; 
    
    if ( s.size() < 3 ) return true ;
    
    if ( s.compare("256") > 0 ) return false ; 
    
    return true ; 
}


vector<string> Solution::restoreIpAddresses(string A) {
    
    vector<string> ans ; 
    
    //if ( A.size() > 12 || A.size() < 4 ) return ans ; 
    
    int s1 , s2 , s3 , s4 , e1 , e2 , e3 , e4 ; 
    int len1 , len2 , len3 , len4 ; 
    
    string st1 ; 
    for ( s1 = 0 , len1 = 0 ; len1 < 3 and s1 + len1 < A.size() ; len1++ )
    {   
        //cout<<"#1#"<<len1+1 ;
        
        st1 += A[s1 + len1] ; 
        
        if ( !valid(st1) ) break ; 
        e1 = s1 + len1 + 1 ; 
        
        string st2 ; 
        for ( s2 = e1 , len2 = 0 ; len2 < 3 and s2 + len2 < A.size() ; len2++ )
        {   
            //cout<<" #2#"<<len2+1 ;
            
            st2 += A[s2 + len2] ; 
            
            if ( !valid(st2) ) break ; 
            e2 = s2 + len2 + 1 ; 
            
            string st3 ; 
            for ( s3 = e2 , len3 = 0 ; len3 < 3 and s3 + len3 < A.size() ; len3++ )
            {   
                //cout<<" #3#"<<len3+1 ;
                
                st3 += A[s3 + len3] ; 
                
                if ( !valid(st3) ) break ; 
                e3 = s3 + len3 + 1 ;
                
                string st4 ; 
                for ( s4 = e3 , len4 = 0 ; len4 < 3 and s4 + len4 < A.size() ; len4++ )
                {   
                    //cout<<len1<<" "<<len2<<" "<<len3<<" "<<len4<<endl ; 
                    //cout<<" #4#"<<len4+1 ;
                    
                    st4 += A[s4 + len4] ; 
                    
                    if ( !valid(st4) ) break ; 
                    e4 = s4 + len4 + 1 ;
                    
                    if ( e4 == A.size() )
                    {
                        ans.push_back( st1 + "." + st2 + "." + st3 + "." + st4 ) ; 
                        break ; 
                    }
                    
                }
            }
        }
    }
    
    //for ( int i = 0 ; i < ans.size() ; i++ ) cout<<ans[i]<<endl ; 
    
    return ans ; 
    
}
