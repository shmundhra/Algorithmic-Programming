// Problem Link : https://leetcode.com/problems/subarrays-with-k-different-integers/
// Author : Himanshu Mundhra

/******************************************************************************************
 * Given an array A of positive integers, call a (contiguous, not necessarily distinct)
 * subarray of A good if the number of different integers in that subarray is exactly K.
 *
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 *
 * Return the number of good subarrays of A.
 *
 * Example 1:
 *      Input: A = [1,2,1,2,3], K = 2
 *      Output: 7
 *      Explanation: Subarrays formed with exactly 2 different integers:
 *                   [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
 *
 * Example 2:
 *      Input: A = [1,2,1,3,4], K = 3
 *      Output: 3
 *      Explanation: Subarrays formed with exactly 3 different integers:
 *                   [1,2,1,3], [2,1,3], [1,3,4].
 *
 * Note:
 *      1 <= A.length <= 20000
 *      1 <= A[i] <= A.length
 *      1 <= K <= A.length
 *
******************************************************************************************/

// O(N) HACK SOLUTION
class Solution {
public:
    
    int solve(vector<int>& A, int k)
    {
        int ans = 0;
        int active = 0;
        vector<int> count(A.size()+1, 0);
        
        int i, j;
        for(i = 0, j = 0; j < A.size(); j++)
        {
            if (count[A[j]] == 0)
            {
                active++;
            }
            count[A[j]]++;
            
            while(active > k)
            {
                ans += j-i;
                count[A[i]]--;
                if (count[A[i]] == 0)
                {
                    active--;
                }
                i++;
            }
        }
        for( ; i < j ; i++ ) ans += j-i;
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int k) {
        
        int ans1 = solve(A, k);     // Less Than Eq to K
        int ans2 = solve(A, k-1);   // Less Than Eq to K-1
        cout << ans1 << " " << ans2 << endl;
        return ans1 - ans2;         // Equal to K
    }
};


// O(N) SOLUTION
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        int actcount = 0;
        vector<int>count(A.size()+1,0);
        vector<int>lastindexmap(A.size()+1,-1);
        int minlastindex = 0;

        for (int i = 0, j = 0; j < A.size(); j++)
        {
            if (count[A[j]] == 0)
            {
                actcount++;
                count[A[j]]++;
                lastindexmap[A[j]] = j;
            }
            else
            {
                /* Checking if this A[j] will alter the MinLastIndex in the Window[i..j] */
                // if (A[j] == A[minlastindex])
                if (lastindexmap[A[j]] == minlastindex)
                {
                    // Find Next "Minimum Last Index"
                    for(minlastindex = minlastindex+1;
                        minlastindex != lastindexmap[A[minlastindex]] and minlastindex < j;
                        minlastindex++);
                }
                count[A[j]]++;
                lastindexmap[A[j]] = j;
            }

            while (actcount > K)
            {
                count[A[i]]--;
                if (count[A[i]] == 0) {
                    actcount--;
                    // if (A[i] == A[minlastindex])
                    // if (lastindexmap[A[i]] == minlastindex)
                    if (i == minlastindex)
                    {
                        // Find Next "Minimum Last Index"
                        for(minlastindex = minlastindex+1;
                            minlastindex != lastindexmap[A[minlastindex]] and minlastindex < j;
                            minlastindex++);
                    }
                    lastindexmap[A[i]] = -1;
                }
                i++;
            }

            if (actcount == K) {
                ans += minlastindex - i + 1;
                // cout << i << "..." << minlastindex << "-" << j << endl;
            }


        }

        return ans;
    }
};

// O(NLOGN) Solution
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        int actcount = 0;
        vector<int>count(A.size()+1,0);
        map<int,int> count;
        map<int,int> lastindexmap;
        set<int> lastindexset;

        for (int i = 0, j = 0; j < A.size(); j++)
        {
            if (count[A[j]] == 0) {
                actcount++;
                count[A[j]]++;
                lastindexmap[A[j]] = j;
                lastindexset.insert(j);
            }
            else
            {
                count[A[j]]++;
                lastindexset.erase(lastindexmap[A[j]]);
                lastindexmap[A[j]] = j;
                lastindexset.insert(j);
            }

            while (actcount > K)
            {
                count[A[i]]--;
                if (count[A[i]] == 0) {
                    actcount--;
                    count.erase(A[i]);
                    lastindexset.erase(lastindexmap[A[i]]);
                    lastindexmap.erase(A[i]);
                }
                i++;
            }

            if (actcount == K) {
                ans += *lastindexset.begin() - i + 1;
                // cout << i << "..." << *lastindexset.begin() << "-" << j << endl;
            }


        }

        return ans;
    }
};