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
    ListNode* rotateRight(ListNode* head, int k) {
        // eg. 1->2->3->4->5->6
        // First, find out the length of the list. Make the list to be a cirle one.
        // Then start to find the node before the newhead (len - k%len), record the newhead and
        // make the node before link to a nullptr to be the new tail.
        ListNode *newhead, *tail = head;
        int len = 1;
        if (head == nullptr) return head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k%len;
        for (int i = 0; i < len-k; i++) tail = tail->next;
        newhead = tail->next;
        tail->next = nullptr;
        return newhead;
    }
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Find out the length of the linkedlist first. Then create two listnodes, fast and slow.
        // Initialize both to head. Fast moves k times first and then move fast and slow together
        // until fast reaches the last list node(one before nullptr) and slow would reach the new end
        // (one node before the new head). Make the new end points to nullptr next and fast points to
        // the origin head. Notice the corner case when len=0 and k=len.
        ListNode *cur = head, *fast = head, *slow = head;
        int len = 0;
        while (cur!=nullptr) {
            cur = cur->next;
            len++;
        }
        if (len==0) return head;
        k = k % len;
        if (k==0) return head;
        while (k-->0) fast = fast->next;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newhead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newhead;
    }
};