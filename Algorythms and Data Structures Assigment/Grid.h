#pragma once
#include<vector>
#include<string>
#include<unordered_set>
#include"Node.h"




class Grid
{
private:
    //streams related
    std::string ReadMaprDoc = "";
  
    std::string  myLine;
    std::string input;
    int mazeSize = 0;
    char i;
    bool pickedDoc = false;
    int maxNrOFFiles;

    int docID = 0;
    std::string path = "C:/Users/Fabian/Desktop/Algorythms and Data Structures Assigment/Algorythms and Data Structures Assigment/MazeInput";


    static const int size =10 ;//size of maze(static and const is required otherwise comiler will give errors)
    
    Node* start;//wchich node to start serch from
    Node* target;//wchich node needs toi be found and reached
    Node* currentNode;//stors current node the software is currently visiting
    Node* maze[size][size];// array 2D for storing created nods
    std::vector <Node*> allNodes;//all nodes of the map in order //Kind of usless

    std::unordered_set<Node*> forests;//cost for weighted grid traversal
public:
    std::string mazefile;//string map used for printing grid
    char buffer;//stores info coming from mazefile for flow control

    //CONSTRUCTOR
    Grid();

    //GETTERS
    Node* GetStartNode() { return this->start; }//get start node pointer of current grid
    Node* GetTargetNode() { return this->target; }//get targer/finish node pointer of current grid
    Node* GetCurrentNode() { return this->currentNode; }//get  node pointer of currently visited node
    std::vector <Node*> GetAllNodes() { return this->allNodes; }//get start node pointer of current grid//Kind of usless
    
    //SETTERS
    Node* SetCurrentNode(Node* ptr) { this->currentNode = ptr;return this->currentNode; }//sets current node to be choosen node ptr

    //FUNCTIONS
    void CreateGraphGrid();//creates data structure in heap/inisialize key values/connects neigbours/adds evryting to maze array 2d
    void PrintGrid();//prints un-traversed state of grid
    void PrintMapSymbols(int i, int j);//based on state bool prints right symbol and assignes corret name 

    
    void PrintsAlgorithmPath(std::vector<Node*> path);
    //cost of traveling between nodes for dijkstra and a*
    //if condition is true i get 5 if false 1
    

    double CostOfTravel(Node* from_node, Node* to_node)
        const {
        return forests.find(to_node) != forests.end() ? 5 : 1;
    }
    void AddNeighbours(int size);
    void SetUpNodeState(std::string size);
    void ReadFile();
    void PrintAllMAzeFiles();
};

