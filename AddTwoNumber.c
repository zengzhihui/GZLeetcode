/**
 * source: https://leetcode.com/problems/add-two-numbers/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    struct ListNode *result = NULL;
    
    int add = 0;
    struct ListNode *rNext = NULL;
    while(p != NULL && q != NULL) {
        struct ListNode *tmpNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmpNode->val = p->val + q->val + add;
        tmpNode->next = NULL;
        if (tmpNode->val >= 10) {
            tmpNode->val = tmpNode->val % 10;
            add = 1;
        } else {
            add = 0;
        }
        
        if (rNext == NULL) {
            rNext = tmpNode;
            result = tmpNode;
        } else {
            rNext->next = tmpNode;
            rNext = tmpNode;
        }
        p = p->next;
        q = q->next;
    }
    
    while(p != NULL) {
        p->val = p->val + add;
        if (p->val >= 10) {
            p->val = p->val % 10;
            add = 1;
        } else {
            add = 0;
        }
        if (rNext == NULL) {
            rNext = p;
        } else {
            rNext->next = p;
            rNext = p;
        }
        p = p->next;
    }
    
    while(q != NULL) {
        q->val = q->val + add;
        if (q->val >= 10) {
            q->val = q->val % 10;
            add = 1;
        } else {
            add = 0;
        }
        if (rNext == NULL) {
            rNext = q;
        } else {
            rNext->next = q;
            rNext = q;
        }
        q = q->next;
    }
    
    if (add > 0) {
        struct ListNode *tmpNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmpNode->val = add;
        tmpNode->next = NULL;
        if (rNext == NULL) {
            rNext = tmpNode;
        } else {
            rNext->next = tmpNode;
        }
    }
    return result;
}