/* https://leetcode.com/problems/minimum-increment-to-make-array-unique/ */

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) 
    {   
        if (A.size() == 0) return 0;
        
        sort(A.begin(), A.end());
        map <int, int> m;
        m[A[0]] = 1;
        
        vector<int> temp = A;
        for (int i = 1 ; i < A.size(); i++) {
            if (m.find(A[i]) != m.end()) {   
                temp[i] = temp[i-1] + 1;
            }
            m[temp[i]] = 1;
        }        
        //sort(temp.begin(), temp.end());        
        for (int i = 0 ; i < temp.size() ; i++) cout << temp[i] << " "; cout << endl;
        
        int ans = 0;
        for (int i = 0 ; i < A.size(); i++) {
            ans += abs(A[i] - temp[i]);
        }
        
        return ans;
    }
};
