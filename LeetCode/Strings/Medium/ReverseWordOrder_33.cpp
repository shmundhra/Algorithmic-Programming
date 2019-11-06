// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Author : Himanshu Mundhra

/************************************************************************************
 * Given an input string, reverse the string word by word.
 * Note:
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. 
 * However, your reversed string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in the reversed string.
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing spaces.
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 * 
****************************************************************************************/

// O(1) Space Solution

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        s.push_back(' ');
        
        int pos = 0;
        for(int i = 0, j = 0; j < s.length() ;)
        {   
            if (s[j] == ' ')
            {
                if (i == j) {
                    i++, j++;
                }
                else {
                    for(int l = i, r = j-1; l <= r ; l++, r--) swap(s[l], s[r]) ;
                    if (pos) s[pos++] = ' ';
                    while(i < j) s[pos++] = s[i++];
                }
            }
            else
            {
                j++;
            }
        }
        return string(s.begin(), s.begin() + pos);
    }
};
