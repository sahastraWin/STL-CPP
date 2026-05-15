#include <iostream>
#include <array>

using namespace std;

int main()
{
    // Initialize std::array with fixed size 5
    array<int, 5> arr = {10, 20, 30, 40, 50};

    // Iterate using range-based for loop
    cout << "Elements of std::array: ";
    for (const auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << "\n";

    // Iterate using index-based loop
    cout << "Elements by index: ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
