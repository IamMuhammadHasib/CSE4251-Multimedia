#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    ofstream encodedFile("encodedText.txt");

    string line, s = "";
    while (getline(inputFile, line))
    {
        s += line + '\n';
    }
    // cout<<s<<endl;

    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == s[i])
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

    inputFile.close();
    encodedFile.close();

    cout << "Encoding successful." << endl;
}