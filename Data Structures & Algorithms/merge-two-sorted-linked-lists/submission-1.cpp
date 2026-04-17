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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;

        if (list1 == nullptr) {
            if (list2 == nullptr) {
                return nullptr;
            }

            curr->val = list2->val;
            list2 = list2->next;

            while (list2) {
                ListNode* nod = new ListNode();
                nod->val = list2->val;
                list2 = list2->next;
                curr->next = nod;
                curr = nod;
            }

            return head;
        }

        if (list2 == nullptr) {
            curr->val = list1->val;
            list1 = list1->next;

            while (list1) {
                ListNode* nod = new ListNode();
                nod->val = list1->val;
                list1 = list1->next;
                curr->next = nod;
                curr = nod;
            }

            return head;
        }

        curr->val = (list1->val <= list2->val ? list1->val : list2->val);

        if (curr->val == list1->val) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }

        while (list1 && list2) {
            ListNode* nod = new ListNode();
            nod->val = (list1->val <= list2->val ? list1->val : list2->val);

            if (nod->val == list1->val) {
                list1 = list1->next;
            } else {
                list2 = list2->next;
            }

            curr->next = nod;
            curr = nod;
        }

        while (list1) {
            ListNode* nod = new ListNode();
            nod->val = list1->val;
            list1 = list1->next;
            curr->next = nod;
            curr = nod;
        }

        while (list2) {
            ListNode* nod = new ListNode();
            nod->val = list2->val;
            list2 = list2->next;
            curr->next = nod;
            curr = nod;
        }

        return head;
    }
};
