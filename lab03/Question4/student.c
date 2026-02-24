#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    if (head == NULL) {
        return -1;  // safety (just in case)
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}