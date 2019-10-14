/* https://leetcode.com/problems/search-in-rotated-sorted-array-ii/ */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        // return find(nums.begin(), nums.end(), target) != nums.end();
        
        if (nums.empty()) return false;        
        nums.push_back(nums[0]);
        nums.push_back(nums[1]);
        
//         int low = 0 + 1;
//         int high = nums.size()-1 - 1;
        
//         int mid;
//         int pivot = 0;
//         while (low < high) {
//             mid = low + (high-low)/2;
//             cout << low << " " << high << " " << mid << endl;
            
//             if (nums[mid] < nums[mid-1] and nums[mid] <= nums[mid+1]) {
//                 pivot = mid;
//                 break;
//             }
            
//             if (nums[mid] <= nums[0]) high = mid;
//             else low = mid + 1;
//         }
                
        int pivot;
        for (int i = 1; i < nums.size()-1; i++) {
            if (nums[i] < nums[i-1] and nums[i] <= nums[i+1]) {
                pivot = i;
                break;
            }
        }        
        cout << pivot << endl ; 
                
        auto itL = lower_bound(nums.begin(), nums.begin()+pivot, target);
        if (itL != nums.begin()+pivot and *itL == target) return true;
        
        auto itR = lower_bound(nums.begin()+pivot, nums.end()-2, target);
        if (itL != nums.end()-2 and *itR == target) return true;
        
        return false;
    }
};