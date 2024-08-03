#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* nextNode = nullptr) : val(x), next(nextNode) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head
        ListNode dummy(0, head);
        ListNode* l = &dummy;
        ListNode* r = head;

        // Move the right pointer n steps ahead
        while (n > 0 && r) {
            r = r->next;
            --n;
        }

        // Move both pointers until right pointer reaches the end
        while (r) {
            l = l->next;
            r = r->next;
        }

        // Remove the nth node from the end
        l->next = l->next->next;

        return dummy.next;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Remove the 2nd node from the end: should remove '4'
    ListNode* updatedHead = solution.removeNthFromEnd(head, 2);

    // Print the updated linked list
    cout << "Updated list: ";
    printList(updatedHead);

    // Clean up the linked list to prevent memory leaks
    while (updatedHead) {
        ListNode* temp = updatedHead;
        updatedHead = updatedHead->next;
        delete temp;
    }

    return 0;
}
