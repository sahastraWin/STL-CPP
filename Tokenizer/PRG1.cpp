// tokenizers_demo.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  1) split_ws_istringstream
     - Uses istringstream to split on whitespace (fast + simple).
*/
vector<string> split_ws_istringstream(const string &s)
{
    vector<string> tokens;
    istringstream iss(s);
    string tok;
    while (iss >> tok)
        tokens.push_back(tok);
    return tokens;
}

/*
  2) split_getline_delim
     - Uses std::getline with a delimiter (works for single-char delimiter like ',').
*/
vector<string> split_getline_delim(const string &s, char delim)
{
    vector<string> tokens;
    string token;
    istringstream iss(s);
    while (getline(iss, token, delim))
    {
        tokens.push_back(token);
    }
    return tokens;
}

/*
  3) split_strtok_cstyle
     - C-style strtok (modifies a C string) — ok for quick scripts but unsafe for const strings.
     - We copy the string into a mutable buffer before using strtok.
*/
vector<string> split_strtok_cstyle(const string &s, const char *delims)
{
    vector<string> tokens;
    // make a mutable copy:
    char *buf = new char[s.size() + 1];
    strcpy(buf, s.c_str());
    char *p = strtok(buf, delims);
    while (p)
    {
        tokens.emplace_back(p);
        p = strtok(nullptr, delims);
    }
    delete[] buf;
    return tokens;
}

/*
  4) split_regex
     - Uses std::regex / sregex_token_iterator for complex separators (multiple separators,
       patterns, or to extract only capture groups).
     - Slightly heavier but powerful.
*/
vector<string> split_regex(const string &s, const string &pattern)
{
    vector<string> tokens;
    // pattern is the delimiter regex, e.g. "[,;\\s]+" (comma/semicolon/whitespace)
    regex re(pattern);
    sregex_token_iterator it(s.begin(), s.end(), re, -1); // -1 = tokens between matches
    sregex_token_iterator end;
    for (; it != end; ++it)
    {
        if (!it->str().empty()) // optional: skip empty tokens
            tokens.push_back(it->str());
    }
    return tokens;
}

/*
  5) split_view (manual find) - zero allocations for scanning (returns vector of strings)
     - Good when performance matters: uses string::find to locate delimiters.
     - We'll return vector<string> for simplicity (could return string_views referencing original string).
*/
vector<string> split_find(const string &s, char delim)
{
    vector<string> tokens;
    size_t start = 0;
    while (start <= s.size())
    {
        size_t pos = s.find(delim, start);
        if (pos == string::npos)
            pos = s.size();
        tokens.emplace_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    return tokens;
}

int main()
{
    string text = "Hello, world! This is C++ tokenization-demo.";
    cout << "Original: " << text << "\n\n";

    // 1) whitespace tokenizer
    auto t1 = split_ws_istringstream(text);
    cout << "1) istringstream (split on whitespace):\n";
    for (auto &tk : t1)
        cout << "[" << tk << "]\n";
    cout << '\n';

    // 2) delimiter tokenizer (comma)
    string csv = "apple,banana,,cherry,dragonfruit";
    auto t2 = split_getline_delim(csv, ',');
    cout << "2) getline with comma delimiter (keeps empty tokens):\n";
    for (auto &tk : t2)
        cout << "[" << tk << "]\n";
    cout << '\n';

    // 3) strtok (C-style) - delimiters: comma and whitespace
    string mixed = "one,two three\tfour;five";
    auto t3 = split_strtok_cstyle(mixed, ",;\t ");
    cout << "3) strtok C-style (multiple delim set):\n";
    for (auto &tk : t3)
        cout << "[" << tk << "]\n";
    cout << '\n';

    // 4) regex split - split on punctuation and whitespace
    string complex = "a,b; c  d\t e\nf";
    auto t4 = split_regex(complex, R"([,;\s]+)"); // split on comma/semicolon/whitespace runs
    cout << "4) regex split ([,;\\s]+):\n";
    for (auto &tk : t4)
        cout << "[" << tk << "]\n";
    cout << '\n';

    // 5) manual find (split on '-')
    string dash = "2025-09-01";
    auto t5 = split_find(dash, '-');
    cout << "5) manual find split on '-':\n";
    for (auto &tk : t5)
        cout << "[" << tk << "]\n";
    cout << '\n';

    return 0;
}
