#include <iostream>
#include <map>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int v;
    list<int> *ajd;

public:
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[this->v];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void fill(int v, bool visited[], stack<int> &Stack)
    {
        visited[v] = true;

        list<int>::iterator itr;

        for (itr = adj[v].begin(); itr != adj[v].end(); itr++)
        {
            if (!visited[*itr])
            {
                fill(*itr, visited, Stack);
            }
        }

        Stack.push(v);
    }

    void dfs(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator itr;

        for (itr = adj.begin(); itr != adj.end(); itr++)
        {
            if (!visited[*itr])
            {
                dfs(*itr, visited);
            }
        }
    }

    Graph transpose()
    {
        Graph g(this->v);

        for (int v = 0; v < V; v++)
        {
            list<int>::iterator itr;

            for (itr = adj[v].begin(); itr != adj[v].end(); itr++)
            {
                ajd[*itr].push_back(v);
            }
        }

        return g;
    }

    
};

int main()
{

    return 0;
}
