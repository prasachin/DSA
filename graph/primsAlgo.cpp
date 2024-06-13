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

void addedge(vector<pii> adj[], int u, int v, int w)
{
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w); // Since the graph is undirected
}

void printgraph(vector<pii> adj[], int n)
{
    cout << "The graph is as follow : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto x : adj[i])
        {
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
}

void primMST(vector<pii> adj[], int V)
{
    // Priority queue to store (weight, vertex) pairs
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int src = 0; // Starting vertex

    // Vector to store the minimum cost to reach each vertex
    vector<int> key(V, INT_MAX);

    // Vector to store the parent of each vertex in the MST
    vector<int> parent(V, -1);

    // Vector to track vertices included in the MST
    vector<bool> inMST(V, false);

    pq.push({0, src});
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto &x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (!inMST[v] && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in the MST:" << endl;
    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }
}

void solve()
{
    cout << "Enter the number of vertices: " << endl;
    int v;
    cin >> v;
    vector<pii> adj[v];

    cout << "Enter the number of edges: " << endl;
    int b;
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        cout << "Enter u, v and w (where u-v with weight w): " << endl;
        int u, w, weight;
        cin >> u >> w >> weight;
        addedge(adj, u, w, weight);
    }

    printgraph(adj, v);

    primMST(adj, v);
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
