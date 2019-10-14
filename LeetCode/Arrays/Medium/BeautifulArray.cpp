/* https://leetcode.com/problems/beautiful-array/ */

class Solution {
public:
    vector<int> beautifulArray(int N) {
        
        int bits = 0 ;
        for (int i = 1 ; i < N ; i*=2) bits++;
        // cout << bits << endl ;
        
        vector<int> ans{0};        
        for (int b = 0, power = 1 ; b < bits ; b++, power*=2) {
            vector<int> temp;
            for (int i = 0 ; i < ans.size(); i++)
            {
                temp.push_back(ans[i]);
                temp.push_back(ans[i]+power);
            }
            ans = temp;
        }
        vector<int> finalans;
        for(int i = 0 ; i < ans.size(); i++ ) {
            if ( ans[i] < N ) {
                finalans.push_back(ans[i]+1);
            }
        }
        
        return finalans;
    }
};
