/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string ans = "";
        auto temp = head;
        while(temp){
            ans.push_back(temp->val+'0');
            temp=temp->next;
        }


        int number = 0;
        reverse(ans.begin(),ans.end());
        for(int i = ans.length()-1;i>=0;i--){
            number += pow(2,i)*(ans[i]-'0');
        }
        return number;
    }
};