#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    ifstream encodedFile("encodedText.txt");
    ofstream decodedFile("decodedText.txt");

    string line, s;
    while(getline(encodedFile, line))
    {
        s += line + '\n';
    }

    for(int i=1; i<s.size(); i+=2)
    {
        int cnt = s[i];
        for(int j=0; j<cnt; j++)
        {
            decodedFile<<s[i-1];
        }
    }

    encodedFile.close();
    decodedFile.close();

    cout<<"Decoding successful."<<endl;


}