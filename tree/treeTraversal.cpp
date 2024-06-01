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

void inorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void preordertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    else
        return;
}

void levelorder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

void printkdist(Node *root, int k) // it will print all the nodes at a distance of k from the root node .
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        printkdist(root->left, k - 1);
        printkdist(root->right, k - 1);
    }
}

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}

void solve()
{
    BST tree;
    cout << "Enter the number of nodes: " << endl;
    ;
    int n, val;
    cin >> n;

    cout << "Enter the values to insert into the BST:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        tree.insert(val);
    }

    cout << "Inorder traversal of the BST: " << endl;
    inorderTraversal(tree.root);
    cout << endl;
    cout << "PreorderTraversal of the BST :" << endl;
    preordertraversal(tree.root);
    cout << endl;
    cout << "Postorder traversal of the BST :" << endl;
    postorder(tree.root);
    cout << endl;
    cout << "The height of the tree is :" << endl;
    cout << height(tree.root) << endl;
    cout << "levelorder traversal of the BST :" << endl;
    postorder(tree.root);
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
    return 0;
}
