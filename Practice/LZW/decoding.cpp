#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

string decode(vector<int> encode, map<int, string> dict)
{
    string ans = "";
    int code = 256;

    string s = "";
    for (int i = 0; i < encode.size(); i++)
    {
        int k = encode[i];
        string entry = dict[k];

        if (dict.find(k) == dict.end())
        {
            entry = s + s[0];
        }
        ans += entry;

        if (s != "")
        {
            dict[code++] = s+entry[0];
        }
        s = entry;
    }

    return ans;
}

int main()
{
    ifstream fin("encoded.txt");
    ofstream fout("output.txt");

    vector<int> encode;
    int tem;
    while (fin >> tem)
        encode.push_back(tem);

    map<int, string> dict;
    for (int i = 0; i < 256; i++)
    {
        dict[i] = string(1, char(i));
    }
    // for(auto i:dict)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    string text = decode(encode, dict);
    cout<<text;
    fout<<text;
}