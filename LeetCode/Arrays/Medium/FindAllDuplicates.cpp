// Problem Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Author : Himanshu Mundhra

/******************************************************************************************
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.
 * Find all the elements that appear twice in this array.
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 *      Input:  [4,3,2,7,8,2,3,1]
 *      Output: [2,3]
 *
*******************************************************************************************/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = 4;

        for (auto &i : nums) {
            i--;
            i *= (n);
        }
        // for (auto i : nums) cout << i << " "; cout << endl;

        for (auto i : nums) {
            nums[i/n]++;
        }

        vector<int> ans;
        for (int i = 0 ; i < nums.size(); i++) {
            // cout << nums[i] << "@" << i << "-" << nums[i]%n << endl;
            if (nums[i]%n == 2) {
                ans.push_back(i+1);
            }
        }
        return ans;

    }
};
