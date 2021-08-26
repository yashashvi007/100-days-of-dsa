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

    void addEdge(int u, int v, bool bidirectional = true)
    {
        adjList[u].push_back(v);

        if (bidirectional)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (int node : adjList[i])
            {
                cout << node << ",";
            }

            cout << endl;
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        bool *visited = new bool[V+1]{false}; 
        visited[src] = true;

        while(!q.empty()){
            int node = q.front();
            cout << node << " ";
            q.pop();
            for(int neighbour:adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(1, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(4, 2, false);
    
    // g.printAdjList();
    g.bfs(0);
    return 0;
}