// Represents the full graph ADT
	// Un-weighted, directed graph.
		// Graph direction is represented by order of edge in edge_node.edge

#ifndef CS163_PROG5_MY_GRAPH_H
#define CS163_PROG5_MY_GRAPH_H

#include <vector>
#include <string>
#include <utility>
#include <memory>

#include <queue> // TODO OK? // For my_graph::recursive_BreadthFirstTraverse

#include "my_exceptions.h"

// TODO:
	// TODO should vertex keep track of "incoming"-directed edges with a vector<edge_node&>?
		// Can we just use smartpointers to get around tracking references from multiple objects?
	// TODO Finish implementing my_graph!
	// TODO Determine whether struct datas should be * or not
	// TODO Determine whether to make my_graph::add_vertex/remove_vertex have arguments be & or not
	// TODO Can I use std::pair from <utility>?
	//      If not, just use a vector and enforce its size = 2:P

using vertex_data_t = std::string;

struct vertex{ // TODO since my_graph's adjacency_list is a std::vector<vertex>, will resizing that & invoking the vertex copy constructor cause issues here?
	std::vector<struct edge_node > edge_list; // TODO should this be a *?

	vertex_data_t data; // TODO Should this be a * or not?

	bool discovered; // Traversal helper flag

	vertex() : data("nothing"), edge_list(), discovered(false) {};
	explicit vertex(vertex_data_t& d_):data(d_), edge_list(), discovered(false) {} // TODO should we enforce "must initialize vertex with a vertex_data_t? Does this do that? // TODO is explicit useful here?

	void display() const;


	bool connectTo(vertex& target) throw (ConnectionException); // TODO make throw exception

	/** Remove a directed edge from this vertex to target.
	 *  @pre vertex target exists. This vertex is connected to vertex target.
	 *  @return True if disconnection successful. Throws exception if disconnection failed.*/
	bool disconnectFrom( vertex & target) throw (ConnectionException);

	bool operator==(const vertex& rhs) const;
	friend ostream& operator<<(ostream& os, const vertex& v_);
};

struct edge_node{
	// Directional: first is source of edge, second is target of edge.
	std::pair<vertex&, vertex&>  edge; // TODO should this be a *?

	explicit edge_node(std::pair<vertex&, vertex&> e_): edge(e_){}

	edge_node( vertex& a, vertex& b): edge(std::make_pair<vertex&, vertex&>(a, b)){} // TODO double check!

	void display() const;

	bool operator==(const edge_node& rhs) const;
};

class my_graph {

public:
	// ---------------------------
	// Constructors and Destructor
	// ---------------------------
	my_graph() : adjacency_list(){};
	my_graph(int size_):adjacency_list( size_){}; // Create a graph of size size_, where each vertex has data "null" and an empty edge_list
	my_graph(std::vector<vertex_data_t> data_vec_); // Turn a vector of vertex_data_t into a graph of vertexes containing that data with empty edge lists
	~my_graph() = default;

	void display() const;

	// -------------------------
	// Add/Remove Parts of Graph
	// -------------------------
		// TODO can add/remove vertex/edge methods be made const?
	bool addVertex(vertex_data_t d_) ;
	bool removeVertex(vertex_data_t d_);

	// Insert a connection between two vertices
	bool addEdge(vertex_data_t& start_, vertex_data_t& end_) throw(NotFoundException);
	bool removeEdge(vertex_data_t& start_, vertex_data_t& end_)throw(NotFoundException);


	void breadthFirstTraverse(vertex_data_t start, void visit(vertex*)); // TODO // Start a  BFT at the vertex with data == start
	void depthFirstTraverse(vertex_data_t start, void visit(vertex*)); // Start a  DFT at the vertex with data == start

private:
	// ----
	// Data
	// ----
	std::vector<vertex> adjacency_list; // an adj list of vertexes with their own edge list



	vertex& getVertexByData(vertex_data_t& v) throw(NotFoundException);
	void setAllVerticesUndiscovered();

	// ----------------------------------
	// Recursive Traversal Helper Methods
	// ----------------------------------
	void recursive_BreadthFirstTraverse(void (*visit)(vertex *), queue<vertex*>& queue_);
	void recursive_DepthFirstTraverse(vertex & v_, void visit(vertex*));

};

#include "my_graph.cc"

#endif //CS163_PROG5_MY_GRAPH_H
