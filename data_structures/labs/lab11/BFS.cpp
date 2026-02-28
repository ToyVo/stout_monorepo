#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_VERTICES 10
#define MAX_SIZE 100

// use this array for checking if a vertex is visited
bool visited[MAX_VERTICES];

struct Queue {
  int queue[MAX_SIZE];
  int front;
  int rear;
};

struct Graph {
  // adjacent matrix
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];
  // number of vertices
  int numVertex;
};

// initialize numVertex to 0 for a graph g
// initialize adjancent matrix of g to all 0
void init(Graph *g) {
  g->numVertex = 0;
  for (int i = 0; i < MAX_VERTICES; i++)
    for (int j = 0; j < MAX_VERTICES; j++)
      g->adjMatrix[i][j] = 0;
}

void insertVertex(Graph *g, int v) {
  if (g->numVertex == MAX_VERTICES) {
    cout << "Already reached maximum vertices" << endl;
    return;
  }

  // inserting a vertex v means nothing more than
  // incresing numVertex by 1
  g->numVertex++;
}

void insertEdge(Graph *g, int u, int v) {
  if (u >= g->numVertex || v >= g->numVertex) {
    cout << "Error: vertex range 0 ~ N-1" << endl;
    return;
  }

  // adding an edge between u and v means
  // set adjMatrix[u][v] to 1
  // set adjMatrix[v][u] to 1
  g->adjMatrix[u][v] = 1;
  g->adjMatrix[v][u] = 1;
}

void initQueue(Queue *q) {
  q->front = 0;
  q->rear = 0;
}

bool isFull(Queue *q) {
  if ((q->rear + 1) % MAX_SIZE == q->front)
    return true;
  else
    return false;
}

bool isEmpty(Queue *q) {
  if (q->front == q->rear)
    return true;
  else
    return false;
}

void enqueue(Queue *q, int data) {
  if (isFull(q))
    cout << "Graph G is full" << endl;
  else {
    q->queue[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_SIZE;
  }
}

int dequeue(Queue *q) {
  int tmp = -1;
  if (isEmpty(q))
    cout << "Graph G is empty" << endl;
  else {
    tmp = q->queue[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
  }
  return tmp;
}

void bfs(Graph *g, int curVertex) {
  // create a queue and initialize it
  Queue q;
  initQueue(&q);

  // record the current vertex is visited
  // and enqueue it
  visited[curVertex] = true;
  enqueue(&q, curVertex);

  int searchVertex;

  // if queue is not empty
  while (!isEmpty(&q)) {
    // dequeue the vertex at the front
    // visit the vertex (display its value)
    searchVertex = dequeue(&q);
    cout << searchVertex << "->";

    // check each vertex if it is adjacent to curVertex
    // (adjMatrix[curVertex][vertex] == 1)
    // and check if it is not visited
    // then record it is visited and enqueue that vertex
    for (int vertex = 0; vertex < MAX_VERTICES; vertex++) {
      if (g->adjMatrix[searchVertex][vertex] == 1 && visited[vertex] == false) {
        visited[vertex] = true;
        enqueue(&q, vertex);
      }
    }
  }
}

int main() {
  // create a graph
  Graph g;

  // initialize a graph
  init(&g);

  // initialize the array that shows
  // if a particular vertex is visited
  for (int i = 0; i < MAX_VERTICES; i++)
    visited[i] = false;

  // insert seven vertices 0, 1, . . , 6
  for (int i = 0; i < 7; i++)
    insertVertex(&g, i);

  // insert edges between v and u
  insertEdge(&g, 0, 4);
  insertEdge(&g, 0, 6);
  insertEdge(&g, 1, 3);
  insertEdge(&g, 3, 5);
  insertEdge(&g, 4, 1);
  insertEdge(&g, 4, 2);
  insertEdge(&g, 6, 2);

  // Breath-First Search starting at vertex 0
  bfs(&g, 0);

  cout << "done" << endl << endl;
}
