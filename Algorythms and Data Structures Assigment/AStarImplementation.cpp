#include "AStarImplementation.h"
#include "Grid.h"
#include "Node.h"
#include <queue>
#include <unordered_set>
#include <iostream>
#include <windows.h>
#include <unordered_map>
#include <map>


//BFS Serch
void AStarImplementation::breadth_first_search(Grid* graph, Node* start) {

    std::queue<Node*> frontier;//Holds
    frontier.push(start);

    std::unordered_set<Node*> reached;
    reached.insert(start);

    std::map<Node*, Node*> orderdListOfMovement;
    orderdListOfMovement[start] = start;





    std::cout << "-------Visited vertex-------" << std::endl;
    while (!frontier.empty()) {
        //create new node to store first item in queue
        //change visited to true for the 2 grid print
        //delete the oldest object in queue
        //assign new value to graph current node(used for traversing)
        Node* current;
        current = frontier.front();
        current->bvisited = true;
        frontier.pop();
        graph->SetCurrentNode(current);

        //player will not travel throu obstacles
        if (current->GetObjectName() != "Wall") {

            //change current node pointer inside graph
            //with out this traversing is imposible
             //print all visited nodes IDs to screen
            std::string id = current->GetID();
            std::cout << id << std::endl;

            //if current object  is equal to target stop job is finished
            if (current->GetObjectName() == "Finish") {
                break;
            }

            //run this for the amoutof  connected objects  1-4 times
            for (Node* next : graph->GetCurrentNode()->GetEdges()) {/*    GetEdgesOfCurrentNode(graph->GetCurrentNode()*/
                if (orderdListOfMovement.find(next) == orderdListOfMovement.end()) {
                    frontier.push(next);
                    orderdListOfMovement[next] = current;


                }
            }
        }
    }
}

