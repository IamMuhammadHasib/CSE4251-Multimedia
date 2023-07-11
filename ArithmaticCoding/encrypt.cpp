#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<int>
#define vl vector<long long>
#define read(a) scanf("%d", &a)
#define p1(a) cout << "Check " << a << endl;
#define p2(a, b) cout << "Check " << a << ' ' << b << endl;
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
#define clr(a, b) memset(a, b, sizeof(a))
#define MOD 1000000007

using namespace std;
int const sz = (int)2e5 + 5;

struct k
{
    /* datad */
    char ch;
    double prob;
    double high;
    double low;
} datad[10];

void solve()
{
    // Taking input
    string input = "CAEE$";
    char ch;
    double prob, prev = 0;
    int index = 0;
    map<char, int> has;
    int newVal = 0;
    while (cin >> ch >> prob)
    {
        if (has.count(ch) == 0)
            has[ch] = newVal++;
        datad[has[ch]].ch = ch;
        datad[has[ch]].prob = prob;
        datad[has[ch]].low = prev;
        datad[has[ch]].high = prev + prob;
        prev = prob + prev;
    }
    cout << newVal << endl;
    printf("datad Table:\n");
    printf("Symbols \tProbability \tLow_Range \tHigh_Range\n");
    for (int i = 0; i < newVal; i++)
    {
        printf("%c \t\t%.2lf \t\t%.2lf \t\t%.2lf\n", datad[i].ch, datad[i].prob, datad[i].low, datad[i].high);
    }

    printf("\n");

    // Encoding and produce code
    double low = 0.0, high = 1.0, range = 1.0;
    for (int i = 0; i < input.size(); i++)
    {
        int k = has[input[i]];

        high = low + range * datad[k].high;
        low = low + range * datad[k].low;
        range = high - low;
        printf("%lf \t%lf \t%lf\n", low, high, range);
        // cout<<low<<' '<<high<<' '<<range<<endl;
    }
    cout << low << ' ' << high << endl;

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
        // cout<<val<<endl;
        k++;
    }
    printf("%.9lf\n", val);
    cout << "Binary Code: " << code << endl;

    // Decoding process
    char symbol;
    do
    {
        for (int i = 0; i < newVal; i++)
        {
            if (datad[i].low <= val and val < datad[i].high)
            {
                printf("%c", datad[i].ch);
                low = datad[i].low;
                high = datad[i].high;
                range = high - low;
                val = (val - low) / range;
                symbol = datad[i].ch;
            }
        }
    } while (symbol != '$');

    cout << endl;
}
int main()
{
    freopen("table.txt", "r", stdin);
    // freopen("output.txt","w",stdout);
    int t = 1, ts = 0; // cin>>t;
    while (t--)
    {

        solve();
    }
    return 0;
}