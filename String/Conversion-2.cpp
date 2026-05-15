#include <bits/stdc++.h>
using namespace std;

// Function to convert a string into a character
// (We will take the first character of the string)
char stringToChar(const string &s)
{
    // Check if string is empty to avoid error
    if (s.empty())
    {
        throw invalid_argument("Empty string cannot be converted to char");
    }

    return s[0]; // return the first character
}

int main()
{
    string str;
    cin >> str; // input a string

    try
    {
        char c = stringToChar(str);
        cout << c << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

/*
Explanation:
------------
- A string is essentially an array of characters.
- To convert a string to a single character, we usually take one element from it.
- Example: s = "Hello"
           s[0] -> 'H'
           s[1] -> 'e'

- In this code:
   * If the string is not empty, return s[0].
   * If it's empty, throw an exception (to prevent undefined behavior).

Example:
--------
Input:  Hello
Output: H

Input:  X
Output: X

Time Complexity: O(1)
Space Complexity: O(1)
*/
