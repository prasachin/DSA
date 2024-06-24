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

struct trieNode
{
    trieNode *child[26];
    bool isend;

    trieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isend = false;
    }
};

void insert(trieNode *root, string &key)
{
    trieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
        {
            curr->child[index] = new trieNode();
        }
        curr = curr->child[index];
    }
    curr->isend = true;
}

bool search(trieNode *root, string &key)
{
    trieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
        {
            return false;
        }
        curr = curr->child[index];
    }
    return curr->isend;
}

bool isempty(trieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

trieNode *dlt(trieNode *root, string key, int i)
{
    if (root == NULL)
        return NULL;
    if (i == key.length())
    {
        root->isend = false;
        if (isempty(root))
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->child[index] = dlt(root->child[index], key, i + 1);
    if (isempty(root) && root->isend == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
}

void solve()
{
    cout << "Enter number of words: " << endl;
    ;

    int n;
    cin >> n;

    trieNode *root = new trieNode();

    cout << "Enter words:" << endl;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        insert(root, word);
    }
    dlt(root, "prakas", 0);
    cout
        << "Enter the key to be searched : " << endl;
    string key;
    cin >> key;
    if (search(root, key))
    {
        cout << "Yes , the words is in this dictionary :" << endl;
    }
    else
        cout << "No , word not found " << endl;
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