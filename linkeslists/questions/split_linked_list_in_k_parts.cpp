#include <bits/stdc++.h>
using namespace std;

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
class Solution
{
public:
    int getlen(ListNode *head)
    {
        int len = 0;
        if (head == NULL)
        {
            return 0;
        }
        while (head != NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    // vector<int> list(ListNode* head){
    //     vector<int> ll;
    //     while(head!= NULL){
    //       ll.push_back(head->val);
    //       head = head->next;
    //     }
    // }

    // time complexity is O(n) and space is O(k)
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans;
        int n = getlen(head);
        int first = n / k;
        int onemore = n % k;
        ListNode *temp = head;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(temp);
            int si = first + (i < onemore ? 1 : 0);
            for (int j = 0; j < si - 1; j++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }
            if (temp != NULL)
            {
                ListNode *prev = temp;
                temp = temp->next;
                prev->next = NULL;
            }
        }
        while (ans.size() < k)
        {
            ans.push_back(NULL);
        }
        return ans;

        return ans;
    }
};

int main()
{
    return 0;
}