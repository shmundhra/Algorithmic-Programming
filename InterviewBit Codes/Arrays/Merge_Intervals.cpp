// https://www.interviewbit.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector < int > A , D ;
    vector < Interval > V ; 
    
    int st = min ( newInterval.start , newInterval.end ) ; 
    int en = max ( newInterval.start , newInterval.end ) ; 
     
    for ( i = 0 ; i < intervals.size() ; i++ )
    {
        A.push_back(intervals[i].start) ;
        A.push_back(intervals[i].end) ;
        D.push_back(-1*intervals[i].start) ;
        D.push_back(-1*intervals[i].end) ;
        
    }
    reverse( D.begin() , D.end() ) ; 
    
    auto left  = lower_bound( D.begin() , D.end() , -1*st ) ; 
    auto right = lower_bound( A.begin() , A.end() , en  ) ; 
    
    
    int r = right - A.begin() ; 
    int l = D.size()-1 - ( left - D.begin() ) ; 
    
    for ( int i = 0 ; i < l ; i+=2)
    {
        V.push_back( Interval( A[i],A[i+1] ) ) ; 
    }
    
    switch ( ((l+2)%2)*2 + (r%2) )
    {
        case 0 :  V.push_back( Interval( A[l] , en   ) ) ;  // even-even
                    break ;  
        case 1 :  V.push_back( Interval( A[l] , A[r] ) ) ;   // even-odd 
                    break ; 
        case 2 :  V.push_back( Interval( st   , en   ) ) ; // odd-even
                    break ; 
        case 3 :  V.push_back( Interval( st   , A[r] ) ) ;  // odd-odd
                    break ; 
    }
    
    for ( int i = 2*( (r+1)/2 ) ; i < A.size() ; i+=2) 
    {
         V.push_back( Interval( A[i],A[i+1] ) ) ; 
    }
    
    
    
    return V ; 
    
}