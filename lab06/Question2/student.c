#include "graph.h"

int count_isolated(Graph* g) {
    int isolated = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        int hasEdge = 0;

        for (int j = 0; j < MAX_NODES; j++) {
            if (g->adj[i][j] == 1) {
                hasEdge = 1;
                break;
            }
        }

        if (!hasEdge) {
            isolated++;
        }
    }

    return isolated;
}