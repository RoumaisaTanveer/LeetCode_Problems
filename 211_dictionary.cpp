#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class WordDictionary
{
private:
    struct TrieNode
    {
        TrieNode *children[26] = {};
        bool isEnd = false;
    };

    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Add a word to the Trie
    void addWord(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isEnd = true;
    }

    // Search with support for '.' wildcard
    bool search(string word)
    {
        return dfs(word, 0, root);
    }

    // Helper DFS function
    bool dfs(const string &word, int index, TrieNode *node)
    {
        if (!node)
            return false;
        if (index == word.length())
            return node->isEnd;

        char c = word[index];
        if (c == '.')
        {
            // Try all 26 possibilities
            for (int i = 0; i < 26; ++i)
            {
                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        }
        else
        {
            // Normal char
            return dfs(word, index + 1, node->children[c - 'a']);
        }
    }
};
