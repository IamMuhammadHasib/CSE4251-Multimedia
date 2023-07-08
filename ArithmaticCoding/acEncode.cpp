#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int kNumBits = 32; // Number of bits in the integer range

struct Range
{
    uint64_t low;  // lower bound of the range
    uint64_t high; // upper bound of the range
};

int main()
{
    // Open input file
    freopen("input.txt", "r", stdin);

    // Calculate symbol frequencies
    vector<int> frequencies(256, 0);
    char c;
    while (cin.get(c))
    {
        frequencies[c]++;
    }
    cin.clear();
    cin.seekg(0);

    // Calculate cumulative symbol frequencies
    vector<int> cumFreq(257, 0);
    for (int i = 1; i <= 256; i++)
    {
        cumFreq[i] = cumFreq[i - 1] + frequencies[i - 1];
    }

    // Initialize range
    Range r = {0, (1ull << kNumBits) - 1};
    uint64_t rangeSize = r.high - r.low + 1;

    // Open output file
    freopen("EncodedText.txt", "w", stdout);

    // Encode symbols
    while (cin.get(c))
    {
        int symbol = int(c);
        uint64_t newLow = r.low + (rangeSize * cumFreq[symbol]) / cumFreq[256];
        uint64_t newHigh = r.low + (rangeSize * cumFreq[symbol + 1]) / cumFreq[256] - 1;
        r = {newLow, newHigh};

        // Shift out any common leading bits
        while (((r.low >> (kNumBits - 1)) ^ (r.high >> (kNumBits - 1))) == 0)
        {
            putchar(r.low >> (kNumBits - 1));
            r.low = (r.low << 1) & ((1ull << kNumBits) - 1);
            r.high = ((r.high << 1) | 1) & ((1ull << kNumBits) - 1);
        }
    }

    // Output the middle bits
    uint64_t middle = (r.low + r.high) / 2;
    for (int i = 0; i < kNumBits - 1; i++)
    {
        putchar(middle >> (kNumBits - 2 - i));
    }

    // Close files
    fclose(stdin);
    fclose(stdout);

    return 0;
}
