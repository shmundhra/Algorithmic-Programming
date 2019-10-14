/* https://leetcode.com/problems/contiguous-array/ */

class Solution {
public:
    
    int getIndex(int sum, int n)
    {
        if (sum >= 0) return sum;
        return n + abs(sum);
    }
    
    int findMaxLength(vector<int>& nums) {
        
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == 0) nums[i] = -1;
        }
        
        for (int i = 1 ; i < nums.size() ; i++) {
            nums[i] += nums[i-1];
        }
        
        vector<int> sumL(2*nums.size()+1, INT_MIN);
        sumL[0] = -1;
        
        int ans = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            int sum = nums[i];
            int index = getIndex(sum, nums.size());
            if (sumL[index] == INT_MIN) {
                sumL[index] = i;
            } else {
                ans = max (ans, i - sumL[index]);
            }
        }
//         unordered_map<int, int> sumL;
//         unordered_map<int, int> sumR;
//         sumL[0] = -1;

//         int ans = 0;
//         for (int i = 0 ; i < nums.size(); i++)
//         {
//             int sum = nums[i];
//             if (sumL.find(sum) == sumL.end()){
//                 sumL[sum] = i;
//             } else {
//                 sumR[sum] = i;
//                 ans = max (ans, sumR[sum] - sumL[sum]);
//             }
//         }
        return ans;
    }
};
