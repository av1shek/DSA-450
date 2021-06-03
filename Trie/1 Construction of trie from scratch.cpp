#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    bool wordEnd;
	TrieNode *child[ALPHABET_SIZE];

	TrieNode()
	{
	    wordEnd = false;
	    for(int i=0;i<ALPHABET_SIZE;i++)
            child[i] = NULL;
	}
};

class Trie
{
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }
    void insert(string s)
    {
        TrieNode *curr = root;
        for(int i=0;i<s.size();i++)
        {
            int indx = s[i]-'a';
            if(!curr->child[indx])
                curr->child[indx] = new TrieNode();
            curr = curr->child[indx];
        }
        curr->wordEnd = true;
    }

    bool search(string s)
    {
        TrieNode *curr = root;
        for(int i=0;i<s.size();i++)
        {
            int indx = s[i]-'a';
            if(!curr->child[indx])
                return false;
            curr = curr->child[indx];
        }
        return (curr) && (curr->wordEnd);
    }
};
int main()
{
	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    Trie T;
    for (int i = 0; i < n; i++)
        T.insert(keys[i]);

    cout << ( T.search("the") ? "YES" : "NO" ) << endl;
    cout << ( T.search("these") ? "YES" : "NO" ) << endl;

	return 0;
}
