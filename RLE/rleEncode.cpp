#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    ofstream encodedFile("encodedText.txt");

    string ss, s = "";
    while (getline(inputFile, ss))
    {
        s += ss + "\n";
    }

    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
            if (cnt == 128)
            {
                encodedFile << s[i - 1] << char(cnt - 1);
                cnt = 1;
            }
        }
        else
        {
            encodedFile << s[i - 1] << char(cnt);
            cnt = 1;
        }
    }

    encodedFile.close();
    inputFile.close();

    cout << "Encoded successfully." << endl;

    return 0;
}