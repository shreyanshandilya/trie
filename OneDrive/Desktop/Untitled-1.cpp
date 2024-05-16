#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    
    public:

        bool isTerminal;
        TrieNode* child[26];

        TrieNode() {
            isTerminal = false;
            for(int i=0; i<26; i++) {
                child[i] = NULL;
            }
        }

};

void add(string word, TrieNode* root) {
    for(int i=0; i<word.size(); i++) {
        if(root->child[word[i]-'A'] == NULL) {
            root->child[word[i]-'A'] = new TrieNode();
        }
        root = root->child[word[i]-'A'];
    }
    root->isTerminal = true;
}

bool search(string word, TrieNode* root) {
    for(int i=0; i<word.size(); i++) {
        if(root->child[word[i]-'A'] == NULL) return false;
        else root = root->child[word[i]-'A'];
    }
    return root->isTerminal;
}

int main() {
    TrieNode* root = new TrieNode();
    vector<string> dictionary;
    dictionary.push_back("SHREYANSH");
    dictionary.push_back("CEO");
    for(auto it: dictionary) add(it, root);
    cout << search("A", root) << endl;
    return 0;
}