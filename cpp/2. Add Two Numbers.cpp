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
    // Create two linked list node as the head, one is used to move and the other is used to return at last.
    // Corner case: One linked list reaches the end and the other not. Should still consider about the carry.
    // If both linked lists reache the end and carry doesn't equal to 0, we should create a new listnode for it.
    // Consider all the corner cases in one while loop!
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur = new ListNode(-1);
        ListNode *curcopy = cur;
        int carry = 0;
        while( (l1 != nullptr) || (l2 != nullptr) || (carry > 0) ) {
            int add1 = l1 == nullptr ? 0 : l1->val;
            int add2 = l2 == nullptr ? 0 : l2->val;
            int sum = add1 + add2 + carry;
            carry = sum/10;
            int value = sum%10;
            ListNode *curNext = new ListNode(value);
            cur->next = curNext;
            cur = curNext;
            if(l1!=nullptr) l1 = l1->next;
            if(l2!=nullptr) l2 = l2->next;
        }
        return curcopy->next;
    }
};