#include "testing_interface_graph.h"

// Implementation file (.cc) for testing_interface_graph class.

// --------------------------------------------------------
// Visits for depthFirstTraverse:
// --------------------------------------------------------

void my_visit(vertex* v){
	cout << *v << endl;
}

// ------------------------
// Constructor & Destructor
// ------------------------

// Points testing_interface_graph to nullptr.
testing_interface_graph::testing_interface_graph() {
	graph_ = nullptr;
}


// Calls ~my_graph().
testing_interface_graph::~testing_interface_graph() {
	delete graph_;
}



// ----------------------------
// Public Method Implementation
// ----------------------------

// Prompts user for desired testing actions, or to quit executing.
bool testing_interface_graph::prompt_user() {
	cout << endl; // Whitespace before prompt
	char input;
	cout << "Choose an action:" << endl;
	cout << "1. Initialize a my_graph\n"
			"2. Insert a vertex\n"
			"3. Add a directed edge from one vertex to another\n"
			"4. Display the graph's contents in adjacency-list order\n"
			"5. Run a depth-first traversal beginning from a vertex\n"
			"(Q to quit)" << endl;
	cout << "Choose 1-5 or (Q)uit: ";
	cin >> input;
	cin.ignore(100, '\n');

	if(input == '1'){
		graph_create();

	}else if(input == '2'){
		string name_;
		cout << "Provide a name for the vertex:" << endl;
		getline(cin, name_);
		bool result = graph_insertVertex(name_);
		if(!result){
			cout <<"Graph has not been initialized." <<endl;
		}

	}else if(input == '3'){
		string source_;
		string target_;

		cout <<"Provide the name of a vertex present in the graph for the source of the directed edge:" << endl;
		getline(cin, source_);
		cout << "Provide the name of a vertex present in the graph for the target of the directed edge:" << endl;
		getline(cin, target_);

		bool result = graph_insertConnection(source_, target_);
		if(!result){
			cout <<"Graph has not been initialized." <<endl;
		}

	}else if(input == '4'){
		bool result = graph_display();
		if(!result){
			cout <<"Graph has not been initialized." <<endl;
		}

	}else if(input == '5'){
		string source_;

		cout <<"Provide the name of a vertex present in the graph to be the source of the depth-first traversal: " <<endl;
		getline(cin, source_);

		bool result = graph_depthFirstTraverse(source_, my_visit);
		if(!result){
			cout <<"Graph has not been initialized." <<endl;
		}

	}else if(input == 'Q'){
		return false;
	}
	else{
		cout << "    Unrecognized input." << endl;
	}

	return true;
}




// ------------------------------------------
// Private callers of my_graph public methods
// ------------------------------------------

// Creates a new my_graph and assings it to graph_ pointer.
bool testing_interface_graph::graph_create() {
	if(graph_ == nullptr) {
		graph_ = new my_graph();
		return true;
	}else return false;
}



// Calls my_graph::display()
bool testing_interface_graph::graph_display() {
	if(graph_){
		graph_->display();
		return true;
	}else return false;

}



// Calls my_graph::insertVertex()
bool testing_interface_graph::graph_insertVertex(vertex_data_t name_) {
	if(graph_) {
		try {
			graph_->insertVertex(name_);
			return true;
		} catch (PreconditionViolatedException e) {
			cout << e.what() << endl;
			return false;
		}
	}else return false;
}



// Calls my_graph::insertConnection()
bool testing_interface_graph::graph_insertConnection(vertex_data_t source_, vertex_data_t target) {
	if(graph_) {
		try {
			graph_->insertConnection(source_, target);
			return true;
		} catch (ConnectionException e) {
			cout << e.what() << endl;
			return false;
		}
	}else return false;
}



// Calls my_graph::depthFirstTraverse()
bool testing_interface_graph::graph_depthFirstTraverse(vertex_data_t source, void visit(vertex *)) {
	if(graph_) {
		graph_->depthFirstTraverse(source, visit);
		return true;
	}else return false;
}