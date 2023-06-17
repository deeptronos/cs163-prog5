
// ----------------------
// vertex Implementation:
// ----------------------

ostream &operator<<(ostream &os, const vertex &v) { // Used for my_visit example visit method
	os << "  VERTEX: \"" << *(v.data) <<"\""<< endl;
	return os;
}


// ------–----------------
// my_graph Implementation
// ------–----------------

// ------------------------
// Constructor & Destructor
// ------------------------

#include "my_graph.h"



my_graph::my_graph() {
	adjacency_list = new vector<vertex>;
}



my_graph::~my_graph(){ // TODO will this destroy strings pointed to by vertex's data?
	if(adjacency_list){ // TODO complete?
		for(auto v : *adjacency_list){
			delete v.data;
			node * node_ptr = v.head;

			if(node_ptr){
				node * next = node_ptr;

				while(v.head){
					node_ptr = v.head -> next;
					delete v.head;
					v.head = node_ptr;
				}
			}
		}
	}
}




// --------------
// Public Methods
// --------------

// Iterates through adjacency_list vector, displaying each vertex.
// At each vertex, iterates thru the edge node LLL and displays directed edges.
void my_graph::display() const {
	cout << "Graph:" << endl;
	if(!(adjacency_list->empty())) {
		for (auto v: *adjacency_list) { // Display vertices in order of appearance in adjacency_list
			cout << v;

			node *node_ptr = v.head;
			if (node_ptr) {
				cout << "  directed edges: " << endl;
				while (node_ptr != nullptr) {
					vertex * temp = &adjacency_list->at(node_ptr->to); // TODO double check this funky pointer business
					cout << "    towards \"" << *temp->data << "\"" << endl;
					node_ptr = node_ptr->next;
				}
			}
			cout << endl; // Whitespace between vertices
		}
	}else{
		cout << "No vertices. Graph is empty." << endl;
	}
}



// Iterates through adjacency_list to check that a vertex with data == d_
// doesn't already exist. If such a vertex is found, throws a PreconditionViolatedException.
// If no such vertex is found, add a new vertex with data d_ to the adjacency_list vector.
bool my_graph::insertVertex(vertex_data_t d_)throw(PreconditionViolatedException){
	for(auto v : *adjacency_list){
		if(*(v).data == d_){ // TODO double check pointer syntax...
			throw PreconditionViolatedException("my_graph::insertVertex - a vertex with that data already exists.");
		}
	}
	string * new_data = new string(d_);
	vertex new_v = {new_data, NULL}; // TODO this may be trouble... is new_v.data getting initialized correctly?
	adjacency_list->push_back(new_v);

	return true;
}



bool my_graph::insertConnection(vertex_data_t source_, vertex_data_t target_) throw(ConnectionException){
	if(adjacency_list->empty()) return false;

	int source_index = -1;
	int target_index = -1;
	try {
		source_index = getVertexIndexFromData(source_);
		target_index = getVertexIndexFromData(target_);
	}catch(NotFoundException e){
		cout << e.what() << endl;
		return false;
	}

	if(source_index < 0 || target_index < 0) throw ConnectionException("my_graph::insertConnection was passed one or more vertices which don't exist in the graph - source_: " + source_ + +", target_: " + target_); // todo Necessary? only way getVertexFromData returns <0 is if adjacency_list->empty() is true...
	else{
		// Check if connection already exists
		node * node_ptr = adjacency_list->at(source_index).head;
		while(node_ptr){
			if(node_ptr->to == target_index){
				throw ConnectionException("my_graph::insertConnection attempted to create a directed edge that already exists - source_: " + source_ + ", target_: " + target_);
			}
			node_ptr = node_ptr -> next;
		}
		// Connection doesn't exist, so...
		node * new_n = new node;
		new_n->to = target_index;
		new_n->next = adjacency_list->at(source_index).head;
		adjacency_list->at(source_index).head = new_n;
		return true;
	}
}



//vertex_data_t my_graph::getVertexDataByIndex(int index){
//	return(*(&adjacency_list->at(index))->data);
//}

void my_graph::depthFirstTraverse(vertex_data_t start, void visit(vertex*)) { // Start a  DFT at the vertex with data == start
	if(adjacency_list->empty()) return;

	setAllVerticesUndiscovered();

	int v_start = -1;
	try {
		v_start = getVertexIndexFromData(start);
	}catch(NotFoundException e){
		cout << e.what() << endl;
		return;
	}
	adjacency_list->at(v_start).discovered = true;
	recursive_DepthFirstTraverse(*(&adjacency_list->at(v_start)), visit); // TODO double check ptr syntax
}



// ---------------
// Private Methods
// ---------------
void my_graph::setAllVerticesUndiscovered(){
	if(adjacency_list->empty())return;

	for(int i = 0; i < adjacency_list->size(); ++i){
		adjacency_list->at(i).discovered = false;
	}

}



int my_graph::getVertexIndexFromData(vertex_data_t &target_) throw(NotFoundException) {
	if(adjacency_list->empty()) return -1;

	for(int i = 0; i < adjacency_list->size(); ++i){
		if(*(adjacency_list->at(i).data) == target_) return i;
	}

	throw NotFoundException("my_graph::getVertexIndexFromData failed to find a vertex in the graph containing the target data - target_: " + target_);
}



// --------------------------
// Recursive Traversal Method
// --------------------------

void my_graph::recursive_DepthFirstTraverse(vertex &v_, void (*visit)(vertex *)) { // TODO is ptr syntax good here?
	v_.discovered = true;
	visit(&v_);

	node * node_ptr = v_.head;
	while(node_ptr){
		if(!( (&adjacency_list -> at(node_ptr -> to)) -> discovered )){
			recursive_DepthFirstTraverse(*(&adjacency_list -> at(node_ptr -> to)), visit); // TODO double check ptr syntax
		}
		node_ptr = node_ptr -> next;
	}

}

