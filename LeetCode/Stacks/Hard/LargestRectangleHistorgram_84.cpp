// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: Himanshu Mundhra

class Solution {
public:
    enum FINDTYPE{LEFT, RIGHT};
    
    vector<int> find(vector<int> v, FINDTYPE type)
    {   
        if (type == RIGHT) reverse(v.begin(), v.end());
        v.insert(v.begin(), INT_MIN);
        
        stack<int> s;
        vector<int> ans; ans.reserve(v.size());

        s.push(0);
        for(int i = 1 ; i < v.size(); i++)
        {
            while(v[i] <= v[s.top()]) s.pop();
            ans.emplace_back(s.top());
            s.push(i);
        }
        // LEFT ans[] ranges as [0, v.size()-2]
        
        if (type == RIGHT) {
            reverse(ans.begin(), ans.end());
            for(auto& val: ans) val = v.size() - val;
            // RIGHT ans[] ranges as [2, v.size()]
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> leftsmall = find(heights, LEFT);
        vector<int> rightsmall = find(heights, RIGHT);
        
        int ans = 0;
        for(int i = 0 ; i < heights.size(); i++)
        {
            ans = max(ans, heights[i]*(rightsmall[i] - leftsmall[i] - 1));
        }
        
        return ans;
    }
};
