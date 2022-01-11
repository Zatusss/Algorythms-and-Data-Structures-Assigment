#include"Node.h"
#include<iostream>
#include<string>
#include<algorithm>


Node::Node()
{
    //Object State
    //variables used for determining what properties created node will have

    this->isWall = false;//is this node an obstacle?
    this->isStart = false;//is this node a player start?
    this->isFinish = false;//is this the final goal?
    this->bvisited = false;//did player visit this node?
    this->IceFloor = false;//did player visit this node?
    this->isAPath = false;//did player visit this node?

    //Object Name
    //this varaible will store name of the new node based on object state
    this->objectName = " ";

}
 bool Node::isDestination(Node * current, Node * target) {
    if (current->Xcoordinate == target->Xcoordinate && current->Ycoordinate == target->Ycoordinate) {
        return true;
    }
    return false;
}
 std::string Node::ReturnObjectState(Node* ptr)
 {
     //new temporary vector for storing all possible vector states
     //add all states to the vector for traversal
     std::vector<bool> objetState;
     objetState.push_back(isWall);
     objetState.push_back(isStart);
     objetState.push_back(isFinish);
     objetState.push_back(bvisited);
     objetState.push_back(IceFloor);

     //while i is not bigger then size of vector
     //check if any of the states of current object  = true
     //if yes assign current object name to temp string
     //print name to console
     //return the value
     for (auto i = 0; i < objetState.size();i++)
     {
         if (objetState[i] == true)
         {
             std::string name = ptr->GetObjectName();
             std::cout << name << std::endl;
             return name;
         }
     }




    //i want to use this method to quickly check all possible sttes that object can be in
    //
 }

 