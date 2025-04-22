// #include <iostream>
// #include <map>
// #include <vector>
// #include <set>
// using namespace std;

// map<string, vector<string>> graph;
// set<string> visited;

// void dfs(string& node) {
//     if (visited.count(node)) return;
//     visited.insert(node);
//     cout << node << " ";

//     for (string& neighbor : graph[node]) {
//         dfs(neighbor);
//     }
// }

// int main() {
//     int edges;
//     cout << "Enter number of edges: ";
//     cin >> edges;

//     cout << "Enter edges (e.g., A B or 1 2):\n";
//     for (int i = 0; i < edges; ++i) {
//         string u, v;
//         cin >> u >> v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);  // undirected graph
//     }

//     string start;
//     cout << "Enter starting node: ";
//     cin >> start;

//     cout << "DFS Traversal: ";
//     dfs(start);
//     cout << endl;

//     return 0;
// }
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int main() {
    map<string, vector<string>> graph;
    set<string> visited;
    int edges;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (e.g., A B or 1 2):\n";
    for (int i = 0; i < edges; ++i) {
        string u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // undirected graph
    }

    string start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    stack<string> s;
    s.push(start);

    while (!s.empty()) {
        string node = s.top();
        s.pop();

        if (visited.count(node)) continue;
        visited.insert(node);
        cout << node << " ";

        // for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
        //     if (!visited.count(*it)) {
        //         s.push(*it);
        //     }
        // }
        for (auto &neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                s.push(neighbor);
            }
        }
        
    }

    cout << endl;
    return 0;
}
