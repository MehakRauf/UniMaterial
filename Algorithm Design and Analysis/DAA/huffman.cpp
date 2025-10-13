#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

// Compare function for min-heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Create a new node
Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Traverse Huffman Tree and store codes
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root)
        return;

    // Leaf node
    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Build Huffman Tree
void buildHuffmanTree(string text) {
    // Count frequency
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    // Min-heap priority queue
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto pair : freq)
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));

    // Combine until one node remains
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node* root = pq.top();

    // Traverse tree and store codes
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " -> " << pair.second << endl;

    cout << "\nEncoded Text: ";
    for (char ch : text)
        cout << huffmanCode[ch];
    cout << endl;
}

int main() {
    string text = "HELLO WORLD";
    buildHuffmanTree(text);
    return 0;
}
