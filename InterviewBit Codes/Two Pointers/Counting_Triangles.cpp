// https://www.interviewbit.com/problems/counting-triangles/

#define MOD 1000000007
int Solution::nTriang(vector<int> &A) {
    
    sort ( A.begin() , A.end() ) ; 
    
    long long count = 0 ; 
    for ( long i = 0 ; i < (long)A.size()-2 ; i++ )
    {   
        long sump = -1 ; 
        
        for ( long j = i+1 ; j < (long)A.size()-1 ; j++ )
        {  
            long sum  = (long)A[j] + (long)A[i] ;
            
            for( sump = max( j+1,sump ) ; sump < A.size() and A[sump] < sum ; sump++ ) ;
            
            //cout<<"("<<i<<","<<j<<") "<<diff<<","<<sum<<":"<<(j+1)<<"--"<<sump<<" "<<sump-diffp<<endl ; 
            
            count += ( sump% MOD - (j+1)% MOD ) % MOD ; 
            count %= MOD ; 
        }
        //cout<<count<<endl ; 
    }
    return (int)count ; 
}
