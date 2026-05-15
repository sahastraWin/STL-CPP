#include <bits/stdc++.h>
using namespace std;

// Function to convert a character into a string
string charToString(char c)
{
    // Method 1: Using string constructor
    return string(1, c);

    // Method 2 (alternative):
    // string s = "";
    // s += c;
    // return s;
}

int main()
{
    char ch;
    cin >> ch; // input a single character

    string s = charToString(ch);
    cout << s << endl;

    return 0;
}

/*
Explanation:
------------
- We want to convert a character into a string.
- In C++, the `string` constructor `string(count, char)` creates a string
  of length = count filled with the character `char`.
- Example: string(1, 'A') -> "A"
           string(5, 'X') -> "XXXXX"

- Other ways:
   * Use += operator:   string s = ""; s += c;
   * Use push_back():   string s; s.push_back(c);

Example:
--------
Input:  Z
Output: "Z"

Time Complexity: O(1)
Space Complexity: O(1)
*/
