#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct ListNode* nextPair = curr->next->next;
        struct ListNode* second = curr->next;

        // swap
        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = curr;
        curr = nextPair;
    }

    return newHead;
}