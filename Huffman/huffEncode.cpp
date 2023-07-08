#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>

struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(char c, int f) : data(c), freq(f), left(nullptr), right(nullptr) {}
};

struct CompareNodes
{
    bool operator()(const HuffmanNode *lhs, const HuffmanNode *rhs) const
    {
        return lhs->freq > rhs->freq;
    }
};

void buildHuffmanTree(std::unordered_map<char, int> &freqMap, HuffmanNode *&root)
{
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, CompareNodes> pq;
    for (const auto &[c, f] : freqMap)
    {
        pq.push(new HuffmanNode(c, f));
    }
    while (pq.size() > 1)
    {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();
        int combinedFreq = left->freq + right->freq;
        HuffmanNode *newNode = new HuffmanNode('$', combinedFreq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    root = pq.top();
    pq.pop();
}

void buildHuffmanCodeTable(HuffmanNode *root, std::string code, std::unordered_map<char, std::string> &codeTable)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data != '$')
    {
        codeTable[root->data] = code;
    }
    buildHuffmanCodeTable(root->left, code + '0', codeTable);
    buildHuffmanCodeTable(root->right, code + '1', codeTable);
}

void encodeText(const std::string &text, const std::unordered_map<char, std::string> &codeTable, std::ofstream &output)
{
    for (char c : text)
    {
        output << codeTable.at(c);
    }
}

int main()
{
    // Redirect input and output to files
    std::freopen("input.txt", "r", stdin);
    std::freopen("EncodedText.txt", "w", stdout);

    // Read input text
    std::string text;
    std::getline(std::cin, text);

    // Build frequency map
    std::unordered_map<char, int> freqMap;
    for (char c : text)
    {
        freqMap[c]++;
    }

    // Build Huffman tree
    HuffmanNode *root;
    buildHuffmanTree(freqMap, root);

    // Build Huffman code table
    std::unordered_map<char, std::string> codeTable;
    buildHuffmanCodeTable(root, "", codeTable);

    // Encode input text using Huffman codes
    std::ofstream output("EncodedText.txt");
    encodeText(text, codeTable, output);
    output.close();

    // Clean up memory
    // TODO: implement tree deletion
    return 0;
}
