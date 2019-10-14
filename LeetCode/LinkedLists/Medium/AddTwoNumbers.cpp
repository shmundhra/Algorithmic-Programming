/* https://leetcode.com/problems/add-two-numbers/ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        
        while(1){            
            int temp = carry;            
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }            
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }
            
            carry = temp/10;            
            tmp->val = temp%10;
            
            if (carry or l1 or l2) {
                tmp->next = new ListNode(0);
                tmp = tmp->next;
            } else {
                break;
            }
        }
        return head;
    }
}
