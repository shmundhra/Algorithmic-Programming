// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

vector<int> Solution::maxone(vector<int> &A, int B) {
    
    /*
    int zer0 = -1 ; 
    int zer1 = 0 ;  while (  zer1<A.size() and A[zer1] == 1 ) zer1++ ; 
    int i = 0 ; 
    
    int maxlen = INT_MIN ; 
    int maxst = -1 ; 
    int flips = 0 ; 
    for ( ; i < A.size() ; i++ )
    {   
        //cout<<zer0<<" "<<zer1<<" "<<i<<endl ; 
        
        if ( A[i] == 0 ) 
        {
            if ( flips < B ) flips++ ; 
            else
            {
                if ( maxlen < (i-1)-zer0 )
                {
                    maxlen = (i-1)-zer0 ; 
                    maxst = zer0 + 1 ; 
                }
                zer0 = zer1 ; 
                while ( zer1 < A.size()-1 and A[++zer1] == 1 ) ; 
                
            }
        }
    }
    
    if ( maxlen < (A.size() -1)-zer0 )
    {
        maxlen = (A.size() -1)-zer0 ; 
        maxst = zer0 + 1 ; 
    }
    
    vector < int > v ; 
    for ( int k = 0 ; k < maxlen ; k++ )
        v.push_back(k+maxst) ; 
        
    return v ; 
    */
    
    /*
    int start = 0 ; 
    int maxlen = INT_MIN ; 
    int maxst = -1 ; 
    int flips = 0 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] == 0 )
        {
            if ( flips < B ) flips ++ ; 
            else
            {
                if ( maxlen < i - start )
                {
                    maxlen = i - start ; 
                    maxst = start ; 
                }
                while(A[start++] == 1 ) ; 
            }
        }
    }
    
    if ( maxlen < (int)(A.size() - start) )
    {   
        maxlen = (int)(A.size()  - start) ; 
        maxst = start ; 
    }
    
    
    
    vector < int > v ; 
    for ( int k = 0 ; k < maxlen ; k++ )
        v.push_back( k + maxst ) ; 
        
    return v ; 
    */
    
    if ( !A.size() ) return vector < int > {0} ; 
    
    A.push_back(0) ; B++ ; 
    
    vector < pair < int , int > > ans ; 
    
    int count = 1 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( A[i] == 1 ) count ++ ; 
        else
        {
            ans.push_back(make_pair(count , (i+1)-count ) ) ; 
            count = 1 ; 
        }
    }
    
    //for(int i=0; i<ans.size() ;i++)cout<<ans[i].first<<","<<ans[i].second<<" " ;cout<<endl;
   
    int maxsum = INT_MIN ; 
    int maxst = 0 ; 
    
    int sum = 0 ; 
    
    int i , j ; 
    for ( i = 0 , j = 0 ; i < (int)ans.size() ; i++ )
    {   
        if ( i < B ) 
        {
            sum += ans[i].first ; 
        }
        else
        {
            if ( maxsum < sum )
            {
                maxsum = sum ; 
                maxst  = ans[j].second ; 
            }
            sum = sum + ans[i].first - ans[j].first ; 
            j++ ; 
        }
    }
    
    if ( maxsum < sum )
    {
        maxsum = sum ; 
        maxst  = ans[j].second ; 
    }
    
    vector < int > v ; 
    for ( int k = 0 ; k < (int)(maxsum-1) ; k++ )
        v.push_back( k + maxst ) ; 
    
    return v ; 
    
    
    
    
    
}
