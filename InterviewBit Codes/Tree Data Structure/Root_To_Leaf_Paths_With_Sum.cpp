// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Check (TreeNode* A, int B , vector<vector<int> > &ans , vector<int> &v , int index ) 
{
    if ( !A ) return 0 ; 
    
    if ( v.size() == index ) v.push_back(0) ; 
    v[index] = A->val ;
    
    if ( !(A->left) and !(A->right) ) 
    {
        if ( B == A->val )
        {
            ans.push_back( vector<int> ( v.begin() , v.begin()+index+1) ) ; 
            return 1 ; 
        }
        else return 0 ; 
    }
    
    Check ( A->left , B-A->val , ans , v , index+1) ; 
    Check ( A->right , B-A->val , ans , v , index+1) ; 
}
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int> > ans ; 
    vector<int> v ; 
    
    Check ( A , B , ans , v , 0 ) ;
    
    return ans ; 
}
