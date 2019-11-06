// Problem Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author : Himanshu Mundhra


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int num = words.size();
        int len = num ? words.front().length() : 0;

        map<string,int> m;
        map<int, int> req_count;
        for(int i = 0 ; i < num; i++) 
        {
            if (m.find(words[i]) == m.end()) m[words[i]] = i; 
            req_count[m[words[i]]]++;
        }
        int uni_reqd = m.size();

        vector<int> ans;

        for(int start = 0 ; start < len ; start++)
        {
            vector<int> hash;
            for(int i = start; i+len <= s.length(); i+=len)
            {
                string tmp(s.begin()+i, s.begin()+i+len);
                if (m.find(tmp) == m.end())
                    hash.push_back(-1);
                else 
                    hash.push_back(m[tmp]);
            }
            
            int uni_c = 0;
            map<int,int> count;
            for(int i = 0, j = 0; j < hash.size(); )
            {   
                if (hash[j] == -1)           // Out Of Vocabulary
                {
                    while(i != j) {
                        if (count[hash[i]] == req_count[hash[i]]) uni_c--;
                        count[hash[i++]]--;
                    }
                    i++, j++;
                    continue;
                }
                
                if (count[hash[j]] == req_count[hash[j]])        // Repeated Vocabulary
                {
                    while(hash[i] != hash[j])
                    {
                        if (count[hash[i]] == req_count[hash[i]]) uni_c--;
                        count[hash[i++]]--;
                    }
                    if (count[hash[i]] == req_count[hash[i]]) uni_c--;
                    count[hash[i++]]--;
                }
                
                count[hash[j]]++ ;
                if (count[hash[j]] == req_count[hash[j]]) uni_c++;
                if (uni_c == uni_reqd) ans.push_back(i*len + start);
                j++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


/*
class Solution {
public:
    
    vector<int> ans;
    int n, m;
    void find(int i, int cnt, string& s, map<string,int>& str, int pos)
    {
        if( i + (n-cnt)*m > s.length())
            return;

        if(cnt == n)
        {
            ans.push_back(pos);
            return;
        }
        
        string ss = s.substr(i, m);
        if(str[ss] > 0)
        {
            str[ss] -= 1;
            find(i+m, cnt+1, s, str, pos);
            str[ss] += 1;
        }
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
    
        ans.clear();
        
        if(s.length() == 0 or words.size() == 0)
            return ans;
        
        n = words.size();
        m = words[0].length();
        
        if(n*m > s.length())
            return ans;
        
        map<string, int> str;
        for(int i = 0; i < n; i++)
            str[words[i]]++;
        
        for(int i = 0; i < s.length(); i++)
        {
            find(i, 0, s, str, i);
        }
        
        return ans;
    }
};
*/