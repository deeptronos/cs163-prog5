#include "my_graph.h"


// Interface file (.h) for an interface class to test my_graph class.
	// Sole private data member is a reference to my_graph.
	// Contains public

// Provides an interface for testing the graph ADT.

#ifndef CS163_PROG5_TESTING_INTERFACE_GRAPH_H
#define CS163_PROG5_TESTING_INTERFACE_GRAPH_H


class testing_interface_graph {
public:
	testing_interface_graph();
	~testing_interface_graph();

	// Prompts user for for input to call my_graph methods.
	// Returns true on any valid input, fale whe
	bool prompt_user();


private:
	// ------------------------------------------
	// Private callers of my_graph public methods
	// ------------------------------------------
	bool graph_create();
	bool graph_display();
	bool graph_insertVertex(vertex_data_t name_);
	bool graph_insertConnection(vertex_data_t source_, vertex_data_t target);

	void graph_depthFirstTraverse(vertex_data_t source, void visit(vertex*));

	my_graph * graph_;

};
#include "testing_interface_graph.cc" // TODO good practice? doesn't compile otherwise...

#endif //CS163_PROG5_TESTING_INTERFACE_GRAPH_H
