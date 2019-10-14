/* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ */

class Solution {
public:
    int findMin(vector<int>& nums) {
        nums.push_back(nums[0]);
        nums.push_back(nums[1]);
        
        int low = 0 + 1;
        int high = nums.size()-1 -1;
        
        while (low < high) {
            int mid = low + (high - low)/2;
            cout << mid << endl;
            
            if (nums[mid] < nums[mid-1] and nums[mid] < nums[mid+1])
                return nums[mid];
            
            if (nums[mid] <= nums[0]) high = mid;
            else low = mid + 1;
        }
        return nums[0];
    }
};
