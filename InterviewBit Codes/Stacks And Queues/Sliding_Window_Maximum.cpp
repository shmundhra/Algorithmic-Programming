// https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

    deque<pair<int,int>> DS;
    for(int i = 0 ; i < min(B,(int)A.size()); i++)
    {
        while(!DS.empty() and (DS.back()).first <= A[i]) DS.pop_back();
        DS.push_back({A[i],i});
    }

    vector<int> ans;
    for(int i = B; i < (int)A.size(); i++)
    {
        ans.push_back((DS.front()).first);  // ans[i-B] for A[i-B.....i-1]
        if (i-B == (DS.front()).second) DS.pop_front();
        while(!DS.empty() and (DS.back()).first <= A[i]) DS.pop_back();
        DS.push_back({A[i],i});
    }
    if (!DS.empty()) ans.push_back((DS.front()).first);

    return ans;
}

//     vector < int > ans ;

//     if( A.empty() ) return ans ;

//     deque < int > d ;
//     d.push_back( A[0] ) ;

//     for ( int i = 1 ; i < B ; i++ )
//     {
//         while( !d.empty() and d.back() < A[i] ) d.pop_back() ;
//         d.push_back( A[i] ) ;
//     }

//     ans.push_back( d.front() ) ;

//     for ( int i = B ; i < (int)A.size() ; i++ )
//     {
//         if ( A[i-B] == d.front() ) d.pop_front() ;

//         while( !d.empty() and d.back() < A[i] ) d.pop_back() ;
//         d.push_back( A[i] ) ;

//         ans.push_back( d.front() ) ;
//     }

//     return ans ;
// }

