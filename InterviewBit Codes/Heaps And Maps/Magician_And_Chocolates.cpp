// https://www.interviewbit.com/problems/magician-and-chocolates/

int Solution::nchoc(int A, vector<int> &B) {
    /*
    multiset < int , greater<int> > s ( B.begin() , B.end() ) ; 
    
    long long ans = 0 ; 
    
    for ( int i = 0 ; i < A ; i++ )
    {
        long val = *( s.begin() ) ; 
        
        ans = (ans + val )%1000000007 ; 
        
        s.erase ( s.begin() ) ; 
        
        val/=2 ; 
        s.insert(val) ; 
    }
    return (int)ans ; */
    
    /*
    long ans = 0 ; 
    make_heap(B.begin() , B.end() ) ; 
    
    for ( int i = 0 ; i < A ; i++ )
    {
        ans = ( ans + B[0] ) % 1000000007 ; 
        pop_heap( B.begin() , B.end()  ) ; 
        B[ B.size()-1 ] /=2 ; 
        push_heap( B.begin() , B.end() ) ; 
    }
    return (int)ans ; 
    */
    
    priority_queue < int > pq ( B.begin() , B.end() ) ; 
    long ans = 0 ; 
    
    for ( int i = 0 ; i < A ; i++ )
    {
        ans += pq.top() ; 
        ans %= 1000000007 ; 
        pq.push(pq.top()/2) ; 
        pq.pop() ; 
    }
    return (int)ans ;
    
}
