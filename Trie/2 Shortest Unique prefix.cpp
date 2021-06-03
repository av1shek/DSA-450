// https://www.interviewbit.com/problems/shortest-unique-prefix/
const int ALPHABET_SIZE = 26;

struct TrieNode
{
    bool wordEnd;
    int freq;
	TrieNode *child[ALPHABET_SIZE];

	TrieNode()
	{
	    wordEnd = false;
	    freq = 1;
	    for(int i=0;i<ALPHABET_SIZE;i++)
            child[i] = NULL;
	}
};

class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }
    void insert(string s)
    {
        TrieNode *curr = root;
        curr->freq++;
        for(int i=0;i<s.size();i++)
        {
            int indx = s[i]-'a';
            if(!curr->child[indx])
                curr->child[indx] = new TrieNode();
            else
                (curr->child[indx]->freq)++;
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

string prefixes(TrieNode *head, string s)
{
    if(head==NULL) return "";
    string ans = "";
    if(head->freq == 1) return ans;

    for(int i=0;i<s.size();i++)
    {
        int indx = s[i] - 'a';
        ans += s[i];
        if(head->child[indx]->freq == 1) return ans;

        head = head->child[indx];
    }
    cout << endl;
    return ans;
}


vector<string> Solution::prefix(vector<string> &arr) {
    vector<string> ans;
    Trie T;
    for(int i=0;i<arr.size();i++) T.insert(arr[i]);
    TrieNode *curr = T.root;
    for(int i=0;i<arr.size();i++)
        ans.push_back(prefixes(curr, arr[i]));
    return ans;
}
