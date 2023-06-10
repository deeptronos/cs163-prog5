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

//bool vertex::addEdge(const vertex& to_connect) throw(AlreadyConnectedException){
//	edge_node e(this, to_connect);
//
//	if(std::find(edge_list.begin(), edge_list.end(), ) != edge_list.end()){
//
//	}
//}

bool vertex::connectTo(vertex& target) throw (NotFoundException){
	std::pair<vertex& ,vertex&> e_p = std::make_pair<vertex&, vertex&> (*this, target);

	edge_node e(e_p);

	edge_list.push_back(e);
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

// --------------
// Public Methods
// --------------

my_graph::my_graph(std::vector<vertex_data_t> data_vec_){
	for(auto d: data_vec_){
		adjacency_list.push_back(vertex(d));
	}
}

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

bool my_graph::addEdge(vertex_data_t& start_, vertex_data_t& end_) throw(NotFoundException) {
	vertex * v_start, * v_end;
	try {
		v_start = &getVertexByData(start_);
		v_end = &getVertexByData(end_);
	}catch(NotFoundException e){ // One or more getVertexByData calls failed
		cout << e.what() << endl; // should we cout from this method?
		return false;
	}

	v_start->connectTo(*v_end); // TODO ok?
}
bool my_graph::removeEdge(vertex_data_t & start_, vertex_data_t  & end_)throw(NotFoundException){
	//Duplicate first 8 lines of addEdge
	// do v_start->disconnectFrom(v_end);
	return false;
}

// ------------------------
// Public Traversal Methods
// ------------------------
void my_graph::depthFirstTraverse(vertex_data_t start, void (*visit)(vertex_data_t &)) {
	if(adjacency_list.empty()) return;
	vertex start_v = getVertexByData(start);
	setAllVerticesUndiscovered();
	recursive_DepthFirstTraverse(start_v, visit);
}

void my_graph::breadthFirstTraverse(vertex_data_t start, void (*visit)(vertex_data_t &)) {
	if(adjacency_list.empty()) return;
	vertex start_v = getVertexByData(start);
	setAllVerticesUndiscovered();
	// Create a queue q, to be passed by reference thru recursive BFT method
	// add start_v to q
	// Call recursive_BreadthFirstSearch(start_v, visit, &q);
}

// ---------------
// Private Methods
// ---------------

vertex& my_graph::getVertexByData(vertex_data_t &v) throw(NotFoundException) {
	// move thru adjacency_list from beginning until a vertex with data == v
	// if reach end of adjacency_list, throw NotFoundException(v + "not found in graph!");
	// otherwise, return matching vertex&
}

void my_graph::setAllVerticesUndiscovered() {
	// from beginning to end of adjacency_list:
		// set each vertex.traversal_discovered_helper to false
}

// ----------------------------------
// Recursive Traversal Helper Methods
// ----------------------------------
void my_graph::recursive_BreadthFirstTraverse(vertex & v_, void (*visit)(vertex_data_t &), queue<vertex>& queue_) { // TODO I think this stub may not result in a BFT...
	// pop from queue
	// If popped vertex.traversal_discovered_helper is true, return

	// call visit on popped vertex
	// mark popped vertex's flag as visited
	// add vertices from popped vertex's edges to queue

	// recurse on vertices from popped vertex's edges
}

void my_graph::recursive_DepthFirstTraverse(vertex &v_, void (*visit)(vertex_data_t &)) {
	// mark v_'s flag as visited
	// for each vertex in edge_list:
		// if vertex's discovered flag is true, do nothing
		// else recurse on vertex
}