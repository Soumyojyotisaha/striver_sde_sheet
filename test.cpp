#include <iostream>
#include <set>

void explainMultiset() // sorted but not unique
{
    std::multiset<int> ms; // Create a multiset of integers
    ms.insert(1); // Insert the element 1; multiset now contains {1}
    ms.insert(1); // Insert another 1; multiset now contains {1, 1}
    ms.insert(1); // Insert another 1; multiset now contains {1, 1, 1}
    int cnt = ms.count(1); // Count the number of elements equal to 1 in the multiset; cnt = 3
    std::cout << "Count of 1: " << cnt << std::endl;

    // Erase elements
    auto it = ms.find(1); // Iterator to the first occurrence of 1
    // Erase the first 2 occurrences of 1
    ms.erase(it, std::next(it, 2)); // Remove elements in the range [it, it + 2)
    
    // Print remaining elements
    std::cout << "Elements after erase: ";
    for (const int& value : ms) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main()
{
    explainMultiset(); // Call the function to demonstrate multiset operations
    return 0; // Indicate that the program ended successfully
}
