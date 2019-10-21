// Problem Link : https://leetcode.com/problems/sliding-window-median/
// Author : Himanshu Mundhra

/*************************************************************************************************************
 * Median is the middle value in an ordered integer list. If the size of the list is even,
 * there is no middle value. So the median is the mean of the two middle value.

 * Examples:
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array
 * to the very right. You can only see the k numbers in the window. Each time the sliding window
 * moves right by one position. Your job is to output the median array for each window in the original array
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position               Median
 * ------------------------------------
 * [1  3  -1] -3  5  3  6  7       1
 *  1 [3  -1  -3] 5  3  6  7      -1
 *  1  3 [-1  -3  5] 3  6  7      -1
 *  1  3  -1 [-3  5  3] 6  7       3
 *  1  3  -1  -3 [5  3  6] 7       5
 *  1  3  -1  -3  5 [3  6  7]      6
 *
 * Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 *
 * Note: You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
**************************************************************************************************************/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> tmp(nums.begin(), nums.begin()+k);
        sort(tmp.begin(), tmp.end());

        multiset<long> left(tmp.begin(), tmp.begin()+k/2);
        multiset<long> right(tmp.begin()+k/2, tmp.end());
        if (left.empty()) left.insert(-1e10);

        vector<double> ans;
        double median, l, r, val2del , val2ins;
        for (int i = k; i < nums.size(); i++)
        {
            //l = *(--left.end()), r = *right.begin();
            // if (k&1) {
            //     median = r;
            // } else {
            //     median = l + (r-l)/2;
            // }

            l = *(left.rbegin()), r = *right.begin();
            median = r - (r-l)*(1 - k&1)/2;
            ans.push_back(median);

            val2del = nums[i-k], val2ins = nums[i];
            if (val2del <= l)
            {
                left.erase(left.find(val2del));

                if (val2ins <= r) {
                    left.insert(val2ins);
                } else {
                    left.insert(*right.begin());
                    right.erase(right.begin());
                    right.insert(val2ins);
                }
            }
            else
            {
                right.erase(right.find(val2del));

                if (val2ins >=l) {
                    right.insert(val2ins);
                } else {
                    right.insert(*(--left.end()));
                    left.erase(--left.end());
                    left.insert(val2ins);
                }
            }
        }
        //l = *(--left.end()), r = *right.begin();
        // if (k&1) {
        //     median = r;
        // } else {
        //     median = l + (r-l)/2;
        // }
        l = *(left.rbegin()), r = *right.begin();
        median = r - (r-l)*(1 - k&1)/2;
        ans.push_back(median);

        return ans;
    }
};
