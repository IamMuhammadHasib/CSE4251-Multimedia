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

    // paired priority queue in desc order
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto i : cnt)
    {
        pq.push({i.second, i.first}); // sort based on how many times appear
    }
    // cout<<">"<<pq.size()<<endl;

    int nValue = 256;
    vector<int> nodalConnection[1000];
    while (pq.size() > 1)
    {
        auto u = pq.top();
        // cout<<char(u.second)<<" "<<u.first<<endl;
        pq.pop();
        auto v = pq.top();
        // cout<<char(v.second)<<" "<<v.first<<endl;
        pq.pop();

        nodalConnection[nValue].push_back(u.second);
        nodalConnection[nValue].push_back(v.second);
        pq.push({u.first+v.first, nValue});
        nValue++;
        // cout<<nValue<<endl;
    }

    queue<int> q;
    q.push(nValue-1);

    map<int, string> code;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(nodalConnection[u].size()>1)
        {
            code[nodalConnection[u][0]] = code[u] + "1";
            code[nodalConnection[u][1]] = code[u] + "0";

            q.push(nodalConnection[u][0]);
            q.push(nodalConnection[u][1]);
        }
    }


    for(auto i:code)
    {
        if(i.first>255) continue;

        cout<<char(i.first)<<":"<<i.second<<endl;
    }
    cout<<endl;

    for(int i=0; i<s.size(); i++)
    {
        string tem = code[s[i]];
        cout<<tem<<" ";
    }
    cout<<endl;

    return "1";
}

int main()
{
    ifstream fin("input.txt");

    string s = "", tem;
    while (getline(fin, tem))
    {
        s += tem + "\n";
    }
    s = s.substr(0, s.size()-1);
    cout << s << endl;

    string compress = huffmanEncode(s);
}