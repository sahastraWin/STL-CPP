#include <iostream>
#include <string>

using namespace std;

int main()
{
    string email = "hello_world_email.com"; // Missing the '@' symbol

    // Try to find the "@" symbol in our string
    size_t position = email.find("@");

    // Check the result using npos
    if (position == string::npos)
    {
        cout << "Error: The email is missing an '@' symbol." << "\n";
    }
    else
    {
        cout << "Success: The '@' symbol was found at index " << position << "\n";
    }

    return 0;
}