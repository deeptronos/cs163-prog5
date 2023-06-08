#include <iostream>
#include <string>
#include <algorithm>

#include "my_graph.h"

void vertex::display() {
	std::cout << "VERTEX: " << std::endl
	<< "  data: \"" << data <<"\""<< std::endl
	<< "  edge list:" << std::endl;
	for(edge_node e: edge_list){
		e.display();
	}
}

void edge_node::display() {
	std::cout << "    EDGE: (\"" << edge.first.data << "\", \"" << edge.second.data << "\")" << std::endl;
}





// -----------------------
// my_graph Implementation
// -----------------------

// ---------------------------
// Constructors and Destructor
// ---------------------------

my_graph::my_graph() {} // TODO

my_graph::my_graph(int size_) {} // TODO

my_graph::my_graph(std::vector<vertex_data_t> data_vec_){} // TODO

my_graph::~my_graph() {} // TODO



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