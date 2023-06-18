// Represents the full graph ADT
	// Un-weighted, directed graph.

// Vertex and node struct are based on Lab 8 structs.
	// Except: vertex has overloaded operator<< to use in an example visit() method.

//my_graph class implements an adjacency list-based Graph ADT.
	// Sole private data member is the adjacency list, a pointer to a vector of vertices.
	// Four public methods to display the graph, add a vertex to it, add a directed edge to it, and to begin a recursive depth-first traversal.
	// Three private methods to set all vertices to be undiscovered (for use in traversals), get the adjacency_list index of a vertex containing data target_, and to do a depth-first traversal recursively.

#ifndef CS163_PROG5_MY_GRAPH_H
#define CS163_PROG5_MY_GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>

#include "my_exceptions.h"


using vertex_data_t = std::string;
using namespace std;

struct vertex{
	vertex_data_t * data;

	struct node * head;

	bool discovered; // Traversal helper flag

	friend ostream&  operator<<(ostream& os, const vertex& v);

};

struct node{
	int to; //

	node * next;
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

//#include "my_graph.cc"

#endif //CS163_PROG5_MY_GRAPH_H
