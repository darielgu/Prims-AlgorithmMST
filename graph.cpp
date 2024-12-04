#include "graph.h"

#include <fstream>
#include <iostream>


//Heap class
    struct Node {
     int weight;
     int vertex;
 };
    class Minheap {
private:
        std::vector<Node> heap;
        int size;


        void heapifyUp(int index) {
            while(index>0) {
                int parent = (index-1)/2;
                if(heap[parent].weight > heap[index].weight) {
                std::swap(heap[parent],heap[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
    void heapifyDown(int index) {
        while(true) {
            int left = 2 * index + 1 ;
            int right = 2 * index + 2 ;
            int smallest = index;

            if(left<size && heap[left].weight < heap[smallest].weight) {
                smallest = left;
            }
            if(right<size && heap[right].weight < heap[smallest].weight) {
                smallest = right;
            }
            if(smallest != index) {
                std::swap(heap[smallest], heap[index]);
                index = smallest;
            }
            else {
                break;
            }

        }
    }
public:
        Minheap(int numNodes) {
            size = 0;
            heap = std::vector<Node>(numNodes);
        }
        bool isEmpty() {
            return size == 0;
        }
        void insert(int vertex, int weight) {
            heap[size].vertex = vertex;
            heap[size].weight = weight;
            heapifyUp(size);
            size++;
        }
        Node removeMin() {
            if (size <= 0) {
                return {INT_MAX, -1};  // Return a sentinel value if heap is empty
            }
            Node root = heap[0];
            heap[0] = heap[size - 1];
            size--;
            if (size > 0) {
                heapifyDown(0);
            }
            return root;
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


    // Implement the adjacency matrix setup
    adjMatrix.resize(numNodes,std::vector<int>(numNodes, INF) );

    //Adjacency Matrix Initialization
    for(int i = 0; i<numEdges; i++){
        int y, z, weight;
        infile>>y>>z>>weight;
        adjMatrix[y-1][z-1] = weight;
        adjMatrix[z-1][y-1] =weight;
    }
    // Set perpendicular to 0
    for (int i = 0; i < numNodes; ++i) {
        adjMatrix[i][i] = 0;
    }

    infile.close();
    return true;
}




    // Prim's algorithm to find the MST
    int Graph::primMST(std::vector<int>& mstStart, std::vector<int>& mstEnd) {


    // Implement Prim's
    // 1. Initialize visited array and minWeight array
    std::vector<bool> visited(numNodes, false);
    std::vector<int> minWeight(numNodes, INF);

    // 2. Start from node 1
        Minheap heap(numNodes);
        int startNode = 0;
        minWeight[startNode] = 0;
        heap.insert(startNode, 0);
        int totalCost = 0;
    // 3. Use a loop to find the minimum weight edge at each step
        while (!heap.isEmpty()) {     // while the heap is not empty
            Node extracted = heap.removeMin();   // remove the minimum edge
            int weight = extracted.weight;       // extract weight and vertex
            int currentVertex = extracted.vertex;

            if (visited[currentVertex]) {  // if we have already visited the vertex skip loop iteration
                continue;
            }

            visited[currentVertex] = true; // set the vertex to visited

            if (!mstEnd.empty()) {
                mstStart.push_back(mstEnd.back()); // **Use the last node in mstEnd as the starting node**
                mstEnd.push_back(currentVertex + 1); // **Convert back to 1-based indexing for output**
            } else if (weight != 0) {
                mstStart.push_back(1); // **For the first edge, start from node 1**
                mstEnd.push_back(currentVertex + 1); // **Convert back to 1-based indexing**
            }

            totalCost += weight;

            for (int v = 0; v < numNodes; v++) {
                int edgeWeight = adjMatrix[currentVertex][v];

                if (edgeWeight != INF && !visited[v] && edgeWeight < minWeight[v]) {
                    minWeight[v] = edgeWeight;  // Update the minimum weight for this vertex
                    heap.insert(v, edgeWeight);  // Reinsert the vertex with updated weight
                }
            }
        }




    // 4. Update MST edges (mstStart and mstEnd vectors)
    // 5. Return the total cost of the MST

    // Placeholder output
    // mstStart.push_back(1);
    // mstEnd.push_back(2);
    // std::cout << "TODO: Replace placeholder MST output with the actual MST.\n";

    return totalCost; // TODO: Return the actual total cost of the MST
}