#include <iostream>
#include <string>
#include <algorithm> // sort, reverse, transform
#include <numeric>   // accumulate
#include <iterator>  // iterators
#include <cctype>    // toupper, tolower
#include <vector>

using namespace std;

int main()
{
    // ----------- Basic String operations --------------
    string s = "Hello World";
    cout << "Original string: " << s << "\n";
    cout << "Length of string: " << s.size() << "\n";
    cout << "Character at index 1: " << s.at(1) << "\n";

    // Substring
    cout << "Substring (0,5): " << s.substr(0, 5) << "\n";

    // Append
    s.append("!!!");
    cout << "After append: " << s << "\n";

    // Insert
    s.insert(6, "Beautiful ");
    cout << "After insert: " << s << "\n";

    // Erase
    s.erase(6, 10); // remove "Beautiful "
    cout << "After erase: " << s << "\n";

    // Replace
    s.replace(6, 5, "Universe");
    cout << "After replace: " << s << "\n";

    // ----------- Searching in string -----------------
    string str = "the quick brown fox jumps over the lazy dog";
    cout << "\nNew string: " << str << "\n";

    size_t pos = str.find("fox");
    if (pos != string::npos)
        cout << "'fox' found at index " << pos << "\n";

    pos = str.rfind("the");
    if (pos != string::npos)
        cout << "Last 'the' found at index " << pos << "\n";

    pos = str.find_first_of("aeiou");
    cout << "First vowel at index " << pos << " (" << str[pos] << ")\n";

    pos = str.find_last_of("aeiou");
    cout << "Last vowel at index " << pos << " (" << str[pos] << ")\n";

    // ----------- Algorithms on string ----------------
    string t = "algorithm";
    cout << "\nOriginal: " << t << "\n";

    reverse(t.begin(), t.end());
    cout << "Reversed: " << t << "\n";

    sort(t.begin(), t.end());
    cout << "Sorted ascending: " << t << "\n";

    sort(t.begin(), t.end(), greater<char>());
    cout << "Sorted descending: " << t << "\n";

    int cnt = count(t.begin(), t.end(), 'a');
    cout << "Count of 'a': " << cnt << "\n";

    int sum_ascii = accumulate(t.begin(), t.end(), 0);
    cout << "Sum of ASCII values: " << sum_ascii << "\n";

    auto it = max_element(t.begin(), t.end());
    cout << "Max char: " << *it << "\n";

    // ----------- Transform (uppercase/lowercase) ------
    string msg = "StL Is PoWeRfUl!";
    cout << "\nOriginal: " << msg << "\n";

    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    cout << "Uppercase: " << msg << "\n";

    transform(msg.begin(), msg.end(), msg.begin(), ::tolower);
    cout << "Lowercase: " << msg << "\n";

    // ----------- String <-> Number conversion ----------
    string numStr = "12345";
    int num = stoi(numStr);
    cout << "\nString to int: " << num << "\n";

    double d = stod("3.14159");
    cout << "String to double: " << d << "\n";

    string s2 = to_string(98765);
    cout << "Int to string: " << s2 << "\n";

    // ----------- Splitting string (manual with find) ----
    string sentence = "one,two,three,four";
    vector<string> words;
    size_t start = 0, end;
    while ((end = sentence.find(',', start)) != string::npos)
    {
        words.push_back(sentence.substr(start, end - start));
        start = end + 1;
    }
    words.push_back(sentence.substr(start)); // last word

    cout << "\nSplitting 'one,two,three,four' -> ";
    for (auto &w : words)
        cout << "[" << w << "] ";
    cout << "\n";

    // ----------- Key differences summary ------------
    /*
    1. std::string is dynamic and manages memory automatically.
    2. Provides rich set of functions: append, insert, erase, replace, find, substr.
    3. Compatible with STL algorithms (sort, reverse, count, accumulate).
    4. Can be transformed easily (toupper/tolower).
    5. Supports conversions (stoi, stod, to_string).
    6. Can be split using find or with stringstream.
    7. Unlike C-style strings, safer (bounds checking via at()) and resizable.
    */

    return 0;
}
