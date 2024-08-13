#include<bits/stdc++.h>
using namespace std;

void print() {
    cout << "raj";
}

int sum(int a, int b) {
    return a + b;
}

void explainpair() {
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;
    pair<int, pair<int, int>> pp = {1, {1, 3}};
    cout << pp.first << " " << pp.second.second << " " << pp.second.first << endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second << endl;
}

void explainvector() {
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // 1, 2

    vector<pair<int, int>> vec;
    vec.push_back({1, 3});
    vec.emplace_back(1, 6); // (1, 3), (1, 6)

    vector<int> v1(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v2(v1);    // Copy of v1

    // ITERATOR
    vector<int>::iterator it = v.begin(); // Points to the memory
    it++;
    cout << *(it) << " ";

    it = it + 2;
    cout << *(it) << " ";

    // Display the vector
    cout << v[0] << " " << v.at(0) << endl; // 10
    cout << v.back() << endl; // 30

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    for (auto it : v) { // Range-based for loop
        cout << it << " ";
    }
    cout << endl;

    // Deletion in a vector
    v.erase(v.begin() + 1); // {10, 12, 35}
    v.erase(v.begin() + 2, v.begin() + 4); // {10, 12}

    // Insertion in a vector
    vector<int> v3(2, 100); // {100, 100}
    v3.insert(v3.begin() + 1, 2, 10); // {100, 10, 10, 100, 100}

    vector<int> copy(2, 50);
    v3.insert(v3.begin(), copy.begin(), copy.end()); // {50, 50, 100, 10, 10, 100, 100}

    cout << v3.size() << endl; // 7
    v3.pop_back(); // Remove last element

    // Swap v1 and v2
    v1.swap(v2);
    v3.clear();
    cout << v3.empty() << endl; // 1 (true)
}

void explainlist() {
    list<int> ls;
    ls.push_back(2); // 2
    ls.emplace_back(4); // 2, 4
    ls.push_front(5); // 5, 2, 4
    ls.emplace_front(1); // 1, 5, 2, 4
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;
}

void explainDeque() {
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3); // 3, 4, 1, 2

    dq.pop_back(); // 3, 4, 1
    dq.pop_front(); // 4, 1

    cout << dq.back() << " " << dq.front() << endl;
}

void explainStack() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5); // 5, 4, 3, 2, 1
    cout << st.top() << endl; // 5
    st.pop(); // Remove top element
    cout << st.top() << endl; // 4
    cout << st.size() << endl; // 4
    cout << st.empty() << endl; // 0 (false)

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4); // 1, 2, 3, 4
    q.back() += 5; // 1, 2, 3, 9
    cout << q.back() << endl; // 9
    cout << q.front() << endl; // 1
    q.pop(); // 2, 9
    cout << q.front() << endl; // 2
}

void explainPQ() {
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10); // 10, 8, 5, 2
    cout << pq.top() << endl; // 10
    pq.pop(); // 8, 5, 2
    cout << pq.top() << endl; // 8

    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(5);
    min_pq.push(2);
    min_pq.push(8);
    min_pq.emplace(10); // 2, 5, 8, 10

    cout << min_pq.top() << endl; // 2
}

void explainSet() {
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2); // Duplicate, won't be added
    st.emplace(4);
    st.insert(3);
    st.emplace(5); // 1, 2, 3, 4, 5

    auto it = st.find(3);
    if (it != st.end()) {
        cout << *it << endl; // 3
    }
    st.erase(5); // 1, 2, 3, 4
    cout << st.count(1) << endl; // 1

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // {1, 4, 5}

    auto it3 = st.lower_bound(2);
    auto it4 = st.upper_bound(3);
    cout << (it3 != st.end() ? *it3 : -1) << endl;
    cout << (it4 != st.end() ? *it4 : -1) << endl;
}

void explainMultiset() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    cout << ms.count(1) << endl; // 3

    ms.erase(1); // Removes all 1s
}

void explainUSet() {
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    cout << (st.find(2) != st.end() ? "Found" : "Not found") << endl;
}

