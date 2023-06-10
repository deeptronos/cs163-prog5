#include <iostream>
#include <string>
#include <algorithm>

//#include "my_graph.h" // TODO should this be done instead of #include-ing this .cc file at bottom of my_graph.h?

// ---------------------
// vertex Implementation
// ---------------------

void vertex::display() {
	std::cout << "VERTEX: " << std::endl
	<< "  data: \"" << data <<"\""<< std::endl
	<< "  edge list:" << std::endl;
	for(edge_node e: edge_list){
		e.display();
	}
}

bool vertex::addEdge(const vertex& to_connect) throw(AlreadyConnectedException){
	edge_node e(this, to_connect);

	if(std::find(edge_list.begin(), edge_list.end(), ) != edge_list.end()){

	}
}

bool vertex::operator==(const vertex& rhs) const{
	return(data == rhs.data);
}

// ------------------------
// edge_node Implementation
// ------------------------

void edge_node::display() {
	std::cout << "    EDGE: (\"" << edge.first.data << "\", \"" << edge.second.data << "\")" << std::endl;
}

bool edge_node::operator==(const edge_node& rhs) const{
	return(edge == rhs.edge);
}



// -----------------------
// my_graph Implementation
// -----------------------

// ---------------------------
// Constructors and Destructor
// ---------------------------

//my_graph::my_graph() {} // TODO

my_graph::my_graph(int size_) {} // TODO

my_graph::my_graph(std::vector<vertex_data_t> data_vec_){} // TODO

//my_graph::~my_graph() {} // TODO



void my_graph::display() const {
	std::cout << "Displaying graph in order of adjacency_list entries:" << std::endl;
	for(auto v : adjacency_list){
		v.display();
	}
}

bool my_graph::addVertex(vertex_data_t d_){ // Adds vertex at end of adjacency_list // TODO what if a vertex with the same vertex_data_t exists?
	vertex v(d_);
	adjacency_list.push_back(v);
}

bool my_graph::removeVertex(vertex_data_t d_){
	const vertex& v = getVertexByData(d_);

	// Remove edges from vertex:
	for(auto e: v.edge_list){
		removeEdge(e.edge.first.data, e.edge.second.data);
	}

	adjacency_list.erase(remove(adjacency_list.begin(), adjacency_list.end(), v), adjacency_list.end()); // TODO what if vertices of value d_ have vertices of other values between them in the adjacency_list vector?
}

bool my_graph::addEdge(vertex_data_t& start_, vertex_data_t& end_) {
	vertex v_start = getVertexByData(start_);
	vertex v_end = getVertexByData(end_);

	v_start.
}