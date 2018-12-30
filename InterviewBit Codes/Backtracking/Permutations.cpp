// https://www.interviewbit.com/problems/permutations/

/*
bool next ( vector<int> &A )
{   
    int n = (int)A.size() ; 
    int i ; 
    for ( i = n-2 ; i>=0 ; i-- )
    {
        if ( A[i] < A[i+1] ) 
        {
            reverse( A.begin()+i+1 , A.end() ) ; 
            int pos = upper_bound( A.begin()+i+1 , A.end() , A[i] ) - A.begin() ; 
            swap ( A[i] , A[pos] ) ; 
            break ; 
        }
    }
    if ( i == -1 ) return false ; 
    else return true ; 
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    sort ( A.begin() , A.end() ) ; 
    vector<vector<int> > ans ; 
    do 
    {
        ans.push_back(A) ; 
        
    }while ( next(A) ) ; 
    
    return ans ; 
}
*/

int solve ( vector<vector<int> > &ans, vector<int> &A, vector<int> &aux, vector<bool> hash , int count )
{   
    int n = (int)A.size() ; 
    if ( count == n ) 
    {
        ans.push_back(aux) ; 
        return 0; 
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( hash[i] == 0 )
        {
            aux[count] = A[i] ; 
           
            hash[i] = true ; 
            solve ( ans , A , aux , hash , count + 1 ) ; 
            hash[i] = false ; 
            
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    sort ( A.begin() , A.end() ) ; 
    
    vector<vector<int> > ans ; 
    vector<int> aux ( (int)A.size() ) ; 
    vector<bool> hash( (int)A.size() , false ) ;
    
    solve ( ans , A , aux , hash , 0 ) ; 
    
    return ans ; 
}   
    
    
    
    
    
    
