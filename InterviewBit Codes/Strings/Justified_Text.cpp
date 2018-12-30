// https://www.interviewbit.com/problems/justified-text/

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    
    vector<string> ans ; 
    
    if ( A.size() == 0 ) return ans ; 
    
    int start = 0 ; 
    int end = -1 ;
    
    int count = 0 ; 
    
    for ( int i = 0 ; i < (int)A.size() ; i++ )
    {
        if ( count + (int)A[i].size() <= B )
        {   
            A[i].push_back(' ') ; 
            count += (int)A[i].size() ; 
            end = i ; 
        }
        else
        {
            count-- ;
            A[end].pop_back() ; 
            for ( int k = 0 ; k < B-count ; k++ )
            {
                A[ start + k%( end-start + 1*(!(end-start)) ) ].push_back(' ') ; 
            }
            string s ; 
            for ( int j = start ; j<=end ; j++ )
            {
                s += A[j] ; 
            }
            //cout<<s<<endl;
            ans.push_back(s) ; 
            count = 0 ; 
            start = i ; 
            i-- ; 
        }
    }
    count-- ;
    A[end].pop_back() ; 
    
    string s ; 
    for ( int j = start ; j<=end ; j++ )
    { 
        s += A[j] ; 
    }
    for ( int k = 0 ; k < B-count ; k++ )
    {
        s.push_back(' ');
    }
    //cout<<s<<endl;
    ans.push_back(s) ;
    
    return ans ; 
    
}
