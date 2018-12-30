// https://www.interviewbit.com/problems/combinations/

int print( vector<vector<int> > &ans, vector < int > &aux, int n, int k, int id, int pos )
{   
    aux[pos] = id ;
    
    if ( k == 1 )
    {
        ans.push_back( vector<int> ( aux.begin()+1 , aux.begin()+pos+1 ) ) ; 
        return 0 ; 
    }
    
    for ( int i = id+1 ; i <= (n-k+2) ; i++ )  // Optimisation ke liye (n-k+2) kar diya
    {
        print ( ans , aux , n , k-1 , i, pos+1 ) ; 
    }
}

vector<vector<int> > Solution::combine(int A, int B) 
{
    vector< vector<int> > ans ;
    vector <int> aux(A+1) ; 
    print ( ans , aux , A , B+1 , 0 , 0 ) ; 
    return ans ; 
}
