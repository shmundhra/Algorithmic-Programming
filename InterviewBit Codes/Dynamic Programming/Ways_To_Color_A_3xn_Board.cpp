// https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

#define MOD 1000000007 
int ss , sd , ds , dd ; 
vector < vector < long long > > dp ; 

long long calc(int A , int state)
{
    if ( A == 0 ) return 1 ; 
    
    if( dp[state][A] == -1 )
    {
        if ( state == 0 )
        {
            long long SS =(ss*calc( A-1 , 0 ) )%MOD; 
            long long SD =(sd*calc( A-1 , 1 ) )%MOD; 
            dp[state][A] =(SS + SD)%MOD ; 
        }
        
        if ( state == 1 )
        {
            long long DS =(ds*calc( A-1 , 0 ) )%MOD; 
            long long DD =(dd*calc( A-1 , 1 ) )%MOD; 
            dp[state][A] =(DS + DD)%MOD ;
        }
    }
    return dp[state][A] ; 
}

int Solution::solve(int A) {
    
    dp.assign( 2 , vector <long long> ( A , -1 ) ) ; 
    
    ss = sd = 0 ; 
    for ( int i = 0 ; i < 4 ; i++ )
    {   
        if ( i == 0 ) continue ; 
        
        for ( int j = 0 ; j < 4 ; j++ )
        {   
            if ( j == i or j == 1 ) continue ; 
            
            for ( int k = 0 ; k < 4 ; k++ )
            {
                if ( k == j or k == 0) continue ;     
                
                if ( k == i ) ss++ ; else sd++ ; 
            }
        }
    }
    
    //cout<<ss<<" "<<sd<<endl ; 
    
    ds = dd = 0 ; 
    for ( int i = 0 ; i < 4 ; i++ )
    {   
        if ( i == 0 ) continue ; 
        
        for ( int j = 0 ; j < 4 ; j++ )
        {   
            if ( j == i or j == 1 ) continue ; 
            
            for ( int k = 0 ; k < 4 ; k++ )
            {
                if ( k == j or k == 2) continue ;     
                
                if ( k == i ) ds++ ; else dd++ ; 
            }
        }
    }
    
    //cout<<ds<<" "<<dd<<endl ;
    
    long long state1 = 12*calc ( A-1 , 0 ) ; 
    long long state2 = 24*calc ( A-1 , 1 ) ; 
    
    return (state1 + state2)%MOD ; 
}
