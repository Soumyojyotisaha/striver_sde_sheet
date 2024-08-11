#include <iostream>
using namespace std;

// Definition for a ListNode
struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    // Test case without a cycle
    Solution sol;
    bool result = sol.hasCycle(head);
    cout << "Cycle detected: " << (result ? "Yes" : "No") << endl;

    // Create a cycle for testing: 1 -> 2 -> 3 -> 4 -> 2
    head->next->next->next->next = head->next;
    result = sol.hasCycle(head);
    cout << "Cycle detected: " << (result ? "Yes" : "No") << endl;
    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
