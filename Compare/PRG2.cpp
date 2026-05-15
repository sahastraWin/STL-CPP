#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome_memcmp(string s)
{
    string rev = s;
    reverse(begin(rev), end(rev));
    for (int i = 0; i < s.length(); i++)
    {
        if (!memcmp(s.c_str(), rev.c_str() + i, s.length() - i))
        {
            return rev.substr(0, i) + s;
        }
    }
    return rev + s;
}

string shortestPalindrome_equal(string s)
{
    string rev = s;
    reverse(begin(rev), end(rev));
    for (int i = 0; i < s.length(); i++)
    {
        if (equal(s.begin(), s.end() - i, rev.begin() + i))
        {
            return rev.substr(0, i) + s;
        }
    }
    return rev + s;
}

int main()
{
    string s;
    cin >> s;

    cout << "Using memcmp : " << shortestPalindrome_memcmp(s) << "\n";
    cout << "Using equal  : " << shortestPalindrome_equal(s) << "\n";
    return 0;
}
