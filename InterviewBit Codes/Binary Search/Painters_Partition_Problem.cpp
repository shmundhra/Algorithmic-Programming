// https://www.interviewbit.com/problems/painters-partition-problem/

#define MOD 10000003
int Solution::paint(int A, int B, vector<int> &C) {
    
    long long k = A ; 
    
    for ( int i = 1 ; i < C.size() ; i++ )
        C[i] += C[i-1] ; 
        
    long long total = C[ C.size()-1 ] ; 
    long long ans = 0 ; 
    int id = C.size()-1 ; 
    
    while(1)
    {   
        for ( int i = 0 ;  i <= id ; i++ )    
            cout<<C[i]<<" " ; 
        cout<<endl ; 
        
        
        if ( k == 1 )
        {
            ans = max ( ans , (( total )%MOD ) ) ;
            break ; 
        }
        
        long long value = total / k ; 
        cout<<total<<" "<<value<<" " ; 
        value = total - value ; 
        
        id = lower_bound(C.begin() , C.end() , value ) - C.begin() ; 
        if ( id != 0 )
        {
            if ( (value - C[id-1]) <= (C[id] - value) ) id-- ; 
        }
        
        cout<<total - C[id]<<" " ; 
        ans =  max ( ans , (( total - C[id] )%MOD )  )  ;   
        total = C[id] ; 
        k-- ; 
        cout<<total<<" "<<ans<<endl ; 
    }
    
}
