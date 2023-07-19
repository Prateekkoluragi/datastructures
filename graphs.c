#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize a graph
void initializeGraph(Graph* graph, int numVertices) {
    int i,j;
    graph->numVertices = numVertices;

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}

// Function to perform DFS traversal recursively
void DFS(Graph* graph, int vertex, int* visited) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    Graph graph;
    int numVertices, source, destination,i;
    FILE* inputFile;

    // Open the input file
    inputFile = fopen("graph_input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // Read the number of vertices from the input file
    fscanf(inputFile, "%d", &numVertices);

    // Initialize the graph
    initializeGraph(&graph, numVertices);

    // Read the edges from the input file
    while (fscanf(inputFile, "%d %d", &source, &destination) == 2) {
        addEdge(&graph, source, destination);
    }

    // Close the input file
    fclose(inputFile);

    // Initialize the visited array
    int visited[MAX_VERTICES];
    for (i = 0; i < graph.numVertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS traversal starting from vertex 0
    printf("DFS traversal: ");
    DFS(&graph, 0, visited);
    printf("\n");

    return 0;
}
