#pragma once
#include<vector>
#include<utility> 
#include<functional>
#include<queue>
#include<unordered_map>
#include"Node.h"
class Grid;
struct Node;

class AStarImplementation
{

public:
	//BFS for traversing all nodes on the map until f is not found
	void breadth_first_search(Grid* graph, Node* start);

	//Dijkstras for traversing the nodes based on travel cost
	void DijkstrasAlgorithm(Grid* wieghtedgraph, Node* start, Node* target,
		std::unordered_map<Node*, Node*>& came_from,
		std::unordered_map<Node*, double>& cost_so_far);
	 
	void AStarAlgorithm(Grid* wieghtedgraph,
		Node* start,
		Node* goal,
		std::unordered_map<Node*, Node*>& came_from,
		std::unordered_map<Node*, double>& cost_so_far);

	 
		
	void SlideAlgorythm(Grid* wieghtedgraph,
		Node* start,
		Node* goal,
		std::unordered_map<Node*, Node*>& came_from,
		std::unordered_map<Node*, double>& cost_so_far);
		
	
	std::vector <Node*> GetEdgesOfCurrentNode(Node* ptr) { return ptr->GetEdges(); }//returns neighbours for currently visited node
	

	//Queue  for dijkstra and a*
	//Remember you will have to change it a bit this is copy and paste
	//try to spend more time to understand it
	template<typename T, typename priority_t>
	struct PriorityQueue
	{
		typedef std::pair<priority_t, T> PQElement;
		std::priority_queue<PQElement, std::vector<PQElement>,
			std::greater<PQElement>> elements;
		
		inline bool empty() const {
			return elements.empty();
		}

		inline void put(T item, priority_t priority) {
			elements.emplace(priority, item);
		}

		T get() {
			T best_item = elements.top().second;
			elements.pop();
			return best_item;
		}
	};

	/*The distance between two points measured along axes at right anglesThe 
	distance between two points measured along axes at right angles*/
	//Used only for A Star Algorythms
	int GetManhatanDistance(Node* current,Node* target) {
		
		int x = (int)(abs(current->Xcoordinate - target->Xcoordinate));
		int y = (int)(abs(current->Ycoordinate - target->Ycoordinate));
		return x + y;
	}




	void RunChoosenAlgorythm();
	void Dijkstras();
	void AStarAlgorythm();
	void SlideAlgorythm();
	void bMenu();


};