//Dijkstras Serch
void AStarImplementation::DijkstrasAlgorithm
(Grid* wieghtedgraph, Node* start, Node* target,
    std::unordered_map<Node*, Node*>& came_from,
    std::unordered_map<Node*, double>& cost_so_far)
{

    /*The frontier contains all of the paths that could form
    initial segments of paths from a start node to a goal node*/
    PriorityQueue<Node*, double> frontier;

    frontier.put(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;




    std::cout << "-------Visited vertex-------" << std::endl;
    while (!frontier.empty()) {
        Node* current;
        current = frontier.get();
        wieghtedgraph->SetCurrentNode(current);
        current->bvisited = true;

        if (current->GetObjectName() != "Wall") {

            //change current node pointer inside graph
            //with out this traversing is imposible
             //print all visited nodes IDs to screen


            if (current->GetObjectName() == "Finish") {
                break;
            }

            for (Node* next : wieghtedgraph->GetCurrentNode()->GetEdges()) {

                double new_cost = cost_so_far[current] +
                    wieghtedgraph->CostOfTravel(current, next);

                if (cost_so_far.find(next) == cost_so_far.end()
                    || new_cost < cost_so_far[next]) {

                    cost_so_far[next] = new_cost;
                    came_from[next] = current;
                    frontier.put(next, new_cost);
                }

            }
        }
    }
}


//A Star Serch
std::vector<Node*> reconstruct_path(
    Node* start, Node* goal,
    std::unordered_map<Node*, Node*> came_from
) {
    //new vector to store algorythms path
    //assign target to temporary node variable
    std::vector<Node*> path;
    Node* current = goal;

    //until algorythm didnt find state
    //add current nod to path vector

    while (current != start) {
        path.push_back(current);
        current = came_from[current];
        current->SetisAPath(true);

    }
    path.push_back(start); // optional
    std::reverse(path.begin(), path.end());
    return path;
}

void AStarImplementation::SlideAlgorythm
(Grid* wieghtedgraph,
    Node* start,
    Node* goal,
    std::unordered_map<Node*,
    Node*>& came_from,
    std::unordered_map<Node*,
    double>& cost_so_far)
{

    PriorityQueue<Node*, double> frontier;

    frontier.put(start, GetManhatanDistance(start, goal));

    came_from[start] = start;
    cost_so_far[start] = 0;

    std::cout << start->GetID() << std::endl;

    while (wieghtedgraph->GetCurrentNode() != goal)
    {

        Node* current;
        current = frontier.get();
        wieghtedgraph->SetCurrentNode(current);
        current->SetisAPath(true);
        bool noObstacle = true;

        if (current == goal)
        {
            std::cout << goal->GetID() << std::endl;
            break;
        }

        while (noObstacle)
        {




            for (Node* next : wieghtedgraph->GetCurrentNode()->GetEdges())
            {



                if (next->Xcoordinate < current->Xcoordinate && next->Ycoordinate == current->Ycoordinate)
                {
                    next->SetDirectionName("South");
                    next->SetSouth(true);

                }

                else if (next->Xcoordinate > current->Xcoordinate && next->Ycoordinate == current->Ycoordinate)
                {
                    next->SetDirectionName("North");
                    next->SetNorth(true);

                }

                else if (next->Ycoordinate > current->Ycoordinate && next->Xcoordinate == current->Xcoordinate)
                {
                    next->SetDirectionName("East");
                    next->SetEast(true);
                }

                else if (next->Ycoordinate < current->Ycoordinate && next->Xcoordinate == current->Xcoordinate)
                {
                    next->SetDirectionName("West");
                    next->SetWest(true);
                }

                double new_cost = cost_so_far[current] + wieghtedgraph->CostOfTravel(current, next);

                if (next->GetObjectName() != "Wall") {



                    cost_so_far[next] = new_cost;
                    double priority = new_cost + GetManhatanDistance(next, goal);

                    frontier.put(next, priority);
                    came_from[next] = current;


                }




                if (next->GetDirectionName() == "South" && next->GetObjectName() != "Wall")
                {
                    current = next;

                    current->SetisAPath(true);



                    cost_so_far[current] = new_cost;
                    double priority = new_cost + GetManhatanDistance(current, goal);

                    frontier.put(current, priority);
                    came_from[current] = current;
                    wieghtedgraph->SetCurrentNode(current);
                    std::cout << current->GetID() << std::endl;




                }
                else if (next->GetDirectionName() == "South" && next->GetObjectName() == "Wall")
                {

                    cost_so_far[current] = new_cost;
                    double priority = new_cost + GetManhatanDistance(current, goal);

                    frontier.put(current, priority);
                    came_from[current] = current;

                    std::cout << current->GetID() << std::endl;

                    noObstacle = false;


                }


                if (next->GetDirectionName() == "West" && next->GetObjectName() != "Wall")
                {
                    current = next;

                    current->SetisAPath(true);



                    cost_so_far[current] = new_cost;
                    double priority = new_cost + GetManhatanDistance(current, goal);

                    frontier.put(current, priority);
                    came_from[current] = current;
                    wieghtedgraph->SetCurrentNode(current);
                    std::cout << current->GetID() << std::endl;




                }
                else if (next->GetDirectionName() == "West" && next->GetObjectName() == "Wall")
                {

                    cost_so_far[current] = new_cost;
                    double priority = new_cost + GetManhatanDistance(current, goal);

                    frontier.put(current, priority);
                    came_from[current] = current;

                    std::cout << current->GetID() << std::endl;

                    noObstacle = false;


                }

            }


        }









        while (!noObstacle)
        {

            for (Node* next : wieghtedgraph->GetCurrentNode()->GetEdges()) {


                double new_cost = cost_so_far[current] + wieghtedgraph->CostOfTravel(current, next);

                if (cost_so_far.find(next) == cost_so_far.end()
                    || new_cost < cost_so_far[next]) {

                    if (next->Xcoordinate < current->Xcoordinate && next->Ycoordinate == current->Ycoordinate)
                    {
                        next->SetDirectionName("South");
                        next->SetSouth(true);

                    }

                    else if (next->Xcoordinate > current->Xcoordinate && next->Ycoordinate == current->Ycoordinate)
                    {
                        next->SetDirectionName("North");
                        next->SetNorth(true);

                    }

                    else if (next->Ycoordinate > current->Ycoordinate && next->Xcoordinate == current->Xcoordinate)
                    {
                        next->SetDirectionName("East");
                        next->SetEast(true);
                    }

                    else if (next->Ycoordinate < current->Ycoordinate && next->Xcoordinate == current->Xcoordinate)
                    {
                        next->SetDirectionName("West");
                        next->SetWest(true);
                    }

                    if (next->GetObjectName() != "Wall") {


                        cost_so_far[current] = new_cost;
                        double priority = new_cost + GetManhatanDistance(current, goal);

                        frontier.put(current, priority);
                        came_from[current] = current;

                        current = next;






                        noObstacle = true;












                    }
                }




            }
        }

    }






}

void  AStarImplementation::RunChoosenAlgorythm()
{
    //remeber to change debug window line memory to have every thing printed
    //I have weird bug where if S and F is to far away first state of the map wont print togeather with some object IDs
    //The Best way of fixing this is redirecting resoult of serch to txt file 
    //or simply go to properties and change buffer size and screen buffer size


    //BFS serch on Grid

    int whatToRun = 0;
    std::cout << "Developer: Fabian Pryba " << std::endl;
    std::cout << "Student ID: w1836469 " << std::endl;
    std::cout << "Welcome to my algorythms and data structure assigment" << std::endl << std::endl;

    std::cout << "Remember A Star is my choosen algorythm for this assigment" << std::endl <<
        "I have implemented more then on just for the learning experience" << std::endl << std::endl;



    std::cout << "[1] BFS" << std::endl;
    std::cout << "[2] Dijkstras" << std::endl;
    std::cout << "[3] A Star" << std::endl;
    std::cout << "[4] Sliding" << std::endl;

    std::cout << "Enter choice using INT value 1-3" << std::endl;
    std::cout << "[]";
    std::cin >> whatToRun;

    //BFS serch on Grid
    if (whatToRun == 1)
    {
        Grid g;
        Grid* ptr = &g;
        g.CreateGraphGrid();
        g.PrintGrid();
        AStarImplementation a;
        a.breadth_first_search(&g, ptr->GetStartNode());
        ptr->PrintGrid();
    }
    //Dijkstras Algorithm search on Grid
    if (whatToRun == 2)
    {
        Grid g;
        Grid* ptr = &g;
        std::unordered_map<Node*, Node*> came_from;
        std::unordered_map<Node*, double> cost_so_far;
        std::vector<Node*> path = reconstruct_path(g.GetStartNode(), g.GetTargetNode(), came_from);

        g.CreateGraphGrid();
        g.PrintGrid();

        AStarImplementation a;
        a.DijkstrasAlgorithm(&g, ptr->GetStartNode(), ptr->GetTargetNode(), came_from, cost_so_far);

        path = reconstruct_path(g.GetStartNode(), g.GetTargetNode(), came_from);
        for (size_t i = 0;i < path.size();i++) {
            std::cout << path[i]->GetID() << std::endl;
        }
        ptr->PrintsAlgorithmPath(path);
    }


    //AStar Algorithm search on Grid
    if (whatToRun == 3)
    {
        AStarImplementation a;
        Grid AStar;
        Grid* ptr = &AStar;

        std::unordered_map<Node*, Node*> came_from;
        std::unordered_map<Node*, double> cost_so_far;
        std::vector<Node*> path = reconstruct_path(AStar.GetStartNode(), AStar.GetTargetNode(), came_from);

        AStar.CreateGraphGrid();
        AStar.PrintGrid();


        a.AStarAlgorithm(&AStar, ptr->GetStartNode(), ptr->GetTargetNode(), came_from, cost_so_far);
        path = reconstruct_path(AStar.GetStartNode(), AStar.GetTargetNode(), came_from);




        for (size_t i = 0;i < path.size();i++) {
            std::cout << path[i]->GetID() << path[i]->GetDirectionName() << std::endl;
        }
        ;

        ptr->PrintsAlgorithmPath(path);


    }

    if (whatToRun == 4)
    {
        AStarImplementation a;
        Grid Slide;
        Grid* ptr = &Slide;

        std::unordered_map<Node*, Node*> came_from;
        std::unordered_map<Node*, double> cost_so_far;
        std::vector<Node*> path = reconstruct_path(Slide.GetStartNode(), Slide.GetTargetNode(), came_from);

        Slide.CreateGraphGrid();
        Slide.PrintGrid();


        a.SlideAlgorythm(&Slide, ptr->GetStartNode(), ptr->GetTargetNode(), came_from, cost_so_far);
        path = reconstruct_path(Slide.GetStartNode(), Slide.GetTargetNode(), came_from);




        for (size_t i = 0;i < path.size();i++) {
            std::cout << path[i]->GetID() << path[i]->GetDirectionName() << std::endl;
        }


        ptr->PrintsAlgorithmPath(path);


    }




}










