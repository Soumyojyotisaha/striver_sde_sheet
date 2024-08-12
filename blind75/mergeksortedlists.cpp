#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergek(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        while (lists.size() > 1) {
            vector<ListNode*> ml;
            for (size_t i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                ml.push_back(merge2list(l1, l2));
            }
            lists = ml;
        }
        return lists[0];
    }

private:
    ListNode* merge2list(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        p->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " "; 
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<vector<int>> data = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists;

    for (const auto& nums : data) {
        lists.push_back(createList(nums));
    }

    Solution sol;
    ListNode* merged = sol.mergek(lists);

    // Print the merged list
    printList(merged);

    // Clean up allocated memory
    deleteList(merged);

    return 0;
}
