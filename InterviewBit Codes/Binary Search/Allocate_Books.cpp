// https://www.interviewbit.com/problems/allocate-books/

bool check( vector<int> &A, int B , int pages )
{
    int count = 1 ; 
    long long sum = 0 ; 
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        sum += A[i] ; 
        
        if ( sum > pages )
        {
            count++ ; 
            sum = A[i] ; 
        }
    }
    
    if ( count <= B ) return true ; 
    
    return false ; 
}

int Solution::books(vector<int> &A, int B) {
    
    if ( A.size() < B ) return -1 ; 
    
    int maxp = INT_MIN ; 
    long long sum = 0 ; 
    for ( int i = 0; i < A.size() ; i++ )
    {
        maxp = max ( maxp , A[i] ) ; 
        sum += A[i] ; 
    }
    
    long long low = maxp ;  // This ensures that we never encounter a case where a book cant be alloted 
                            // hence count will always be alteast 1 .
    long long high = sum ;  // When each book is alloted to the same student 
    
    while ( low < high )   // ........no no YES yes yes yes ........ format 
    {
        long long mid = low + ( high - low ) /2 ; 
        
        if ( check(A , B , mid ) )
            high = mid ; 
        else
            low = mid + 1 ; 
    }
    return low ; 
    
    // We dont need to take care of the whether or not each student is assigned a book 
    // This is because IF it is possible , i.e. A.size() >= B ; then the max pages assigned
    // to a student will be minimum only when all students are getting assigned a book 
    
}
