#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>

template<typename T>
class Graph {
private:
    int numVertices;
    std::unordered_map<T, std::list<T>> adjLists;
    std::unordered_map<T, bool> visited;

    void DFSUtil(T v);

public:
    Graph(int vertices);
    void addEdge(T src, T dest);
    void BFS(T startVertex);
    void DFS(T startVertex);
};

template<typename T>
Graph<T>::Graph(int vertices) {
    numVertices = vertices;
}

template<typename T>
void Graph<T>::addEdge(T src, T dest) {
    adjLists[src].push_back(dest);
}

template<typename T>
void Graph<T>::BFS(T startVertex) {
    for(auto& pair : visited) {
        pair.second = false;
    }

    std::queue<T> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    std::cout << "BFS starting from vertex " << startVertex << " : ";

    while(!queue.empty()) {
        T currVertex = queue.front();
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

template<typename T>
void Graph<T>::DFSUtil(T vertex) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for(auto adjVertex : adjLists[vertex]) {
        if(!visited[adjVertex]) {
            DFSUtil(adjVertex);
        }
    }
}

template<typename T>
void Graph<T>::DFS(T startVertex) {
    for(auto& pair : visited) {
        pair.second = false;
    }

    std::cout << "DFS starting from vertex " << startVertex << " : ";
    DFSUtil(startVertex);
    std::cout << std::endl;
}

int main() {
    
    Graph<int> g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    std::cout << "Integer Graph:" << std::endl;
    g.BFS(0);
    g.DFS(0);

 
    Graph<std::string> gs(5);
    gs.addEdge("A", "B");
    gs.addEdge("A", "C");
    gs.addEdge("B", "D");
    gs.addEdge("C", "D");
    gs.addEdge("D", "E");

    std::cout << "\nString Graph:" << std::endl;
    gs.BFS("A");
    gs.DFS("A");

    return 0;
}
