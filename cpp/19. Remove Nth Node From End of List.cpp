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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a listnode, whose next element is head.
        // Complete in one pass. Use two pointers, fast and slow. Fast move n steps first, then move fast and slow together.
        // If fast reaches end, slow would reach the one before the element that we need to remove. We have moved the slow
        // for (len - n) steps.
        if (head == nullptr || n<=0) return head;
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *slow(res), *fast(res);
        for (int i = 0; i < n; i++) {
            if (fast==nullptr) return nullptr;
            fast = fast->next;
        }
        while (fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return res->next;
        
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // head->1/next->2/next->3/next->4/next->5/null, n=2
        // fast->1/next->...
        // slow->head->1/next->...
        // fast stores the address for 1 (the val), and then for 2...
        // slow stores the address for head, for 1/next (the address for next), and then for 2/next...
        // after the while, fast stores the address for val 5, slow stores the address for next under 3.
        // *slow is next under 3, which is just the address for val 4. (*slow)->next is the next under 4,
        // which is the address for val 5. In this way, next under 3 would directly point to 5.
        // (*slow)->val is 4. head->val = 1, head->next = address for val 2.
        ListNode *fast = head, **slow = &head;
        for (int i = 1; i < n; i++) fast = fast->next;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = &((*slow)->next);
        }
        // tmp is an address, delete would find the address and delete the node 4/next.
        ListNode* tmp = *slow;
        *slow = (*slow)->next;
        delete tmp;
        return head;
    }
};

