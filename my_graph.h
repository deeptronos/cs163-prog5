// Represents the full graph ADT
	// Un-weighted, directed graph.
		// Graph direction is represented by order of edge in edge_node.edge

#ifndef CS163_PROG5_MY_GRAPH_H
#define CS163_PROG5_MY_GRAPH_H

#include <vector>
#include <string>
#include <utility>

// TODO:
	// TODO Finish implementing my_graph!   
	// TODO Determine whether struct datas should be * or not
	// TODO Determine whether to make my_graph::add_vertex/remove_vertex have arguments be & or not
	// TODO Can I use std::pair from <utility>?
	//      If not, just use a vector and enforce its size = 2:P

using vertex_data_t = std::string;

struct vertex{ // TODO since my_graph's adjacency_list is a std::vector<vertex>, will resizing that & invoking the vertex copy constructor cause issues here?
	std::vector<struct edge_node> edge_list; // TODO should this be a *?
	vertex_data_t data; // TODO Should this be a * or not?

	explicit vertex(vertex_data_t& d_):data(d_){} // TODO should we enforce "must initialize vertex with a vertex_data_t? Does this do that? // TODO is explicit useful here?

	void display();
};

struct edge_node{
	std::pair<vertex, vertex>  edge; // TODO should this be a *? // Directional: first vertex is source of edge, second vertex is target of edge.

	explicit edge_node(std::pair<vertex, vertex> e_): edge(e_){}
	edge_node(vertex a, vertex b): edge(std::make_pair(a, b)){} // TODO double check!

	void display();
};

class my_graph {

public:
	// ---------------------------
	// Constructors and Destructor
	// ---------------------------
	my_graph();
	my_graph(int size_); // Create a graph of size size_, where each vertex has data "null" and an empty edge_list
	my_graph(std::vector<vertex_data_t> data_vec_); // Turn a vector of vertex_data_t into a graph of vertexes containing that data with empty edge lists
	~my_graph();

	void display() const;

//	int getNumVertices() const; // TODO necessary?
	virtual int getNumVertices() const = 0; // TODO necessary?
	virtual int getNumEdges() const = 0; // TODO necessary?

	// -------------------------
	// Add/Remove Parts of Graph
	// -------------------------
		// TODO can add/remove vertex/edge methods be made const?
	bool addVertex(vertex_data_t d_) ;
	bool removeVertex(vertex_data_t d_);

	bool addEdge(vertex_data_t * start_, vertex_data_t * end_) ;
	bool removeEdge(vertex_data_t * start_, vertex_data_t * end_) ;

	// ------------------------
	// Public Traversal Methods
	// ------------------------
	void depthFirstTraverse(vertex_data_t start, void visit(vertex_data_t&)); // Start a  DFT at the vertex with data == start

	void breadthFirstTraverse(vertex_data_t start, void visit(vertex_data_t&)); // Start a  BFT at the vertex with data == start

private:
	// ----
	// Data
	// ----
	std::vector<vertex> adjacency_list; // an adj list of vertexes with their own edge list

	// ----------------------------------
	// Recursive Traversal Helper Methods
	// ----------------------------------
	void recursive_BreadthFirstTraverse(vertex & v_, void visit(vertex_data_t&));
	void recursive_DepthFirstTraverse(vertex & v_, void visit(vertex_data_t&));

};


#endif //CS163_PROG5_MY_GRAPH_H
