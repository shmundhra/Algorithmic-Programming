// https://www.interviewbit.com/problems/order-of-people-heights/

/*struct tnode
{
    int ht ; 
    int num ;
    tnode* left  ; 
    tnode* right ;
    
    tnode ( int x , int y ) : ht(x) , num(y) , left(NULL) , right(NULL) {}
};

tnode *T ; 

int TreeInsert ( tnode* &A , int h , int n )
{
    if ( n < (A->num) )
    {   
        (A->num)-- ;
        if ( A->left == NULL )
        {
            tnode *node = new tnode ( h , n ) ; 
            A->left = node ; 
        }
        else
        {
            TreeInsert( A->left  , h , n ) ;
        }
    }
    else
    {   
        n-= (A->num) ; 
        if ( A->right == NULL )
        {
            tnode *node = new tnode ( h , n ) ; 
            A->right = node ; 
        }
        else
        {
            TreeInsert( A->right  , h , n ) ;
        }
    }
    
}

int Inorder ( tnode *A , vector<int> &ans )
{
    if (!A) return 0 ; 
    Inorder(A->left , ans );
    ans.push_back(A->ht) ; 
    Inorder(A->right, ans ) ;
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    
    vector < pair<int,int> > v ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
        v.push_back(make_pair( A[i] , B[i] ) ) ; 
    sort ( v.begin() , v.end() ) ; 
        
    T = new tnode( v[0].first , v[0].second ) ; 
    
    for ( int i = 1 ; i < v.size() ; i++ )
    {
        TreeInsert( T , v[i].first , v[i].second ) ; 
    }
    
    vector < int > ans ; 
    Inorder( T , ans) ; 
    
    return ans ; 
}
*/


long query ( vector <int> &bit , int index )
{   
    long sum = 0 ; 
    for ( int i = index ; i > 0 ; i-= i&(-i) )
    {
        sum += bit[i] ; 
    }
    return sum ; 
}


void update ( vector <int> &bit , int index )
{
    for ( int i = index ; i < bit.size() ; i += i&(-i) )
    {
        bit[i] += 1 ; 
    }
}


long Search ( vector <int > &bit ,  int value  /*, vector <bool> &check*/  )
{
    long low = 1 ; 
    long high = bit.size()-1 ; 
    
    /*while ( low <= high )
    {
        long mid = low + (high-low)/2 ; 
        
        long num = mid-1 - query( bit , mid-1 ) ; //bit[mid-1] no. of filled places till [ 1,mid )
        
        if ( num == value )
        {
            if ( !check[mid] )
            {   
                update ( bit , mid ) ; 
                check[mid] = true ; 
                return mid ; 
            }
            else
            {
                low = mid+1 ; 
            }
        }
        else if ( num > value )
        {
            high = mid-1 ; 
        }
        else
        {
            low = mid+1 ; 
        }
    }*/
    
    while ( low < high )
    {
        long mid = low + ( high-low +1 )/2 ; 
        
        long num = (mid-1)-query(bit,mid-1) ; 
        
        if ( num > value )
        {
            high = mid-1 ; 
        }
        else
        {
            low = mid ; 
        }
    }
    update ( bit , low ) ; 
    return low ; 
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    
    vector < pair<int,int> > v ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
        v.push_back(make_pair( A[i] , B[i] ) ) ; 
    sort ( v.begin() , v.end() ) ; 
    
    
    vector < int > ans ( A.size() + 1 , -1 ) ; 
    vector < int > bit ( A.size() + 1 , 0  ) ; 
    //vector < bool > check ( A.size() + 1 , false  ) ; 
    
    for ( int i = 0  ; i < v.size() ; i++ )
    {
        int index = Search ( bit , v[i].second  /*, check */  ) ; 
        ans[index] = v[i].first ; 
    }
    
    return vector <int> ( ans.begin()+1 , ans.end() ) ; 
}

