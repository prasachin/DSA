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

void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void printgraph(vector<int> adj[], int n)
{
    cout << "The graph is as follow : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

bool DfSRec(vector<int> adj[], int s, bool visited[], bool recst[]) // approach based on the dfs traversal
{
    visited[s] = true;
    recst[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            if (DfSRec(adj, u, visited, recst) == true)
            {
                return true;
            }
        }
        else if (recst[u] == true)
        {
            return true;
        }
    }
    recst[s] = false;

    return false;
}

bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    bool recst[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recst[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (DfSRec(adj, i, visited, recst) == true)
            {
                return true;
            }
        }
    }
    return false;
}

void solve() // implentation for the undirected graph
{
    int v;
    cin >> v;
    vector<int> adj[v];

    cout << "Enter the number of the edges : " << endl;
    int b;
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        cout << "Enter u and v" << endl;
        int u, w;
        cin >> u >> w;
        addedge(adj, u, w);
    }

    printgraph(adj, v);

    if (DFS(adj, v) == true)
    {
        cout << "The graph contain cycle" << endl;
    }
    else
    {
        cout << "No cycle present " << endl;
    }
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