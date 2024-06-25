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

// Function to build the segment tree
void buildTree(vector<int> &segTree, int arr[], int start, int end, int node)
{
    if (start == end)
    {
        segTree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(segTree, arr, start, mid, 2 * node + 1);
    buildTree(segTree, arr, mid + 1, end, 2 * node + 2);
    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

// Function to get the sum of a range
int getSum(vector<int> &segTree, int start, int end, int l, int r, int node)
{
    // If range is outside the bounds
    if (r < start || l > end)
    {
        return 0;
    }
    // If range is completely within the bounds
    if (l <= start && r >= end)
    {
        return segTree[node];
    }
    // Partial overlap
    int mid = (start + end) / 2;
    int leftSum = getSum(segTree, start, mid, l, r, 2 * node + 1);
    int rightSum = getSum(segTree, mid + 1, end, l, r, 2 * node + 2);
    return leftSum + rightSum;
}

// Function to update the segment tree
void update(vector<int> &segTree, int start, int end, int index, int value, int node)
{
    if (start == end)
    {
        segTree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index <= mid)
    {
        update(segTree, start, mid, index, value, 2 * node + 1);
    }
    else
    {
        update(segTree, mid + 1, end, index, value, 2 * node + 2);
    }
    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n) cin >> a[i];

    // Initialize the segment tree with appropriate size
    int segTreeSize = 4 * n;
    vector<int> segTree(segTreeSize, 0);

    // Build the segment tree
    buildTree(segTree, a, 0, n - 1, 0);

    // Output the segment tree
    cout << "Segment Tree: ";
    for (int i = 0; i < segTreeSize; i++)
    {
        cout << segTree[i] << " ";
    }
    cout << endl;

    // Example usage of getSum and update
    int l, r;
    cout << "Enter range (l, r) to get sum: " << endl;
    cin >> l >> r;
    cout << "Sum of elements in range (" << l << ", " << r << ") is: " << getSum(segTree, 0, n - 1, l, r, 0) << endl;

    int index, value;
    cout << "Enter index and value to update: " << endl;
    cin >> index >> value;
    update(segTree, 0, n - 1, index, value, 0);

    cout << "Segment Tree after update: " << endl;
    for (int i = 0; i < segTreeSize; i++)
    {
        cout << segTree[i] << " ";
    }
    cout << endl;
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
