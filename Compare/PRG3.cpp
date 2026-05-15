#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s)
{
    string rev = s;
    reverse(begin(rev), end(rev));
    // Now rev is the reverse of s.
    // Example: s = "abcd", rev = "dcba"

    // We want to find the longest prefix of s that matches a suffix of rev.
    // That prefix will be the palindrome part.

    // T.C : O(n^2)   (nested comparisons for each i)
    // S.C : O(n)     (extra space for rev string)
    for (int i = 0; i < s.length(); i++)
    {
        /*
        memcmp(ptr1, ptr2, count) → compares memory byte-by-byte.

        - Here we compare:
          s.c_str()                → pointer to the *prefix of s*.
          rev.c_str() + i           → pointer to the *suffix of rev* (skipping first i chars).
          s.length() - i            → number of characters to compare.

        - memcmp returns:
          0   → if all bytes match.
          <0  → if first differing byte in s < corresponding byte in rev.
          >0  → if first differing byte in s > corresponding byte in rev.

        - In our case we check:
          if (!memcmp(...))  → this means "if comparison result == 0"
                             → i.e., if prefix of s == suffix of rev.
        */
        if (!memcmp(s.c_str(), rev.c_str() + i, s.length() - i))
        {
            // Found the largest prefix that is equal to some suffix of rev.
            // This prefix is already a palindrome.

            // rev.substr(0, i) → the extra characters from rev that we must prepend.
            // Then add s to complete the palindrome.
            return rev.substr(0, i) + s;
        }
    }

    // If no overlap found, just append the full reverse.
    return rev + s;
}

int main()
{
    string s;
    cin >> s;

    cout << shortestPalindrome(s) << "\n";
    return 0;
}

/*
Problem:
--------
Given a string s, return the shortest palindrome
that can be formed by adding characters in front of s.

Key Idea:
---------
1. Reverse s → rev.
2. Find the longest prefix of s that matches a suffix of rev.
   (This ensures the prefix is already palindrome.)
3. Prepend the remaining part of rev in front of s.

Example 1:
----------
Input:  "aacecaaa"
Reverse: "aaacecaa"

Check overlaps:
i=0 → compare "aacecaaa" with "aaacecaa" → mismatch
i=1 → compare "aacecaaa" with "aacecaa"  → match found

So prepend rev.substr(0,1) = "a".
Answer: "aaacecaaa"

Example 2:
----------
Input:  "abcd"
Reverse: "dcba"

Check overlaps:
i=0 → "abcd" vs "dcba" → mismatch
i=1 → "abcd" vs "cba"  → mismatch
i=2 → "abcd" vs "ba"   → mismatch
i=3 → "abcd" vs "a"    → mismatch

No prefix-suffix match → prepend full rev.
Answer: "dcbabcd"

Time Complexity:
----------------
O(n^2), because for each i we may compare up to n characters.

Space Complexity:
-----------------
O(n), storing rev.
*/
