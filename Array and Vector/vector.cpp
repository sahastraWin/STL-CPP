#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Initialize vector using initializer list
    vector<int> vec = {10, 20, 30, 40, 50};

    // Add elements dynamically
    vec.push_back(60);
    vec.push_back(70);

    // Iterate using range-based for loop
    cout << "Elements of vector: ";
    for (const auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << "\n";

    // Iterate using index-based loop
    cout << "Elements by index: ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";

    return 0;
}
