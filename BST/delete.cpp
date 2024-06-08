#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vvll vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define mii map<int, int>
#define mis map<int, string>
#define msi map<string, int>
#define si set<int>
#define sll set<long long>
#define sc set<char>
/* FUNCTIONS */
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
/* PRINTS */
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << "," << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os;
    string sep;
    for (const T &x : v)
        os << sep << x, sep = " ";
    return os;
}
/* UTILS */
#define M 1000000007
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool chk_pali(string s)
{
    for (int i = 0; i < (int)s.length() / 2; i++)
        if (s[i] != s[s.length() - 1 - i])
            return 0;
    return 1;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
#define all(a) (a).begin(), (a).end()

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST() : root(NULL) {}

    void insert(int val)
    {
        root = insertNode(root, val);
    }

private:
    Node *insertNode(Node *node, int val)
    {
        if (node == NULL)
        {
            return new Node(val);
        }
        if (val < node->data)
        {
            node->left = insertNode(node->left, val);
        }
        else
        {
            node->right = insertNode(node->right, val);
        }
        return node;
    }
};

Node *getsucc(Node *root)
{
    Node *curr = root->right;

    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deletekey(Node *root, int val) // Time complexity of this will be O(h) and it will take O(h) extra space as well .
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < val)
    {
        root->right = deletekey(root->right, val);
    }
    else if (root->data > val)
    {
        root->left = deletekey(root->left, val);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getsucc(root);
            root->data = succ->data;

            root->right = deletekey(root->right, succ->data);
        }
    }
    return root;
}

void solve()
{
    cout << "Enter Number of the Nodes : " << endl;
    int n;
    cin >> n;
    BST tree;
    cout << "Enter The Nodes : " << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cout << "Enter the key to be deleted :" << endl;
    int val;
    cin >> val;
    if (deletekey(tree.root, val))
    {
        cout << "deleted " << endl;
    }
    else
        cout << " Not found " << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}