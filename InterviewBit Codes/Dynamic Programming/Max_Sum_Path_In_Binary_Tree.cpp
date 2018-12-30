// https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long ll ; 

//ll greatest ; 

ll maxm ( ll a , ll b , ll c )
{
    ll high = a ; if ( b > high ) high = b ; if ( c > high ) high = c ; return high;  
}

pair < ll,ll > solve ( TreeNode *T )
{
    if ( !T )
    {
        return {INT_MIN,0} ; 
    }
    
    //if ( T->val > greatest ) greatest = T->val ; 
    
    pair<ll,ll> lef = solve ( T->left ) ; 
    pair<ll,ll> righ = solve ( T->right ) ; 
    
    ll diam = lef.second + T->val + righ.second ; 
    
    ll maxi  = maxm ( diam , lef.first , righ.first ) ; 
    ll spath = maxm (0 , lef.second + T->val , righ.second + T->val ) ; 
    
    return {maxi , spath} ; 
}
 
int Solution::maxPathSum(TreeNode* A) {
    
    //greatest = INT_MIN ; 
    pair<ll,ll> p =  solve ( A ) ; 
    
    //if ( !p.first ) return greatest ; 
    
    return p.first ; 
    
}
