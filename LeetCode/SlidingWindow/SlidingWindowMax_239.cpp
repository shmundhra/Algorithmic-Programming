// Problem Link : https://leetcode.com/problems/sliding-window-maximum/
// Author : Himanshu Mundhra

/******************************************************************************************
 * Given an array nums, there is a sliding window of size k which is moving from the
 * very left of the array to the very right. You can only see the k numbers in the window.
 * Each time the sliding window moves right by one position. Return the max sliding window.
 *
 * Example:
 *      Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 *      Output: [3,3,5,5,6,7]
 *      Explanation:
 *          Window position                Max
 *          ----------------------------------
 *          [1  3  -1] -3  5  3  6  7       3
 *           1 [3  -1  -3] 5  3  6  7       3
 *           1  3 [-1  -3  5] 3  6  7       5
 *           1  3  -1 [-3  5  3] 6  7       5
 *           1  3  -1  -3 [5  3  6] 7       6
 *           1  3  -1  -3  5 [3  6  7]      7
 *
********************************************************************************************/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> DS;

        for(int i = 0 ; i < k ; i++)
        {
            while(!DS.empty() and DS.back() < nums[i]) DS.pop_back();
            DS.push_back(nums[i]);
        }

        for(int i = k ; i < nums.size(); i++)
        {
            ans.push_back(DS.front());
            if (DS.front() == nums[i-k]) DS.pop_front();
            while(!DS.empty() and DS.back() < nums[i]) DS.pop_back();
            DS.push_back(nums[i]);
        }
        if (!DS.empty()) ans.push_back(DS.front());

        return ans;
    }
};
