#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjLists;
    std::vector<bool> visited;

    void DFSUtil(int v);

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
    void DFS(int startVertex);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists.resize(vertices);
    visited.resize(vertices, false);
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

void Graph::BFS(int startVertex) {
    std::fill(visited.begin(), visited.end(), false);
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    std::cout << "BFS starting from vertex " << startVertex << " : ";

    while(!queue.empty()) {
        int currVertex = queue.front();
        std::cout << currVertex << " ";
        queue.pop();

        for(auto adjVertex : adjLists[currVertex]) {
            if(!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::DFSUtil(int vertex) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for(auto adjVertex : adjLists[vertex]) {
        if(!visited[adjVertex]) {
            DFSUtil(adjVertex);
        }
    }
}

Void Graph::DFS(int startVertex) {
    std::fill(visited.begin(), visited.end(), false);
    std::cout << "DFS starting from vertex " << startVertex << " : ";
    DFSUtil(startVertex);
    std::cout << std::endl;
}

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.BFS(0);
    g.DFS(0);

    return 0;
}
