#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

struct __
{
    char ch;
    double pro;
    double low;
    double high;
} box[10];

void generateTable(string s)
{
    ifstream fin("probability.txt");
    // ofstream fout("rangeTable.txt");

    char ch;
    double pro, pre = 0;

    map<char, int> hash;
    int index = 0;

    while (fin >> ch >> pro)
    {
        if (hash.count(ch) == 0)
            hash[ch] = index++;

        box[hash[ch]].ch = ch;
        box[hash[ch]].pro = pro;
        box[hash[ch]].low = pre;
        box[hash[ch]].high = pre + pro;
        pre += pro;
    }

    printf("Symbols \tProbability \tRange_Low \tRange_High\n");
    for (int i = 0; i < index; i++)
    {
        printf("%c \t%.2lf \t%.2lf \t%.2lf\n", box[i].ch, box[i].pro, box[i].low, box[i].high);
    }


    // main encoding process
    // finding the expected low and high
    double low = 0, high = 1, range = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int k = hash[s[i]];

        high = low + range * box[k].high;
        low = low + range * box[k].low;
        range = high - low;
    }
    cout << endl
         << low << " " << high << endl
         << endl;

    // making the code
    string code = "0.";

    int k = 1;
    double val = 0;

    while (val < low)
    {
        if (val + pow(2, -k) < high)
        {
            code += "1";
            val += pow(2, -k);
        }
        else
            code += "0";
        k++;
    }

    ofstream fout("compressed.txt");
    fout<<val;
    cout<<val<<endl;
    cout<<"Binary: "<<code<<endl<<endl;
}

int main()
{
    ifstream fin("in.txt");
    ofstream fout("cipher.txt");

    string s;
    fin >> s;

    generateTable(s);
}