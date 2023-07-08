#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void LZWencode()
{
    // Create dictionary
    unordered_map<string, int> dictionary;
    for (int i = 0; i < 256; i++)
    {
        string s(1, char(i));
        dictionary[s] = i;
    }

    string currentString;
    int code = 256;

    // Redirect input to "input.txt"
    freopen("input.txt", "r", stdin);

    // Redirect output to "EncodedText.txt"
    freopen("EncodedText.txt", "w", stdout);

    // Read input file and encode
    char c;
    while (cin.get(c))
    {
        string nextString = currentString + c;
        if (dictionary.count(nextString))
        {
            currentString = nextString;
        }
        else
        {
            cout << dictionary[currentString] << " ";
            dictionary[nextString] = code;
            code++;
            currentString = string(1, c);
        }
    }
    cout << dictionary[currentString] << endl;

    // Close files
    fclose(stdin);
    fclose(stdout);
}

int main()
{
    LZWencode();
    return 0;
}
