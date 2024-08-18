#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
    };

    node *head;
    node *tail;
    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode) {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode) {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node *resnode = m[key_];
            int res = resnode->val;
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            node *existingnode = m[key_];
            deletenode(existingnode);
            m.erase(key_);
        }
        if (m.size() == cap) {
            node *lru = tail->prev;
            m.erase(lru->key);
            deletenode(lru);
            delete lru;
        }
        addnode(new node(key_, value));
        m[key_] = head->next;
    }

    ~LRUCache() {
        while (head) {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Create a cache with capacity 2
    LRUCache cache(2);

    // Perform operations
    cache.put(1, 1); // cache is {1=1}
    cout << "Get 1: " << cache.get(1) << endl; // returns 1

    cache.put(2, 2); // cache is {1=1, 2=2}
    cout << "Get 2: " << cache.get(2) << endl; // returns 2

    cache.put(3, 3); // evicts key 1, cache is {2=2, 3=3}
    cout << "Get 1: " << cache.get(1) << endl; // returns -1 (not found)

    cache.put(4, 4); // evicts key 2, cache is {3=3, 4=4}
    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (not found)

    cout << "Get 3: " << cache.get(3) << endl; // returns 3

    cout << "Get 4: " << cache.get(4) << endl; // returns 4

    return 0;
}
