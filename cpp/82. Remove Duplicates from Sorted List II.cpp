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
        // eg. 1->1->2->3->3->5
        // Create two list nodes res and pre, and make them link to head. one for moving and the other for return.
        // Link pre/res to head, the head may be duplicated, but we would find out and change it after the inner while
        // statement. The inner while statement would stop at the node which is the last duplicate.
        if (head==nullptr) return head;
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* pre = res;
        while (head!=nullptr) {
            while (head->next!=nullptr && head->val == head->next->val) {
                head = head->next;
            }
            if (pre->next != head) {
                pre->next = head->next;
            } else {
                pre = pre->next;
            }
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
        // eg. 1->1->2->3->3->5
        // A recursive solution. if current node is not unique, return deleteDuplicates with head.next.
        // If current node is unique, link it to the result of next list made by recursive call.
        if (head == nullptr) return head;
        ListNode* prehead = head;
        while (head->next!=nullptr && head->val == head->next->val) {
            head = head->next;
        }
        if (prehead!=head) return deleteDuplicates(head->next);
        else head->next = deleteDuplicates(head->next);
        return head;
    }
};