// Problem Link: https://leetcode.com/problems/shortest-palindrome/
// Author : Himanshu Mundhra

/*********************************************************************************************************
 * Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. 
 * Find and return the shortest palindrome you can find by performing this transformation.
 * 
 *      Example 1:
 *      Input: "aacecaaa"
 *      Output: "aaacecaaa"
 * 
 *      Example 2:
 *      Input: "abcd"
 *      Output: "dcbabcd"
 * 
***********************************************************************************************************/

class Solution {
public:
          
    string shortestPalindrome(string s) {
        string rev_s(s.rbegin(), s.rend());
        string tmp = s + "#@$%&" + rev_s;

        vector<int> LPB(tmp.size(), 0);
        int i = 1, len = 0;
        while(i < LPB.size())
        {
            if (tmp[i] == tmp[len])
                LPB[i++] = ++len;
            else
                if (len) len = LPB[len-1];
                else i++;
        }
        
        return rev_s + string(s.begin() + LPB.back() , s.end());
    }
};
