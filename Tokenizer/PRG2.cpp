#include <bits/stdc++.h>
using namespace std;

// Function to reverse the order of words in a string
string reverseWords(string s)
{
    stringstream ss(s); // Breaks string into words (default delimiter = space)
    string token = "";  // Will store each word
    string result = ""; // Final reversed string

    // Extract each word and add it to the front of result
    while (ss >> token)
    {
        result = token + " " + result;
    }

    // Remove the trailing space at the end
    return result.substr(0, result.length() - 1);
}

int main()
{
    string s;
    getline(cin, s); // Input full line (can contain spaces)

    cout << reverseWords(s) << endl;
    return 0;
}

/*
Problem:
--------
Given a string s, reverse the order of words.
Words are separated by spaces.

Logic:
------
- Use stringstream to split the string into words.
- Keep prepending each word to the result.
- Remove the last extra space at the end.

Example 1:
----------
Input:  "the sky is blue"
Output: "blue is sky the"

Example 2:
----------
Input:  "  hello world  "
Output: "world hello"

Time Complexity:
----------------
O(n), where n is the length of the string.

Space Complexity:
-----------------
O(n) due to extra result string and token storage.
*/
