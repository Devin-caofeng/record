#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) { }
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> ump;
        return clone(node, ump);
    }

    UndirectedGraphNode *clone(UndirectedGraphNode *node,
                               unordered_map<int, UndirectedGraphNode *> &ump) {
        if (!node) return NULL;
        if (ump.count(node->label)) return ump[node->label];

        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        ump[node->label] = newNode;
        for (size_t i = 0; i < node->neighbors.size(); ++i) {
            (newNode->neighbors).push_back(clone(node->neighbors[i], ump));
        }

        return newNode;
    }

    UndirectedGraphNode *clone(UndirectedGraphNode *node) {
        if (!node) return NULL;

        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> unmp;
        if (unmp.find(node) == unmp.end()) {
            unmp[node] = new UndirectedGraphNode(node->label);
            for (auto neighbor : node->neighbors) {
                unmp[node]->neighbors.push_back(clone(neighbor));
            }
        }

        return unmp[node];
    }
};

int main() {
    return 0;
}
