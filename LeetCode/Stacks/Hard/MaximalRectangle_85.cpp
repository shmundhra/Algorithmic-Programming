// Problem Link: https://leetcode.com/problems/maximal-rectangle/
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.empty()) return 0;
        
        vector<vector<int>> a(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0 ; i < a.size(); i++)
            for(int j = 0 ; j < a[i].size(); j++)
                a[i][j] = matrix[i][j] - '0';
        // for(auto row: a) { for(auto cell : row) cout << cell << " "; cout << endl ; } cout << "---------\n" ;
        
        vector<vector<int>> b = a;
        for(int j = 0 ; j < a[0].size(); j++)
        {   
            int sum = 0;
            for(int i = 0 ; i < a.size() ; i++)
            {
                sum = sum*a[i][j] + a[i][j];
                b[i][j] = sum;
            }
        }
        // for(auto row: b) { for(auto cell : row) cout << cell << " "; cout << endl ; } cout << endl;
        
        vector<vector<int>> left = b;
        for(int i = 0 ; i < b.size(); i++) {
            left[i] = find(b[i], LEFT);
        }
        
        vector<vector<int>> right = b;
        for(int i = 0 ; i < b.size(); i++) {
            right[i] = find(b[i], RIGHT);
        }
        
        int ans = 0;
        for(int i = 0 ; i < b.size(); i++)
        {
            for(int j = 0 ; j < b[0].size(); j++)
            {
                ans = max(ans, b[i][j]*(right[i][j] - left[i][j] - 1));
            }
        }
        
        return ans;
    }
};