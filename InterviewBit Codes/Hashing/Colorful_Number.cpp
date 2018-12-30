// https://www.interviewbit.com/problems/colorful-number/

int Solution::colorful(int A) {
    
    if ( A < 10 ) return 1 ; 
    
    vector < int > V ; 
    
    for ( int i = A ; i > 0 ; i/=10 )
    {   
        if ( i%10 < 2 ) return 0 ; 
        V.push_back( i%10 ) ; 
    }
    reverse ( V.begin() , V.end() ) ; 
    
    unordered_map < int , int > m ; 
    
    for ( int len = 1 ; len <= V.size() ; len++ )
    {   
          int prod = 1 ; 
          for ( int i = 0 ; i < len ; i++ ) prod *= V[i] ; 
          
          if ( m.find(prod) != m.end() )
          {
             return 0 ; 
          }
          else
          {   
             // cout<<prod<<"  " ; 
              m[prod] = 1 ; 
          }
          
          for ( int i = len ; i + len <= V.size() ; i++ )
          {
              prod = prod * V[i] / V[i-len] ; 
              
              if ( m.find(prod) != m.end() )
              {
                 return 0 ; 
              }
              else
              { 
                  //cout<<prod<<"  " ;
                  m[prod] = 1 ; 
              }
          }
          
    }
    return 1 ; 
}