void explainMap() {
    map<int, int> mpp1;                // Key: int, Value: int
    map<int, pair<int, int>> mpp2;     // Key: int, Value: pair<int, int>
    map<pair<int, int>, int> mpp3;     // Key: pair<int, int>, Value: int

    mpp1[1] = 2;
    mpp1.emplace(3, 1);
    mpp1.insert({2, 4});
    
    mpp2[2] = {3, 10};
    mpp3[{2, 3}] = 10;

    cout << "mpp1 elements:\n";
    for (const auto& it : mpp1) {
        cout << it.first << " " << it.second << endl;
    }

    cout << "Value for key 1: " << mpp1[1] << endl;
    cout << "Value for key 5 (default if not found): " << mpp1[5] << endl;

    auto it = mpp1.find(3);
    if (it != mpp1.end()) {
        cout << "Value for key 3: " << it->second << endl;
    } else {
        cout << "Key 3 not found in mpp1" << endl;
    }

    it = mpp1.find(5);
    if (it != mpp1.end()) {
        cout << "Value for key 5: " << it->second << endl;
    } else {
        cout << "Key 5 not found in mpp1" << endl;
    }

    auto lb = mpp1.lower_bound(2);
    auto ub = mpp1.upper_bound(3);

    if (lb != mpp1.end()) {
        cout << "Lower bound for key 2: " << lb->first << " " << lb->second << endl;
    } else {
        cout << "Lower bound for key 2 not found" << endl;
    }

    if (ub != mpp1.end()) {
        cout << "Upper bound for key 3: " << ub->first << " " << ub->second << endl;
    } else {
        cout << "Upper bound for key 3 not found" << endl;
    }
}

void explainmultimap()
{
    //can store duplicate keys
    //{1,2}
    //{1,3}
}

void explainunorderedmap()
{
    //not sorted but unique keys
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second == p2.second) {
        return p1.first > p2.first; // Compare first if second elements are equal
    }
    return false;
}

// Sorting algorithms demonstration
void explainsort() {
    // Example array and vector
    int a[] = {1, 3, 2, 5, 4};
    int n = sizeof(a) / sizeof(a[0]); // Size of the array

    vector<int> v = {5, 2, 4, 1, 3};
    vector<pair<int, int>> vp = {{1, 4}, {2, 3}, {3, 2}, {4, 1}};

    // Sorting examples
    sort(a, a + n); // Sort array in ascending order
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(v.begin(), v.end()); // Sort vector in ascending order
    cout << "Vector sorted in ascending order: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    sort(a + 2, a + 4); // Sort part of the array (elements at index 2 and 3)
    cout << "Partial array sorted (index 2 to 3): ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(a, a + n, greater<int>()); // Sort array in descending order
    cout << "Array sorted in descending order: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(vp.begin(), vp.end(), comp); // Sort vector of pairs using custom comparator
    cout << "Vector of pairs sorted using custom comparator: ";
    for (const auto& p : vp) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    // Bit manipulation example
    int num = 7;
    int cnt = __builtin_popcount(num); // Number of set bits in num
    cout << "Number of set bits in " << num << " is " << cnt << endl;

    long long num2 = 166565165185;
    int count = __builtin_popcountll(num2); // Number of set bits in num2 (64-bit integer)
    cout << "Number of set bits in " << num2 << " is " << count << endl;

    // Permutations of a string
    string s = "213";
    sort(s.begin(), s.end());
    cout << "Permutations of the string \"" << s << "\":\n";
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // Find maximum and minimum elements in the array
    int maxi = *max_element(a, a + n);
    int mini = *min_element(a, a + n);
    cout << "Maximum element in the array: " << maxi << endl;
    cout << "Minimum element in the array: " << mini << endl;
}

int main() {
    explainpair();
    explainvector();
    explainlist();
    explainDeque();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMultiset();
    explainUSet();
    explainMap();
    explainsort();
    

    print();
    cout << endl;
    int s = sum(1, 5);
    cout << s << endl;
    
    return 0;
}
