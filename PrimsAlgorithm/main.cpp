//
// Eric Bollar
// Advanced Topics in CS, Period E
// 10 November 2020
//

#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct Edge {
    string start;
    string end;
    int weight;
    Edge(int weight, string start, string end) {
        this->weight = weight;
        this->start = start;
        this->end = end;
    }
    bool operator<(const Edge &rhs) const {
        return this->weight > rhs.weight;
    }
};

void initializeGraph(priority_queue<Edge> &graph) {
    graph.push(Edge(5, "A", "B"));
    graph.push(Edge(2, "A", "D"));
    graph.push(Edge(4, "B", "C"));
    graph.push(Edge(2, "B", "E"));
    graph.push(Edge(8, "D", "B"));
    graph.push(Edge(7, "D", "E"));
    graph.push(Edge(3, "C", "F"));
    graph.push(Edge(6, "C", "E"));
    graph.push(Edge(1, "E", "F"));
}

priority_queue<Edge> primsAlgorithm(priority_queue<Edge> &graph, int numVertices) {
    set<string> visited;
    set<Edge> chosen;
    priority_queue<Edge> temp;
    visited.insert(graph.top().start);
    while (visited.size() < numVertices) {
        string s = graph.top().start;
        string e = graph.top().end;
        bool found = false;
        for (set<string>::iterator itr = visited.begin(); itr != visited.end(); itr++) {
            if (*itr == s) {
                found = true;
                visited.insert(e);
            } else if (*itr == e) {
                found = true;
                visited.insert(s);
            }
            if (found) {
                chosen.insert(graph.top());
                while (!temp.empty()) {
                    graph.push(temp.top());
                    temp.pop();
                }
            }
        }
        if (!found) {
            temp.push(graph.top());
        }
        graph.pop();
    }
    priority_queue<Edge> out;
    for (set<Edge>::iterator itr = chosen.begin(); itr != chosen.end(); itr++) {
        out.push(*itr);
    }
    return out;
}

int main() {
    priority_queue<Edge> graph;
    initializeGraph(graph);
    priority_queue<Edge> mst = primsAlgorithm(graph, 6);

    while (!mst.empty()) {
        Edge e = mst.top();
        cout << e.start << "-" << e.end << " (" << e.weight << ") " << endl;
        mst.pop();
    }

    return 0;
}
