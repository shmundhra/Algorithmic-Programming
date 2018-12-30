// https://www.interviewbit.com/problems/gray-code/

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
/*
    vector<int>  ans ; 
    stack < int > val , aux , rev ; 
    
    for ( int i = 0 ; i < A ; i++ ) 
    {
        val.push(A-i-1) ; 
    }
    
    int num = 0 ; 
    ans.push_back(0) ; 
    
    while ( !val.empty() )
    {
        int pos = val.top() ; 
        num = (num ^ (1<<pos)) ;
        
        ans.push_back( num ) ; 
        
        val.pop() ; 
        while ( !aux.empty() and aux.top() < pos )
        {
            rev.push(aux.top()) ; 
            aux.pop() ; 
        }
        aux.push(pos) ; 
        
        while ( !rev.empty() )
        {
            val.push(rev.top()) ; 
            rev.pop() ; 
        }
    }
    return ans ; 
*/

    vector < int > v = {0} ; 
    for ( int i = 0 ; i < A ; i++ )
    {
        int num = (1<<i) ;
        v.insert( v.end() , v.rbegin() , v.rend() ) ;
        //transform ( v.begin() + num , v.end() , v.begin()+num , [](int &x){x+=num;} ) ; 
        for ( int j = num ; j < v.size() ; j++ ) v[j] += num ; 
    }
    return v ; 
}
