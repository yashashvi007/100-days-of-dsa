#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    int V;

    list<int> *adjList;

public:
    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    bool cycle(int v, bool visited[], bool dfsCyc[])
    {
        visited[v] = true;
        dfsCyc[v] = true;

        for (auto it : adjList[v])
        {
            if (!visited[it])
            {
                if (cycle(it, visited, dfsCyc))
                {
                    return true;
                }
            }
            else if (dfsCyc[it])
            {
                return true;
            }
        }

        dfsCyc[v] = false;
        return false;
    }

    bool isCyclic()
    {
        bool *visited = new bool[V]{false};
        bool *dfsCyc = new bool[V]{false};

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (cycle(i, visited, dfsCyc))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    return 0;
}