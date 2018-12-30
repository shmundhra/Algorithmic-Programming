// https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    
    /*
    int count = -1 ; 
    int l , r ; 
    
    int maxi = 0 ; 
    int ml , mr ; 
    
    for ( int i = 1 ; i <= A.size() ; i++ )
    {
        if ( count < 0 )
        {
            l = i ; 
            r = i - 1 ; 
            count = 0 ; 
        }
        
        if ( A[i-1] == '0')
        {
            count++ ; 
        }
        else
        {
            count-- ; 
        }
        r++ ; 
        
        if ( count > maxi )
        {
            maxi = count ; 
            ml = l ; 
            mr = r ; 
        }
    }
    if ( maxi > 0 )
    {
        vector<int> v = { ml , mr } ; 
        return v ; 
    }
    else
    {   
        vector<int> v = { } ; 
        return v ; 
    }*/
    
    
    int n = A.length() ; 
    
    vector < int > v ( n ) ; 
    for ( int i = 0 ; i < n ; i++ ) v[i] = A[i]=='1' ? -1 : 1 ;  
    
    int maxsum = INT_MIN ; 
    int csum = 0 ; 
    
    vector < int > ans(2) ; 
    
    int l , r ; 
    l = 0 ; 
    for ( int i = 0 ; i < n ; i++ )
    {
        csum += v[i] ; 
        //maxsum = max ( maxsum , csum ) ; 
        
        if ( maxsum < csum )
        {
            maxsum = csum ; 
            r = i ; 
            ans[0] = l+1 ; ans[1] = r+1 ; 
        }
        //csum = max ( csum , 0 ) ; 
        if ( csum < 0 )
        {
            csum = 0 ; 
            l = i+1 ; 
        }
    }
    return ans ; 
}
