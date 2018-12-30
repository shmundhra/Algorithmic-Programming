// https://www.interviewbit.com/problems/3-sum-zero/

int next ( vector < int > A , int ind )
{
    return (  upper_bound( A.begin()+ind+1 , A.end() , A[ind] ) - A.begin() ) ; 
}

int bef ( vector < int > A , int ind )
{   
    ind = A.size()-1 - ind ; 
    
    reverse(A.begin() , A.end() ) ;
    
    for ( int i = 0 ; i < A.size() ; i++ ) A[i] *= (-1) ; 
    
    return ( A.end()-1 - upper_bound( A.begin()+ind+1 , A.end() , A[ind] )  ) ; 
}

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    int B = 0 ; 
    
    vector<vector<int> > ans ; 
    
    sort ( A.begin() , A.end() ) ; 
    
    int i , j , k ; 
     
    for ( i = 0 ; i < A.size() ; ) 
    {   
        for ( j = i+1 , k = A.size()-1 ; j < k ;  )
        {
            //cout<<i<<" "<<j<<" "<<k<<endl ; 
            
            long long sum = (A[i] + A[j] + A[k]) ; 
            
            if ( sum == B )
            {
                vector < int > v = { A[i] , A[j] , A[k] } ;
                ans.push_back(v) ; 
                
                int temp ; 
                
                temp = A[j] ; 
                while ( A[j] == temp ) j++ ;
                
                temp = A[k] ; 
                while ( A[k] == temp ) k-- ; 
                 
            }
            else if ( sum > B )
            {
               int temp = A[k] ; 
               while ( (k>=0) and A[k] == temp ) k-- ; 
            }
            else
            {
               int temp = A[j] ; 
               while ( j<A.size() and A[j] == temp ) j++ ; 
            }
        }
        int temp = A[i] ; 
        while ( i<A.size() and A[i] == temp ) i++ ; 
    }
    
    return ans ; 
    
}
