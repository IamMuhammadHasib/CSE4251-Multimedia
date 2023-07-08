#include <iostream>
#include <fstream>
#include <unordered_map>

struct HuffmanNode
{
    char data;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(char c) : data(c), left(nullptr), right(nullptr) {}
};

void buildHuffmanTree(const std::string &codeTable, HuffmanNode *&root)
{
    root = new HuffmanNode('$');
    HuffmanNode *current = root;
    for (char c : codeTable)
    {
        if (c == '0')
        {
            if (current->left == nullptr)
            {
                current->left = new HuffmanNode('$');
            }
            current = current->left;
        }
        else if (c == '1')
        {
            if (current->right == nullptr)
            {
                current->right = new HuffmanNode('$');
            }
            current = current->right;
        }
        else
        {
            current->data = c;
            current = root;
        }
    }
}

void decodeText(const std::string &encodedText, const HuffmanNode *root, std::ofstream &output)
{
    const HuffmanNode *current = root;
    for (char c : encodedText)
    {
        if (c == '0')
        {
            current = current->left;
        }
        else if (c == '1')
        {
            current = current->right;
        }
        if (current->data != '$')
        {
            output << current->data;
            current = root;
        }
    }
}

int main()
{
    // Redirect input and output to files
    std::freopen("EncodedText.txt", "r", stdin);
    std::freopen("DecodedText.txt", "w", stdout);

    // Read encoded text
    std::string encodedText;
    std::getline(std::cin, encodedText);

    // Read Huffman code table
    std::unordered_map<std::string, char> codeTable;
    char c;
    std::string code;
    while (std::cin >> c >> code)
    {
        codeTable[code] = c;
    }

    // Build Huffman tree
    HuffmanNode *root;
    std::string codeTableStr;
    for (const auto &[code, c] : codeTable)
    {
        codeTableStr += code + " " + c + "\n";
    }
    buildHuffmanTree(codeTableStr, root);

    // Decode encoded text using Huffman codes
    std::ofstream output("DecodedText.txt");
    decodeText(encodedText, root, output);
    output.close();

    // Clean up memory
    // TODO: implement tree deletion
    return 0;
}
