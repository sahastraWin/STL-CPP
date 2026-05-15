#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "abc";
    string s2 = "abd";

    // memcmp
    cout << "memcmp : " << memcmp(s1.c_str(), s2.c_str(), 3) << "\n";

    // equal
    cout << "equal  : " << equal(s1.begin(), s1.end(), s2.begin()) << "\n";

    // compare
    cout << "compare: " << s1.compare(s2) << "\n";

    return 0;
}
