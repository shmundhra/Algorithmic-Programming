/* https://leetcode.com/problems/two-sum/ */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for ( int i = 0 ; i < nums.size(); i++ ) {
        //     for ( int j = i+1 ; j < nums.size(); j++ ) {
        //         if ( nums[i] + nums[j] == target ) { 
        //             return vector<int>{i, j};
        //         }
        //     }
        // }
        // return vector<int>{};
        
        vector <pair<int,int> > v(nums.size());
        for(int i = 0 ; i < nums.size() ; i++) {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());
        
        for (int i = 0 , j = v.size()-1; i < j ;) {
            if ( v[i].first + v[j].first == target) {
                return vector<int>{v[i].second, v[j].second};
            }
            if ( v[i].first + v[j].first < target) {
                i++;
            }
            else {
                j--;
            }            
        }
        return vector<int>{};
    }
};
