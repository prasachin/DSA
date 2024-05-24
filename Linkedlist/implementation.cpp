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
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
}

void insertnode(Node *&head, int val)
{
    Node *newnode = new Node(val);
    if (!head)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

Node *insertatbegin(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}

Node *insertatend(Node *head, int val)
{
    Node *temp = new Node(val);
    if (!head)
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    return head;
}

Node *deletebegining(Node *head)
{
    Node *temp = head;
    if (!head)
    {
        return NULL;
    }
    head = head->next;
    free(temp);
    return head;
}

Node *deleteatend(Node *head)
{
    if (!head)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = NULL;
    return head;
}

Node *insertatgiven(Node *head, int pos, int val)
{
    Node *temp = new Node(val);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node *deleteatgiven(Node *head, int pos)
{
    if (!head)
    {
        return NULL;
    }
    if (pos == 1)
    {
        return deletebegining(head);
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL || curr->next == NULL)
    {
        return head;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete (temp);
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
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            return pos;
        }
        else
        {
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}

void printmiddle(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The middle element of this linkedlist is : " << (slow->data) << endl;
}

void printXthfromend(Node *head, int x)
{
    if (head == NULL)
    {
        return;
    }
    Node *fast = head, *slow = head;
    for (int i = 1; i <= x; i++)
    {
        if (!fast)
            return;
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << "The " << x << "th node from the end is : " << (slow->data) << endl;
}

Node *reversell(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *removeDuplicates(Node *head) // Given ll is sorted
{
    if (!head)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

Node *reverseIngroups(Node *head, int k)
{
    if (!head || k == 1)
        return head;

    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev_group_end = dummy;
    Node *curr = head;

    while (curr)
    {
        Node *group_start = curr;
        Node *group_end = curr;
        for (int i = 1; i < k && group_end->next; i++)
        {
            group_end = group_end->next;
        }
        Node *next_group_start = group_end->next;
        Node *prev = next_group_start;
        Node *current = group_start;

        while (current != next_group_start)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        prev_group_end->next = group_end;
        prev_group_end = group_start;
        curr = next_group_start;
    }
    head = dummy->next;
    delete dummy;
    return head;
}

void deletebypointer(Node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    if (ptr->next == NULL)
    {
        return;
    }
    else
    {
        Node *temp = ptr->next;
        ptr->data = temp->data;
        ptr->next = temp->next;
        delete (temp);
    }
}

Node *segragate(Node *head)
{
    Node *ee = NULL, *es = NULL, *os = NULL, *oe = NULL;

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        int x = curr->data;
        if (x % 2 == 0)
        {
            if (es == NULL)
            {
                es = curr;
                ee = curr;
            }
            else
            {
                ee->next = curr;
                ee = ee->next;
            }
        }
        else
        {
            if (os == NULL)
            {
                os = curr;
                oe = curr;
            }
            else
            {
                oe->next = curr;
                oe = oe->next;
            }
        }
    }

    if (os == NULL || es == NULL)
    {
        return head;
    }
    else
    {
        ee->next = os;
        oe->next = NULL;
        return es;
    }
}

Node *pairwiseswap(Node *head) // this is just swaping the data rather than  any pointer .
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
    return head;
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

    cout << "\nAfer deleting 10 from pos 3 : " << endl;
    head = deleteatgiven(head, 3);
    print(head);

    cout << "\n Enter the element to be searched :" << endl;
    int x;
    cin >> x;
    cout << "Found at " << search(head, x) << endl;

    printmiddle(head);
    int y;
    cout << "\n Enter the node number to be searched from end " << endl;
    cin >> y;
    printXthfromend(head, y);

    cout << "\n The reversed LinkedList is : " << endl;
    head = reversell(head);
    print(head);

    cout << "\n After removal of Duplicates: " << endl;
    head = removeDuplicates(head);
    print(head);

    int z;
    cout << "\nEnter the group number in which ll to be reversed : " << endl;
    cin >> z;

    cout << "\n After reversing in groups : " << endl;
    head = reverseIngroups(head, z);
    print(head);

    cout << "\n After segragating even and the odd elements : " << endl;
    head = segragate(head);
    print(head);

    cout << "\n After swaping pairwise : " << endl;
    head = pairwiseswap(head);
    print(head);
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