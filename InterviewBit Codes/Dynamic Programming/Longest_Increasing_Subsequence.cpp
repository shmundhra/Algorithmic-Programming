// https://www.interviewbit.com/problems/longest-increasing-subsequence/

void join (vector < int > &I , int left , int mid , int right , vector < int > &v , vector < int > &LIS)
{
    vector < int > l ( I.begin()+left , I.begin()+mid  ) ; 
    vector < int > r ( I.begin()+mid , I.begin()+right ) ;
    
    vector < int > temp ( right - mid , 0 ) ; 
    
    for ( int i = 0 , j = 0 ; j < r.size() ; )
    {
        if ( v[ l[i] ] > v[ r[j] ] or i == l.size() )
        {
            temp[r[j]-mid] += i ; 
            j++ ; 
        }
        else
        {
            i++ ; 
        }
    }
    
    int i , j ; 
    for ( i = 0 , j = 0 ; i < l.size() and j < r.size() ; )
    {
        if ( v[ l[i] ] < v[ r[j] ] )
        {
            I[left+i+j] = l[i] ; 
            i++ ; 
        }
        else
        {
            I[left+i+j] = r[j] ; 
            j++ ; 
        }
    }
    for ( ; i < l.size() ; i++ )
    {
        I[left+i+j] = l[i] ; 
    }
    for ( ; j < r.size() ; j++ )
    {
        I[left+i+j] = r[j] ; 
    }
    
    for ( int i = 0 ; i < r.size() ; i++ ) LIS[i+mid] += temp[i] ; 

}

int solve ( vector < int > &I , int left , int right , vector < int > &v , vector < int > &LIS )
{   
    if ( right - left <= 1 ) return 0 ; 
    
    int mid = left + ( right - left) / 2 ; 
    
    solve ( I , left , mid , v , LIS) ; 
    cout<<"("<<left<<" "<<mid<<") "; for ( int i = 0 ; i < v.size() ; i++ ) cout<<LIS[i]<<" " ; cout<<endl ; 
    
    solve ( I , mid , right , v , LIS) ; 
    cout<<"("<<mid<<" "<<right<<") "; for ( int i = 0 ; i < v.size() ; i++ ) cout<<LIS[i]<<" " ; cout<<endl ;
    
    join ( I , left , mid , right , v , LIS ) ; 
    cout<<"("<<left<<" "<<mid<<" "<<right<<") "; for ( int i = 0 ; i < v.size() ; i++ ) cout<<LIS[i]<<" " ; cout<<endl ;  
}


int Solution::lis(const vector<int> &A) {
    
    /*
    vector < int > LIS ( (int)A.size() , 0 ) ; 
    vector < int > path ( (int)A.size() , 0 ) ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        int len = 0 ; 
        int pos = -1 ; 
        for ( int j = 0 ; j < i ; j++ )
        {
            if ( A[j] < A[i] )
            {
                if ( LIS[j] > len )
                {
                    len = LIS[j] ; 
                    pos = j ; 
                }
            }
        }
        LIS[i] = 1 + len ; 
        path[i] = pos ; 
    }
    
    int max = -1 ; 
    int maxp = -1 ; 
    for ( int i = 0 ; i < LIS.size() ; i++ )
    {
        if ( max < LIS[i] )
        {
            max = LIS[i] ; 
            maxp = i ; 
        }
    }
    
    vector < int > seq ; 
    for ( int i = maxp ; i>= 0 ; i = path[i] ) seq.push_back(i) ; 
    reverse(seq.begin() , seq.end()) ; 
    
    return *max_element(LIS.begin() , LIS.end() ) ; 
    */
    
    vector < int > v ; 
    vector < int > LIS ; 
    
    v.assign( A.begin() , A.end() ) ; 
    LIS.assign( A.size() , 1 ) ; 
    
    vector < int > I ; for ( int i = 0 ; i < A.size() ; i++ ) I.push_back(i) ; 
    
    solve( I , 0 , (int)A.size() , v , LIS ) ; 
    
   
    return *max_element(LIS.begin() , LIS.end() ) ; 
}