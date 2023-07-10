#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

string huffmanEncode(string s)
{
    map<int, int> cnt;

    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]]++;
    }
    // for(auto i:cnt) cout<<i.first<<" "<<i.second<<endl;

    // paired priority queue in des order
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto i : cnt)
    {
        pq.push({i.second, i.first}); // sort based on how many times appear
    }

    int nValue = 256;
    vector<int> nodalConnection[(int)2e5];
    while (pq.size() != 1)
    {
        auto u = pq.top();
        pq.pop();
        auto v = pq.top();
        pq.pop();

        nodalConnection[nValue].push_back(u.second);
        nodalConnection[nValue].push_back(v.second);
        nValue++;
    }
}

int main()
{
    ifstream fin("input.txt");

    string s = "", tem;
    while (getline(fin, tem))
    {
        s += tem + "\n";
    }
    cout << s << endl;

    string compress = huffmanEncode(s);
}