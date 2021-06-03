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

void printAll(TrieNode*, vector<string>&, string);

class Trie
{
public:
    TrieNode *root;
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

    vector<string> search(string s)
    {
        vector<string> ans;
        TrieNode *curr = root;

        for(int i=0;i<s.size();i++)
        {
            int indx = s[i]-'a';
            if(!curr->child[indx])
                return ans;
            curr = curr->child[indx];
        }
        if((curr))
        {
            string t = s;
            printAll(curr, ans, t);
        }
        return ans;
    }
};

void printAll(TrieNode *root, vector<string> &ans, string s="")
{
    if(root==NULL) return;
    if(root->wordEnd) ans.push_back(s);

    for(int i=0;i<ALPHABET_SIZE;i++)
        if(root->child[i])
            printAll(root->child[i],  ans, s + char('a'+ i));
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    vector<vector<string> > ans;
    Trie T;
    for(int i=0;i<n;i++) T.insert(contact[i]);
    TrieNode *curr = T.root;
    for(int i=0;i<s.size();i++)
        ans.push_back(T.search(s.substr(0, i+1) ));
    return ans;
}


int main()
{
	string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    int n = sizeof(contact)/sizeof(contact[0]);
    string s = "geeips";
    Trie T;

    for(int i=0;i<n;i++) T.insert(contact[i]);

    vector<vector<string> > ans = displayContacts(n, contact, s);

    for(auto group : ans)
    {
        for(auto it : group) cout << it << " ";
        cout << endl;
    }

	return 0;
}
