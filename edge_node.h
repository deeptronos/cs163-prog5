

#ifndef CS163_PROG5_EDGE_NODE_H
#define CS163_PROG5_EDGE_NODE_H
#include <tuple>
#include "vertex.h"

class edge_node {
private:
	std::tuple<vertex> edge; // un-ordered tuple representing an edge between two nodes
public:
	edge();
	edge(vertex a, vertex b);
	~edge();

	void display();

};


#endif //CS163_PROG5_EDGE_NODE_H
