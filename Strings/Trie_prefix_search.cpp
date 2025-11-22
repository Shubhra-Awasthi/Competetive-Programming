// Trie implementation for prefix search
// O(L) for insert and search, where L is the length of the word

struct Node
{
    int cnt;
    bool end;
    vector<Node *> children;

    Node()
    {
        cnt = 0;
        end = false;
        children.resize(26, nullptr);
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(const string &word)
    {
        Node *curr = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
            curr->cnt++;
        }
        curr->end = true;
    }

    bool search(const string &word)
    {
        Node *curr = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (curr->children[index] == nullptr)
            {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->end;
    }
};