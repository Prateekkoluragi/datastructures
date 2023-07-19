#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for a graph node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for a graph
struct Graph {
    int numVertices;
    struct Node* adjacencyList[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int distance[MAX_VERTICES];
};

// Function to create a new graph node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
        graph->distance[i] = -1;
    }

    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform BFS
void BFS(struct Graph* graph, int startVertex) {
    graph->visited[startVertex] = 1;
    graph->distance[startVertex] = 0;

    struct Node* queue = createNode(startVertex);
    struct Node* front = queue;

    while (front != NULL) {
        int currentVertex = front->vertex;
        struct Node* temp = graph->adjacencyList[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                graph->distance[adjVertex] = graph->distance[currentVertex] + 1;

                struct Node* newNode = createNode(adjVertex);
                front->next = newNode;
                front = newNode;
            }

            temp = temp->next;
        }

        struct Node* prev = queue;
        queue = queue->next;
        free(prev);
        front = queue;
    }
}

int main() {
    int numVertices, numEdges,i;
    printf("Enter the number of individuals in the social network: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the number of connections in the social network: ");
    scanf("%d", &numEdges);

    printf("Enter the connections (individual1 individual2):\n");
    for (i = 0; i < numEdges; i++) {
        int ind1, ind2;
        scanf("%d %d", &ind1, &ind2);
        addEdge(graph, ind1, ind2);
    }

    int source, destination;
    printf("Enter the source individual: ");
    scanf("%d", &source);

    printf("Enter the destination individual: ");
    scanf("%d", &destination);

    BFS(graph, source);

    if (graph->distance[destination] != -1)
        printf("The degree of separation between %d and %d is %d.\n", source, destination, graph->distance[destination]);
    else
        printf("There is no connection between %d and %d.\n", source, destination);

    return 0;
}
