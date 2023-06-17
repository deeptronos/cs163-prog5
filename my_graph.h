// Represents the full graph ADT
	// Un-weighted, directed graph.
		// Graph direction is represented by order of edge in edge_node.edge

#ifndef CS163_PROG5_MY_GRAPH_H
#define CS163_PROG5_MY_GRAPH_H

#include <vector>
#include <string>
#include <utility>
#include <memory>

#include "my_exceptions.h"

// TODO:
	// TODO Can I use std::pair from <utility>?
	//      If not, just use a vector and enforce its size = 2:P

using vertex_data_t = std::string;
using namespace std;

struct vertex{ // TODO since my_graph's adjacency_list is a std::vector<vertex>, will resizing that & invoking the vertex copy constructor cause issues here?
	vertex_data_t * data; // TODO Should this be a * or not?

	struct node * head;

	bool discovered; // Traversal helper flag

	friend ostream&  operator<<(ostream& os, const vertex& v);

};

struct node{
	int to; //

	node * next;

	friend ostream&  operator<<(ostream& os, const vertex& v);
};

class my_graph {

public:
	// ---------------------------
	// Constructors and Destructor
	// ---------------------------
	my_graph();
	~my_graph();




	// --------------
	// Public Methods
	// --------------

	void display() const;

	bool insertVertex(vertex_data_t d_) throw(PreconditionViolatedException);
	bool insertConnection(vertex_data_t source_, vertex_data_t target_) throw(ConnectionException);

	void depthFirstTraverse(vertex_data_t start, void visit(vertex*)); // Start a  DFT at the vertex with data == start

private:
	// ----
	// Data
	// ----
	std::vector<vertex> * adjacency_list; // an adj list of vertexes with their own edge list

	// ---------------
	// Private Methods
	// ---------------
	void setAllVerticesUndiscovered();


	// Retrieve the vertex with data of target_. Returns its index in adjacency_list.
	int getVertexIndexFromData(vertex_data_t& target_) throw(NotFoundException);

	// ----------------------------------
	// Recursive Traversal Methods
	// ----------------------------------
	void recursive_DepthFirstTraverse(vertex & v_, void visit(vertex*));

};

#include "my_graph.cc"

#endif //CS163_PROG5_MY_GRAPH_H
