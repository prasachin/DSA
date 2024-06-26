#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

class DisjointSet
{
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // Path compression to further optimize .
        }
        return parent[u];
    }

    void unionSets(int u, int v) // Here we are performing union by rank to optimize like it give O(logn ) efficiency .
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Kruskal
{
private:
    vector<Edge> edges;
    int V;

public:
    Kruskal(int V) : V(V) {}

    void addEdge(int u, int v, int weight)
    {
        edges.push_back({u, v, weight});
    }

    int findMST()
    {
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);

        int mstWeight = 0;
        vector<Edge> mstEdges;

        for (auto &edge : edges)
        {
            if (ds.find(edge.src) != ds.find(edge.dest))
            {
                ds.unionSets(edge.src, edge.dest);
                mstWeight += edge.weight;
                mstEdges.push_back(edge);
            }
        }

        cout << "Edges in the MST:\n";
        for (auto &edge : mstEdges)
        {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
        }

        return mstWeight;
    }
};

int main()
{
    cout << "Enter the Number of vertices" << endl;
    int v;
    cin >> v;

    Kruskal kruskal(v);

    cout << "Enter the number of edeges " << endl;
    int u;
    cin >> u;
    for (int i = 0; i < u; i++)
    {
        cout << "Enter source , destination and weight of this edge :" << endl;
        int src, dest, wt;
        cin >> src >> dest >> wt;
        kruskal.addEdge(src, dest, wt);
    }
    cout << "Weight of MST is " << kruskal.findMST() << endl;

    return 0;
}
