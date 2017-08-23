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
    ListNode* deleteDuplicates(ListNode* head) {
        // eg. 1->1->2->3->3
        // Create a list node res for return and another list node cur for move.
        // The inner while statement will find the last duplicate, and we can link the
        // cur to the next node of this last duplicate. Then move cur and head node to
        // continue.
        if (head==nullptr || head->next == nullptr) return head;
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* cur = head;
        while (head!=nullptr) {
            while (head->next!=nullptr && head->val == head->next->val) {
                head = head->next;
            }
            cur->next = head->next;
            cur = cur->next;
            head = head->next;
        }
        return res->next;
    }
};


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
    ListNode* deleteDuplicates(ListNode* head) {
        // A recursive solution. Notice at the return statement, if the value of head == the value of head->next,
        // return head->next. If not, return head.
        // eg.1->1->2->3->3, return 1->1->2->3
        //                             !  3->
        // return seconde 1, but the first 3 still links to the last 3 and the first 1 still links to second 1.
        if (head == nullptr || head->next == nullptr) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};