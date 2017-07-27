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
    
    void testPointers() {
        
        ListNode *l1 = new ListNode(1);
        ListNode *tmp = l1;
        for (int i = 2; i < 10; i++) {
            tmp->next = new ListNode(i);
            tmp = tmp->next;
        }
        
        cout << "&l1: " << &l1 << endl;
        cout << "&(l1->next): " << &(l1->next) << endl;
        cout << "&(l1->val): " << &(l1->val) << endl;
        cout << "l1: " << l1 << endl;
        cout << "l1->next: " << l1->next << endl;
        cout << "l1->val: " << l1->val << endl;
        cout << "*l1.next: " << (*l1).next << endl;
        cout << "*l1.val: " << (*l1).val << endl;
        
        cout << "&(l1->next): " << &(l1->next) << endl;
        cout << "&(l1->next->next): " << &(l1->next->next) << endl;
        cout << "&(l1->next->val): " << &(l1->next->val) << endl;
        cout << "l1->next: " << l1->next << endl;
        cout << "l1->next->next: " << l1->next->next << endl;
        cout << "l1->next->val: " << l1->next->val << endl;
        cout << "(*(l1->next)).val: " << (*(l1->next)).val << endl;
        cout << "(*(l1->next)).next: " << (*(l1->next)).next << endl;
        
        
        
        int a = 100;
        int *p = &a;
        cout << "&p: " << &p << endl;
        cout << "p: " << p << endl;
        cout << "*p: " << *p << endl;
        cout << "&a: " << &a << endl;
        cout << "a: " << a << endl;
    }
};

/* result:
    &l1: 0x7fff88274ed8
    &(l1->next): 0xf1ce78
    &(l1->val): 0xf1ce70
    l1: 0xf1ce70
    l1->next: 0xf1ceb0
    l1->val: 1
    *l1.next: 0xf1ceb0
    *l1.val: 1
    &(l1->next): 0xf1ce78
    &(l1->next->next): 0xf1ceb8
    &(l1->next->val): 0xf1ceb0
    l1->next: 0xf1ceb0
    l1->next->next: 0xf1ced0
    l1->next->val: 2
    (*(l1->next)).val: 2
    (*(l1->next)).next: 0xf1ced0
    &p: 0x7fff88274ee0
    p: 0x7fff88274ed0
    *p: 100
    &a: 0x7fff88274ed0
    a: 100
*/