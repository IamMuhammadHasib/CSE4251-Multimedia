#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void LZWdecode()
{
    // Create dictionary
    unordered_map<int, string> dictionary;
    for (int i = 0; i < 256; i++)
    {
        string s(1, char(i));
        dictionary[i] = s;
    }

    int code = 256;

    freopen("EncodedText.txt", "r", stdin);
    freopen("DecodedText.txt", "w", stdout);

    // Read encoded text and decode
    int prevCode, currCode;
    cin >> prevCode;
    cout << dictionary[prevCode];
    while (cin >> currCode)
    {
        string s;
        if (dictionary.count(currCode))
        {
            s = dictionary[currCode];
        }
        else
        {
            s = dictionary[prevCode] + dictionary[prevCode][0];
        }
        cout << s;
        dictionary[code] = dictionary[prevCode] + s[0];
        code++;
        prevCode = currCode;
    }

    // Close input file
    fclose(stdin);
    fclose(stdout);
}

int main()
{
    LZWdecode();
    return 0;
}
