#include "my_graph.h"


// Provides an interface for testing the graph ADT.

#ifndef CS163_PROG5_TESTING_INTERFACE_GRAPH_H
#define CS163_PROG5_TESTING_INTERFACE_GRAPH_H


class testing_interface_graph {
public:
	testing_interface_graph();
	~testing_interface_graph();

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
