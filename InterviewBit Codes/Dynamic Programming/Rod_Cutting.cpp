// https://www.interviewbit.com/problems/rod-cutting/

/*vector < int > arr;
vector < vector <int>  > par;
/*vector < vector <int>  > dp;
vector < int > ans;
int func(int start,int end,int lol,int sed)
{
    if(start>end) return 0;
    if(start==end) return sed-lol;
    if(dp[start][end]!=-1) return dp[start][end];
    
    int i;
    int xd = 100000;
    int bst;
    for(i=start;i<=end;i++)
    {
        int bc = func(i+1,end,arr[i],sed)+func(start,i-1,lol,arr[i])+sed-lol;
        if(bc<xd)
        {
            xd= bc;
            bst = i;
        }
    }
    dp[start][end] = xd;
    par[start][end] = bst;
    return xd;
}
void randi(int l,int r)
{
    if(l>r) return;
    
    if(l==r and l>=0)
    {
        ans.push_back(arr[l]);
        return;
    }
    
    ans.push_back(arr[par[l][r]]);
    randi(l,par[l][r]-1);
    randi(par[l][r]+1,r);
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    
    dp.clear(); par.clear();
    int n = B.size();
    dp.resize(n); par.resize(n);
    ans.clear();
    arr = B;
    
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            dp[i].push_back(-1),par[i].push_back(-1);
    }
    func(0,n-1,0,A);
    randi(0,n-1);
    return ans;
}

*/

    dp.clear(); par.clear(); ans.clear(); arr.clear();
    
    ll n = B.size();
    
    dp.resize(n); par.resize(n);
    
    for(auto v:B) arr.push_back(v);
    
    ll i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            dp[i].push_back(-1),par[i].push_back(0);
    }
    
    for(i=0;i<n;i++)
    {
        ll left = (i-1>=0) ? arr[i-1]:0;
        ll right = (i+1<n) ? arr[i+1]:A;
        dp[i][i] = right - left;
        par[i][i]=i;
    }
    for(i = 1 ; i < n ; i++ )
    {
        for( j = 0 ; j+i < n ; j++ )
        {
            ll bst, xd = 1e18 ;
            ll last = j+i;
            for(int k = j; k <= last ; k++)
            {
                ll bc = 0;
                if(k > j )
                    bc += dp[j][k-1] ;
                if(k < last)
                    bc += dp[k+1][last];
                    
                ll left = (j-1>=0) ? arr[j-1]:0;
                ll right = (last+1<n) ? arr[last+1]:A;
                // cout<<right-left<<"\n";
                bc+=(right-left);
                if(bc<xd)
                {
                    xd=bc,bst=k;
                }
                
            }
            dp[j][last]=xd,par[j][last]=bst;
        }
    }
    // for(i=0;i<n;i++){
    //   for(j=0;j<n;j++)
    //     cout<<dp[i][j]<<" ";
    //   cout<<"\n";
    // }
    // cout<<dp[0][n-1]<<"\n";
    randi(0,n-1);



//-------------------------------------------------------------------------------------
typedef long long ll ; 

ll solve ( vector < vector < ll  >  > &path , ll x , ll y , vector< ll > &ans )
{   
    if ( path[x][y] == -1 ) return 0 ; 
    
    ans.push_back( path[x][y] ) ; 
    solve ( path , x , path[x][y] , ans ) ; 
    solve ( path , path[x][y] , y , ans ) ; 
}

vector<int> Solution::rodCut(int a, vector<int> &b) {
    
    ll A = (ll)a ; vector<ll> B ; for ( auto x : b ) B.push_back((ll)x) ; 
    
    B.insert(B.begin() , 1 , 0 ) ; 
    B.push_back(A) ; 
    
    ll n = B.size() ; 
    
    vector < vector < ll  >  > dp ( n , vector < ll  > ( n , 0) ) ; 
    vector < vector < ll  >  > path ( n , vector < ll  > ( n , -1) ) ; 
    
    for ( ll  len = 2 ; len < n ; len ++ )
    {
        for ( ll  start = 0 ; start+len < n ; start++ )
        {
            ll cost = INT_MAX/2 ; 
            ll  pos = -1 ; 
            for ( ll  cut = start + 1 ; cut < start+len ; cut++ )
            {
                if ( dp[start][cut] + dp[cut][start+len] < cost )
                {
                    cost = dp[start][cut] + dp[cut][start+len] ; 
                    pos = cut ; 
                }
            }
            path[start][start+len] = pos ; 
            dp[start][start+len] = ( B[start+len] - B[start] ) ; 
            
            if ( pos != -1 ) dp[start][start+len] += cost  ; 
            
        }
    }
    vector < ll  > ans ; ans.clear() ; 
    
    solve ( path , 0 , n-1 , ans ) ; 
    
    for ( ll  i = 0 ; i < (ll)ans.size() ; i++ ) ans[i] = B[ans[i]] ; 
    
    vector < int > res ; 
    for ( ll i = 0 ; i < (ll)ans.size() ; i++ ) res.push_back((int)ans[i]) ; 
    
    return res ; 
    
}
