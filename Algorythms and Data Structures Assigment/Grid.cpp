#include "Node.h"
#include "Grid.h"


#include <filesystem>

#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iostream>

#include <stdlib.h>
#include <algorithm>
#include <cstdio>


#include<vector>
#include<string>
#include<unordered_set>
    Grid::Grid()
{   
    
    start = nullptr;
    target = nullptr;
    currentNode = nullptr;
    mazefile = " ";
    buffer = ' ';
   
}
    

    void Grid::ReadFile()
    {
        //this stream will be used to store directory of choosen file
        std::string path = "C:/Users/Fabian/Desktop/Algorythms and Data Structures Assigment/Algorythms and Data Structures Assigment/MazeInput";

        int mazeSize = 0;

        char i = ' ';
        std::string ReadMaprDoc = "";
        std::ifstream MapIfstream;
        std::string  myLine;
        std::string input;
        int maxNrOFFiles =  mazeSize;
        int docID = 0;
        bool pickedDoc = false;

        std::vector<std::string> MapLevelsvector;

        //print all text files in the path
        for (const auto& file : std::filesystem::directory_iterator::directory_iterator(path))
        {
            if (file.path().extension() == ".txt")
            {
                docID++;
                std::cout << "Document ID " << "[" << docID << "]" << file.path().filename().stem() << std::endl;
            }
        }

        //selecting maze doc
        if (!MapIfstream.is_open())
        {
            std::cout << "Please enter doc id " << std::endl;
            std::cin >> input;
            int i = std::stoi(input);
            std::cin.ignore();
            if (i < docID)
            {
                docID = 0;
                pickedDoc = false;
                MapIfstream.close();

                for (const auto& file : std::filesystem::directory_iterator::directory_iterator(path))
                {
                    docID++;

                    if (docID == i)
                    {
                        ReadMaprDoc = (file.path().u8string());
                        MapIfstream.open(ReadMaprDoc, std::ifstream::in);
                        std::cout << "You have choosen  []" << file.path().filename() << std::endl;
                        pickedDoc = true;
                        while (std::getline(MapIfstream, input))
                        {
                            SetUpNodeState(input);
                            AddNeighbours(mazeSize);
                            PrintGrid();
                            CreateGraphGrid();

                        }
                        
                    }

                }

            }

        }
      



        //if u want throu doc seletcion or if file is open enter
        if (pickedDoc || MapIfstream.is_open())
        {

            if (MapIfstream.is_open())
            {

          


                while (std::getline(MapIfstream, myLine))
                {




                }


                //when stream finishes reding show size of maze+swap map vector
                if (MapIfstream.eof())
                {
                    //map size
                    std::cout << myLine.size() << std::endl;
                    std::cout << MapLevelsvector.size() << std::endl;
                    std::reverse(MapLevelsvector.begin(), MapLevelsvector.end());
                    //calculation maze size
                }


            }
            for (std::string is : MapLevelsvector)
            {

                if (is == "\n")
                    std::cin.ignore(1);


                std::cout << myLine.size() << std::endl;
                std::cout << MapLevelsvector.size() << std::endl;
                std::reverse(MapLevelsvector.begin(), MapLevelsvector.end());
                //calculation maze size


                int i = 0;

                std::cout << MapLevelsvector[i] << std::endl;
                i++;
            }





                                                    









        }
    }   

    //creates data structure in heap
    void Grid::CreateGraphGrid()
    {


        //nested for loop for creating nodes in memory
        //inisializing key node variables like object state 
        //inisializing key grid variables for traversal start,finish and current
        SetUpNodeState(myLine);
        AddNeighbours(mazeSize);
        //nested for loop for creating neighbours
        //if node is not out of map bounds
        //connecting nodes with neigbours to create a grid


    }
    //prints Grid to screen 
    void Grid::PrintGrid()
    {
        //nested for loop for using PrintMapSymbols()
        for (int Y = 0;Y < mazeSize;Y++) {      //Standard nested for loop for printing map state
            for (int X = 0;X < mazeSize;X++) {

                PrintMapSymbols(Y, X);//Prints righ symbol base on state of 3 bools inisde every object
            }
            std::cout << std::endl;//Starts a new row when size variable is equal to int i
        }


    }
    //Prints symbol  based on node state bool
    //this code checks all the objects inside array 2d for one of 5 bools 
    //if condition is satisfied prints the right char symbol to the screen
    //also assignes gives new name to then node base on bool state
   
    void Grid::PrintMapSymbols(int i, int j)
    {


        if (this->maze[i][j]->isWall) {
            std::cout << char(254) << " ";
            this->maze[i][j]->SetObjectName("Wall");
        }

        else if (this->maze[i][j]->isStart) {
            std::cout << "S" << " ";
            this->maze[i][j]->SetObjectName("Start");
        }
        else if (this->maze[i][j]->isFinish) {
            std::cout << "F" << " ";
            this->maze[i][j]->SetObjectName("Finish");
        }
        else if (this->maze[i][j]->bvisited) {
            std::cout << "X" << " ";
            this->maze[i][j]->SetObjectName("Visited");
        }

        else {
            std::cout << "." << " ";
            this->maze[i][j]->SetObjectName("Ice Floor");
        }



    }

    void Grid::PrintsAlgorithmPath(std::vector<Node*> path)
    {
        //create temporary variable that scors function parameter
        //right now this variable is useless not used keep it for leaters
        std::vector<Node*> currentpath = path;

        //Prints symbol  based on node state bool
        //this code checks all the objects inside array 2d for one of 5 bools 
        //if condition is satisfied prints the right char symbol to the screen
        //also assignes gives new name to then node base on bool state

        for (int Y = 0;Y < this->size;Y++) {
            for (int X = 0;X < this->size;X++) {

                if (this->maze[Y][X]->isWall) {
                    std::cout << char(254) << " ";
                    this->maze[Y][X]->SetObjectName("Wall");
                }
                else if (this->maze[Y][X]->isStart) {
                    std::cout << "S" << " ";
                    this->maze[Y][X]->SetObjectName("Start");
                }
                else if (this->maze[Y][X]->isFinish) {
                    std::cout << "F" << " ";
                    this->maze[Y][X]->SetObjectName("Finish");
                }
                else if (this->maze[Y][X]->isAPath) {
                    std::cout << "X" << " ";
                    this->maze[Y][X]->SetObjectName("IsAPath");
                }
                else {
                    std::cout << "." << " ";
                    this->maze[Y][X]->SetObjectName("Ice Floor");
                }
            }
            //Starts a new row when size variable is equal to int i
            std::cout << std::endl;
        }
    }


    void Grid::AddNeighbours(int size)
    {
        for (int i = 0;i <size;i++) {
            for (int j = 0;j < size;j++) {

                //push maze in to all nodes vector (might become usefull?)
                //if node position is no out of map bounds connect neighbours
                allNodes.push_back(maze[i][j]);
                if ((i - 1) >= 0) {


                   maze[i][j]->connectedNodes.push_back(maze[i - 1][j]);

                }
                if ((i + 1) <= size - 1) {

                    maze[i][j]->connectedNodes.push_back(maze[i + 1][j]);
                }
                if ((j - 1) >= 0) {

                   maze[i][j]->connectedNodes.push_back(maze[i][j - 1]);
                }
                if ((j + 1) <= size - 1) {

                   maze[i][j]->connectedNodes.push_back(maze[i][j + 1]);
                }


            }
        }
    }

    void Grid::SetUpNodeState(std::string newMaze)
    {






        //use this for the time being but u will have to improve this leater
        this->mazefile = 
       /**/ ".0...00..."
            ".0.0...F.."
            "..0..0...."
            ".0.0.....0"
            ".S.......0"
            ".........."
            "....0.0.0."
            ".0.0......"
            "0........0"
            "...0.....0"; 

        std::stringstream ss(this->mazefile, std::ios::in);


        for (int i = 0;i < this->size;i++) {
            for (int j = 0;j < this->size;j++) {

                //every time loop runs creqte new node in heap
                //assign values to X and Y Cordinates
                //set Node ID (used for printing visited nodes)
                Node* n = new Node();

                n->SetID((size - j) - 1, i);



                //sends information from (stringstream) ss to (char) buffer 
                // based on buffer current data set correct object state bool to true
                //new node symbol shoud affect any of 4 the bool variables
                //after seting up key variables assign new node to 2D array 
                ss >> buffer;


                if (i == 0 || i == size - 1)
                {
                    n->isWall = true;
                }

                if (j == 0 || j == size - 1)
                {
                    n->isWall = true;
                }


                if (this->buffer == '0') {
                    n->isWall = true;

                }
                else if (this->buffer == 'S') {
                    n->isStart = true;
                    this->start = n;
                    this->currentNode = this->start;

                }
                else if (this->buffer == 'F') {
                    n->isFinish = true;
                    this->target = n;
                }
                else if (this->buffer == '.')
                {
                    n->IceFloor = true;
                }

                this->maze[j][i] = n;
            }


        }
    }



   


    

   

   
    
    













