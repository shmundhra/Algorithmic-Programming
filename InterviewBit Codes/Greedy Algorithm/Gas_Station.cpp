// https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size() ; 
    long long sum , iter , start ; 
    
    for ( start = 0 ; start < n ; )
    {   
        sum = 0 ; 
        for ( iter = start ;  iter < start + n ; iter++ )
        {
            sum += A[ iter%n ] - B[ iter%n ] ; 
            
            if ( sum < 0 )
            {
                start = iter + 1 ; 
                break ; 
            }
        }
        if ( iter == start + n )
        {
            return start ; 
        }
    }
    
    return -1 ; 
}
