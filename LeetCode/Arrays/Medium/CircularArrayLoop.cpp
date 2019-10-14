/* https://leetcode.com/problems/circular-array-loop/ */

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        
//         for (int i = 0 ; i < nums.size() ; i++ ) {
//             bool flag = false;
//             if (nums[i] < 0) flag = true;
            
//             nums[i] = abs(nums[i]) % nums.size();
//             if (flag) nums[i] = -nums[i];
            
//             cout << nums[i] << " ";
//         }cout << endl;
        
        
//         vector<int> flag(nums.size(), 0);
        
//         int curr = 0;
//         for (int start = 0 ; start < nums.size(); start++ )
//         {
//             if (flag[start] != 0 ) continue;
//             curr++;
//             cout << "\nStart at " << start << ": " ; 
//             for (int hop = start; ; )
//             {   
//                 cout << hop << " " ;
//                 if (flag[hop] == curr) {
//                     return true;
//                 }
//                 if (0 < flag[hop] and flag[hop] < curr) {
//                     break;
//                 }
                
//                 // flag[hop] == 0
//                 flag[hop] = curr;
                
//                 //goto next
//                 int next = (hop + nums[hop] + nums.size()) % nums.size();
//                 int x = (nums[hop] < 0);
//                 int y = (nums[next] < 0);
//                 if (nums[hop] == 0 or x^y)
//                 {
//                     break;
//                 }
//                 hop = next;
//             }
//         }
//         return false;
        
        for (int i = 0 ; i < nums.size() ; i++ ) {
            if ( nums[i] < 0 ) {
                nums[i] = abs(nums[i]) % nums.size();
                nums[i] *= -1;
            } else {
                nums[i] = abs(nums[i]) % nums.size();
            }            
            cout << nums[i] << " ";
        }cout << endl;
        
        for (int i = 0 ; i < nums.size() ; i++ ) {
            nums[i] *= 10000;
        }
                
        int curr = 0;
        for (int start = 0 ; start < nums.size(); start++ )
        {
            if (abs(nums[start])%10000 != 0 ) continue;
            curr++;
            
            cout << "\nStart at " << start << ": " ; 
            for (int hop = start; ; )
            {   
                cout << hop << " " ;
                
                int val = abs(nums[hop]) % 10000;
                if ( val == curr ) {
                    return true;
                }
                if (0 < val and val < curr) {
                    break;
                }
                
                // val == 0
                if (nums[hop] < 0) nums[hop] -= curr;
                else nums[hop] += curr;
                
                //goto next
                int next = (hop + nums[hop]/10000 + nums.size()) % nums.size();
                
                int x = (nums[hop] < 0);
                int y = (nums[next] < 0);
                if (nums[hop]/10000 == 0 or x^y)
                    break;
                
                hop = next;
            }
        }
        return false;
    }
};
