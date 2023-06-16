
// ------------------------
// Constructor & Destructor
// ------------------------

my_graph::my_graph(int size) {
	adjacency_list = new vector<vertex>(size);
	for(auto v : *adjacency_list){
		v.data = nullptr;
		v.head = nullptr;
		v.discovered = false;
	}
}

my_graph::~my_graph(){ // TODO will this destroy strings pointed to by vertex's data?
	if(adjacency_list){ // TODO complete?
		for(auto v : *adjacency_list){
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
		for (auto v: *adjacency_list) {
			cout << "  VERTEX: data: " << v.data << endl;
			node *node_ptr = v.head;
			if (node_ptr) {
				cout << "  directed edges: " << endl;
				while (node_ptr != nullptr) {
					vertex * temp = &adjacency_list->at(node_ptr->to); // TODO double check this funky pointer business
					cout << "    towards " << temp->data << endl;
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
bool my_graph::insert_vertex(vertex_data_t & d_)throw(PreconditionViolatedException){
	for(auto v : *adjacency_list){
		if(*v.data == d_){ // TODO double check pointer syntax...
			throw PreconditionViolatedException("my_graph::insert_vertex - a vertex with that data already exists.");
		}
	}
	string new_data(d_);
	vertex new_v = {&new_data, nullptr}; // TODO this may be trouble... is new_v.data getting initialized correctly?
	adjacency_list->push_back(new_v);

	return true;
}

bool my_graph::insert_connection(vertex_data_t& source_, vertex_data_t& target_){
	int source_index = getVertexIndexFromData(source_);
	int target_index = getVertexIndexFromData(target_);
	if(source_index < 0 || target_index < 0) return false;
	else{
		node * new_n = new node;
		new_n->to = target_index;
	}
}