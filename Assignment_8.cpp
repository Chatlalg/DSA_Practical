#include <iostream>
using namespace std;

#define INF 9999

void dijkstra(int graph[10][10], int v, int src)
{

    // int *dist=new int[v];
    int dist[10] = {INF}; // Stores the shortest distances from the source
    bool visited[10] = {false}; // Tracks visited nodes
    
    dist[src] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < v - 1; count++)
    {
        int minDist = INF, u = -1;

        // Find the unvisited vertex with the minimum distance
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true; // Mark the chosen vertex as visited

        // Update distances for adjacent vertices
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && graph[u][i] != 0 && dist[u] != INF && dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    // Display the shortest distances
    cout << "\nVertex\tDistance from Source " << src << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int v, src;
    int graph[10][10]; // Maximum graph size is set to 10x10

    cout << "Enter number of nodes (<=10): ";
    cin >> v;

    cout << "Enter adjacency matrix (enter 0 for no edge):\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
            if (i == j)
            {
                graph[i][j] = 0; // Distance to itself is 0
            }
        }
    }

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, v, src);

    return 0;
}