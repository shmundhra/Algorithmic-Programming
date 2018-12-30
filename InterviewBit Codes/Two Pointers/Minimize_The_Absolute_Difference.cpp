// https://www.interviewbit.com/problems/minimize-the-absolute-difference/

int f ( int a , int b , int c )
{
    return ( max ( a , max ( b , c )) - min ( a , min ( b , c )) ) ; 
}


int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    if (  A.size() * B.size() * C.size() == 0 ) return INT_MAX ; 
    
    int sb = 0 ; int sc = 0 ; 
    
    int mini = INT_MAX ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        int idb = upper_bound( B.begin() + sb , B.end() , A[i] ) - B.begin() ;         
        int idc = upper_bound( C.begin() + sc , C.end() , A[i] ) - C.begin() ; 
        
        int lb = idb ? B[idb-1] : B[0] ; 
        int lc = idc ? C[idc-1] : C[0] ;
        
        int rb = (idb != B.size() ) ? B[idb] : B[B.size()-1] ;
        int rc = (idc != C.size() ) ? C[idc] : C[C.size()-1] ; 
        
        //cout<<A[i]<<" ("<<lb<<","<<rb<<" )  "<<"("<<lc<<","<<rc<<") "<<mini<<endl ; 
        
        int x = min ( f(A[i] , rb , rc ) , f(A[i] , lb , lc) ) ; 
        int y = min ( f(A[i] , rb , lc ) , f(A[i] , lb , rc) ) ;
        int z = min ( x , y ) ; 
        mini = min ( mini , z ) ; 
        
        sb = ( idb ? (idb-1) : 0) ; 
        sc = ( idc ? (idc-1) : 0) ; 
    }
    return mini ; 
}
