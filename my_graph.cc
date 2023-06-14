#include <iostream>
#include <string>
#include <algorithm> // TODO allowed?

//#include "my_graph.h" // TODO should this be done instead of #include-ing this .cc file at bottom of my_graph.h?

// ---------------------
// vertex Implementation
// ---------------------

void vertex::display() const{
	std::cout << "VERTEX: " << std::endl
	<< "  data: \"" << data <<"\""<< std::endl
	<< "  edge list:" << std::endl;
	for(edge_node e: edge_list){
		e.display();
	}
}

bool vertex::connectTo(vertex& target) throw (ConnectionException){
	std::pair<vertex& ,vertex&> e_p = std::make_pair<vertex&, vertex&> (*this, target);
	edge_node e(e_p);

	if(find(edge_list.begin(), edge_list.end(),e ) != edge_list.end()){ // If e exists in edge_list...
		throw ConnectionException("vertex::connectTo() attempted to make an edge that already exists.");
	}

	edge_list.push_back(e);
	return true;
}

bool vertex::disconnectFrom(vertex &target) throw(ConnectionException) {
	for(auto e:edge_list){
		if(e.edge.second == target){
			edge_list.erase(remove(edge_list.begin(), edge_list.end(), e), edge_list.end()); // TODO
			return true;
		}
	}
	throw ConnectionException("vertex::disconnectFrom() attempted to remove an edge that didn't exist.");
}

bool vertex::operator==(const vertex& rhs) const{
	return(data == rhs.data);
}

ostream& operator<<(ostream& os, const vertex& v_){
	v_.display();
}

// ------------------------
// edge_node Implementation
// ------------------------

void edge_node::display() const{
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

	adjacency_list.erase(remove(adjacency_list.begin(), adjacency_list.end(), v), adjacency_list.end()); //TODO does this not remove everything from v to end()? // TODO what if vertices of value d_ have vertices of other values between them in the adjacency_list vector?
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

	try{
		v_start->connectTo(*v_end); // TODO ok?
	} catch(ConnectionException e){ //Already connected
		cout << e.what() << endl;
		return false;
	}
	return true;
}
bool my_graph::removeEdge(vertex_data_t & start_, vertex_data_t  & end_)throw(NotFoundException){
	vertex * v_start, * v_end;
	try {
		v_start = &getVertexByData(start_);
		v_end = &getVertexByData(end_);
	}catch(NotFoundException e){ // One or more getVertexByData calls failed
		cout << e.what() << endl; // should we cout from this method?
		return false;
	}
	try{
		v_start->disconnectFrom(*v_end);
	}catch(ConnectionException e){ // Connection did not exist
		cout << e.what()<< endl;
		return false; // TODO will an exception cause the code to stop executing?
	}
	return true;
}

// ------------------------
// Public Traversal Methods
// ------------------------
void my_graph::depthFirstTraverse(vertex_data_t start, void (*visit)(vertex &)) {
	if(adjacency_list.empty()) return;
	vertex start_v = getVertexByData(start);
	setAllVerticesUndiscovered();
	recursive_DepthFirstTraverse(start_v, visit);
}

void my_graph::breadthFirstTraverse(vertex_data_t start, void (*visit)(vertex &)) {
	if(adjacency_list.empty()) return;
	setAllVerticesUndiscovered();

	vertex start_v = getVertexByData(start);

	queue<vertex*> q;

	q.push(&start_v);
	start_v.discovered = true;

//	recursive_BreadthFirstTraverse(start_v, visit, q);
	recursive_BreadthFirstTraverse(visit, q);
}

// ---------------
// Private Methods
// ---------------

vertex& my_graph::getVertexByData(vertex_data_t &v) throw(NotFoundException) {
	// move thru adjacency_list from beginning until a vertex with data == v
	// if reach end of adjacency_list, throw NotFoundException(v + "not found in graph!");
	// otherwise, return matching vertex&
	for(auto entry: adjacency_list){
		if(entry.data == v) return entry;
	}
	throw NotFoundException("my_graph::getVertexByData failed to find a vertex with data v.");
}

void my_graph::setAllVerticesUndiscovered() {
	// from beginning to end of adjacency_list:
		// set each vertex's discovered flag to false
	for(vertex v: adjacency_list){
		v.discovered = false;
	}
}

// ----------------------------------
// Recursive Traversal Helper Methods
// ----------------------------------
//void my_graph::recursive_BreadthFirstTraverse(vertex & v_, void (*visit)(vertex_data_t &), queue<vertex>& queue_) { // TODO I think this stub may not result in a BFT...
void my_graph::recursive_BreadthFirstTraverse(void (*visit)(vertex &), queue<vertex*>& queue_) {
	// pop from queue
	// If popped vertex.traversal_discovered_helper is true, return
	// call visit on popped vertex
	// mark popped vertex's flag as visited
	// add vertices from popped vertex's edges to queue
	// recurse on vertices from popped vertex's edges

	if(queue_.empty()) return;
	// Pop from queue
	vertex* popped = queue_.front();
	queue_.pop(); // TODO will we still have pos after this?

	visit(*popped); // TODO should visit take vertex, not vertex_data?
	for(edge_node& ve: popped->edge_list){
		if(!ve.edge.second.discovered){ // TODO i'm a bit shaky on this. make sure that this is a reference to a vertex, not a copy of any type.
			ve.edge.second.discovered = true;
			queue_.push(&(ve.edge.second));
		}
	}
	recursive_BreadthFirstTraverse(visit, queue_);

}

void my_graph::recursive_DepthFirstTraverse(vertex &v_, void (*visit)(vertex &)) {
	// mark v_'s flag as visited
	// for each vertex in edge_list:
		// if vertex's discovered flag is true, do nothing
		// else recurse on vertex
	v_.discovered = true;
	visit(v_); // TODO should visit take vertex, not vertex_data?
	for(auto ve:v_.edge_list){
		if(!ve.edge.second.discovered){
			ve.edge.second.discovered = true;
			recursive_DepthFirstTraverse(ve.edge.second, visit);
		}
	}
}