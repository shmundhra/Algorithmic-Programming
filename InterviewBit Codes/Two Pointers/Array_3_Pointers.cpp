// https://www.interviewbit.com/problems/array-3-pointers/

long abso ( long x , long y ) { if ( x < y ) return (y-x) ; else return (x-y) ; } 

long max3 ( long a , long b , long c ) { long maxi = a ; if ( maxi < b ) maxi = b ; if ( maxi < c ) maxi = c ; return maxi ; } 
long min3 ( long a , long b , long c ) { long mini = a ; if ( mini > b ) mini = b ; if ( mini > c ) mini = c ; return mini ; } 

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int i , j , k ; 
    
    long minmax = INT_MAX ;
    long mini ; 
    for ( i = j = k = 0 ; i < A.size() and j < B.size() and k < C.size() ; )
    {   
        minmax = min3 ( minmax , (long)INT_MAX , max3 ( abso(A[i],B[j]) , abso(A[i],C[k]) , abso(C[k],B[j]) )  );
        mini = min3 ( A[i] , B[j] , C[k] ) ; 
        
        if ( mini == A[i] ) i++ ; 
        else if ( mini == B[j] ) j++ ; 
        else k++ ; 
    }    
    
    return (int)minmax ; 
        
}
