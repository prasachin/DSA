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
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

void insertnode(Node *&head, int val)
{
    Node *newnode = new Node(val);
    if (!head)
    {
        head = newnode;
        head->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

Node *insertatbegin(Node *head, int val) // tricky one as doing in O(1) time .
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
    }
}

Node *insertatend(Node *head, int val) // optimized O(1) solution
{
    Node *temp = new Node(val);
    if (!head)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = temp->data;
        temp->data = head->data;
        head->data = t;
        return temp;
    }
}

Node *deletebegining(Node *head)
{
    Node *temp = head;
    if (!head)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    else
    {
        head->data = head->next->data;
        Node *temp = head->next;
        head->next = head->next->next;
        delete temp;
        return head;
    }
}

Node *deleteatend(Node *head)
{
    if (!head)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != head)
    {
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = head;
    return head;
}

Node *insertatgiven(Node *head, int pos, int val)
{
    Node *temp = new Node(val);
    if (pos == 1)
    {
        return insertatbegin(head, val);
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++)
    {
        curr = curr->next;
    }
    if (curr->next == head && pos > 1)
    {
        delete temp;
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int search(Node *head, int x)
{
    int pos = 1;
    Node *curr = head;
    if (head == NULL)
    {
        return -1;
    }
    do
    {
        if (curr->data == x)
        {
            return pos;
        }
        curr = curr->next;
        pos++;
    } while (curr != head);
    return -1;
}

void solve()
{
    Node *head = NULL;
    cout << "Enter the number of element in the linkedlist :" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertnode(head, val);
    }

    cout << "The provided linkedlist are as follows :" << endl;

    print(head);

    cout << "\nAfer inserting 10 at the begining : " << endl;
    head = insertatbegin(head, 10);
    print(head);

    cout << "\nAfer inserting 10 at the end : " << endl;
    head = insertatend(head, 10);
    print(head);

    cout << "\nAfer deletion 10 from begining : " << endl;
    head = deletebegining(head);
    print(head);

    cout << "\nAfer deletion 10 from end : " << endl;
    head = deleteatend(head);
    print(head);

    cout << "\nAfer inserting 10 at pos 3 : " << endl;
    head = insertatgiven(head, 3, 10);
    print(head);

    cout << "\n Enter the element to be searched :" << endl;
    int x;
    cin >> x;
    cout << "Found at " << search(head, x) << endl;
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