#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<int> encodeIt(string text, map<string, int> dict)
{
    string s = string(1, text[0]);

    vector<int> ans;
    int code = 256;
    for (int i = 1; i < text.size(); i++)
    {
        string c = string(1, text[i]);
        if (dict.find(s + c) != dict.end())
        {
            s += c;
        }
        else
        {
            ans.push_back(dict[s]);
            dict[s + c] = code++;
            // cout<<dict[s]<<" ";
            s = c;
        }
    }
    ans.push_back(dict[s]);
    // cout<<dict[s]<<" ";

    return ans;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("encoded.txt");

    string text, line;
    while (getline(fin, line))
    {
        if (text.size() == 0)
        {
            text = line;
        }
        else
        {
            text += '\n' + line;
        }
    }
    // cout<<s;

    map<string, int> dict;
    for (int i = 0; i < 256; i++)
    {
        dict[string(1, char(i))] = i;
    }
    // for(auto i:dict) cout<<i.first<<" "<<i.second<<endl;

    vector<int> encode = encodeIt(text, dict);
    for (auto i : encode)
    {
        cout << i << " ";
        fout << i << " ";
    }
}