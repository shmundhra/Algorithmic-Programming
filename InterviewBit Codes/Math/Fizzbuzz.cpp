// https://www.interviewbit.com/problems/fizzbuzz/

vector<string> Solution::fizzBuzz(int A) {
    
    vector < string > v ; 
    for ( int i = 1 ; i <= A ; i++ )
    {
        if ( i%15 == 0 ) v.push_back("FizzBuzz") ; 
        else if ( i%5 == 0) v.push_back("Buzz") ; 
        else if ( i%3 == 0) v.push_back("Fizz") ; 
        else 
        {   
            string s ;
            for ( int j = i ; j > 0 ; j/=10 )
                s.push_back(j%10 +'0') ; 
            reverse(s.begin() , s.end() ) ; 
            v.push_back(s) ; 
        }
        
    }
}
