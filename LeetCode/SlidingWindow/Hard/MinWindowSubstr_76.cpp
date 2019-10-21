// Problem Link : https://leetcode.com/problems/minimum-window-substring/ 
// Author : Himanshu Mundhra

/*********************************************************************************************************** 
 * Given a string S and a string T,
 * find the minimum window in S which will contain all the characters in T 
 * in complexity O(n).
 * 
 * Example:
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 * 
***********************************************************************************************************/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> reqhash;
        int reqcount = 0;
        for(char c: t) {
            if (reqhash[c] == 0) reqcount++;
            reqhash[c]++;
        }
        
        int len = INT_MAX;
        pair<int,int> ans;
        unordered_map<char,int> hash;
        int count = 0;
        for(int i = 0,j = 0 ; j < s.length(); j++)
        {
            if (reqhash.find(s[j]) == reqhash.end()) continue;
                        
            hash[s[j]]++;
            if (hash[s[j]] == reqhash[s[j]]) {
                count++;
            }
            while(count == reqcount)
            {
                if (len > j+1 - i) {
                    len = j+1 - i;
                    ans = {i, j+1};
                }
                
                if (reqhash.find(s[i]) == reqhash.end()) {
                    i++;
                    continue;
                }
                
                if (hash[s[i]] == reqhash[s[i]]) {
                    hash[s[i]]--;
                    i++;
                    count--;
                }
                else {
                    hash[s[i]]--;
                    i++;
                }
            }
        }
        return string(s.begin()+ans.first, s.begin()+ans.second);
    }
};