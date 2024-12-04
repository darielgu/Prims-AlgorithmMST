#include "graph.h"
#include <fstream>
#include <iostream>
//Heap Struct
struct Node{
    int vertex;
    int weight;
};
//Creating minHeap class
class minHeap{
private:
    std::vector<Node> heap;
    int size;
    void heapifyUp(int index){
        while(index>0) {
            int parent = (index - 1) / 2;
            if (heap[index].weight < heap[parent].weight) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int index){
        int smallest = index;
        int left = 2 * index +1;
        int right = 2 * index +2;
        if (left<size && heap[left].weight < heap[smallest].weight ){
            smallest = left;
        }
        if(right<size && heap[right].weight < heap[smallest].weight){
            smallest = right;
        }
        if(smallest != index){
            std::swap(heap[index], heap[smallest]);
            heapifyDown(index);
        }
    }
public:
    minHeap(int numNodes){
        heap = std::vector<Node>(numNodes);
        size = 0;
    }
    bool isEmpty(){
        return size == 0;
    }
    void insert(int vertex, int weight){
        heap[size].vertex = vertex;
        heap[size].weight = weight;
        heapifyDown(size);
        size++;
    }
    Node removeMin(){
        if(size=0){
            return {-1,INT_MAX};
        }
        Node root = heap[0];
        Node last = heap[size];

    }
};

// Load the graph from a file
bool Graph::loadGraphFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        return false;
    }
    int numEdges;
    infile >> numNodes >> numEdges;
    // Set perpendicular to 0
    for (int i = 1; i <= numNodes; ++i) {
        adjMatrix[i][i] = 0;
    }
    // Implement the adjacency matrix setup
    adjMatrix.resize(numNodes+1,std::vector<int>(numNodes+1, INF) );


//Adjacency Matrix Initialization
    for(int i = 0; i<numEdges; i++){
        int y, z, weight;
        infile>>y>>z>>weight;
        adjMatrix[y][z] = weight;
        adjMatrix[z][y] =weight;
    }

    infile.close();
    return true;
}
//Heap Node Structure and functions
struct Heap{
    int vertex;
    int weight;
};






// Prim's algorithm to find the MST
int Graph::primMST(std::vector<int>& mstStart, std::vector<int>& mstEnd) {
    // Placeholder for visited nodes and minimum weight initialization
//Implement Prim's
    // Steps:
    // 1. Initialize visited array and minWeight array
    std::vector<bool> visited(numNodes+1, false);
    std::vector<int> minWeight(numNodes+1, INF);
    // 2. Start from node 1
        //    visited[1] = true;
    int start = 1;
    minWeight[start] = 0;
    int totalCost = 0;
    // 3. Use a loop to find the minimum weight edge at each step
    for (int i = 0; i<numNodes; i++){
        int u =-1;
    }



    // 4. Update MST edges (mstStart and mstEnd vectors)
    // 5. Return the total cost of the MST

    // Placeholder output
    mstStart.push_back(1);
    mstEnd.push_back(2);
    std::cout << "TODO: Replace placeholder MST output with the actual MST.\n";

    return 0; // TODO: Return the actual total cost of the MST
}