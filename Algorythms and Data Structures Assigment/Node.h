#pragma once
#include <vector>
#include <cmath>
#include <string>

struct Node
{

    //Bools for checking object properties
    bool isWall;//is this node an obstacle?
    bool isStart;//is this node a player start?
    bool isFinish;
    bool bvisited;
    bool IceFloor;
    bool isAPath;

    std::string objectName =" ";

    //direction bools

    bool north;
    bool east;
    bool south;
    bool west;

    std::string directionsName;

    //Algorythm traversing variables for a*
    int gCost = 0;//acumulated distance from the start node to the current node that your at
    int hCost = 0;//estimated distance to the target Manhatan Distance
    int fCost = 0;//sum of both g and h cost
    

    int Xcoordinate = 0;//x cordinate
    int Ycoordinate=0;//y cordinate
    std::string nodeID = " ";//holds ID information of node (X,Y,name)

    Node* parent = nullptr;//whatever node discovered this node is a parent
    std::vector <Node*> connectedNodes;//all possible connections to this node
   


public:
    Node();
    
    //GETTERS
    bool GetisAPath() { return this->bvisited; }
    bool SetisAPath(bool i) { bvisited = i;return bvisited; }

    bool  GetNorth() { return this->north ; }
    bool  GetSouth() { return this->south ; }
    bool  GetWest() { return this->west ; }
    bool  GetEast() { return this->east ; }
   
    std::vector<bool> objetState;

    std::string GetDirectionName() { return directionsName; }

    bool* GetisFinish() {return &isFinish; }
    bool* GetisWall() { return &isWall; }
    std::vector <Node*> GetEdges() {return connectedNodes; }//all possible connections to this node

    int GetF() { return gCost + hCost; }//distance traveld + distance to targe
    

    std::string GetID() {
        std::string temp =
            ("[") + (std::to_string(Xcoordinate))
            + ("][Y]--") + (directionsName) +
            ("--[X][") + (std::to_string(Ycoordinate))
            + ("]") + ("[") + (objectName) + ("]")
            ;return temp;
    }
    
    
       
    
    //get node ID
    std::string SetID(int x, int y) { std::string temp = (std::to_string((Xcoordinate = x) + (Ycoordinate = y))); return temp; } //get node ID
    
    void SetDirectionName(std::string temp) { directionsName = temp; }

    std::string GetObjectName() { return objectName; }
    //Setters

    void SetNorth(bool temp) { north = temp; }
    void SetSouth(bool temp) { south = temp; }
    void SetWest(bool temp) { west = temp; }
    void SetEast(bool temp) { east = temp; }


    std::string SetObjectName(std::string newobjectName) { objectName = newobjectName;return objectName;}
                                                                
    
    //FUNCTIONS
    static bool isDestination(Node* current, Node* target);
    std::string ReturnObjectState(Node* ptr);
   
    
};


//keep in mind operator function needs to be declred outside of class when u want to overload operators
inline bool operator < (const Node& lhs, const Node& rhs)
{//We need to overload "<" to put our struct into a set
    return lhs.fCost < rhs.fCost;
}




