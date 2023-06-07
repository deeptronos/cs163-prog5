// Represents the full graph ADT

#ifndef CS163_PROG5_MY_GRAPH_H
#define CS163_PROG5_MY_GRAPH_H

#include <vector>
#include "vertex.h"
#include "GraphInterface.h"
#include "edge_node.h"


class my_graph: GraphInterface  {
private:
	std::vector<vertex> adjacency_list; // an adj list of vertexes with their own edge list

public:
	int getNumVertices() const;
	int getNumEdges() const;

	bool add(LabelType start, LabelType end, int edgeWeight);
	bool remove(LabelType start, LabelType end);

	int getEdgeWeight(LabelType start, LabelType end) const;

	void depthFirstTraversal(LabelType start, void visit(LabelType&));

	void breadthFirstTraversal(LabelType start, void visit(LabelType&));

	void display();
};


#endif //CS163_PROG5_MY_GRAPH_H
