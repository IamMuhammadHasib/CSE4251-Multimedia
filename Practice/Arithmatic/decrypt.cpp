#include<bits/stdc++.h>
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

    ifstream vfin("compressed.txt");
    double val;
    vfin>>val;
    cout<<endl<<val<<endl;

    // main decoding process
    double low, high, range;
    char symbol;
    do
    {
        for(int i=0; i<index; i++)
        {
            if(box[i].low<= val && val < box[i].high)
            {
                cout<<box[i].ch;
                low = box[i].low;
                high = box[i].high;
                range = high - low;
                val = (val - low)/ range;
                symbol = box[i].ch;
            }
        }
    } while (symbol != '$');

    cout<<endl<<endl;

}

int main()
{
    ifstream fin("compressed.txt");
    ofstream fout("cipher.txt");

    string s;
    fin >> s;

    generateTable(s);
}