
#ifndef CS163_PROG5_VERTEX_H
#define CS163_PROG5_VERTEX_H
#include "edge_node.h"
#include <vector>
#include <string>

using namespace std;

class vertex {
private:
	vector<edge_node> edge_list; // Represents an list for this vertex

	string data;

public:
	vertex();
	vertex (string d);
	~vertex();

	bool connect(vertex target);

	void display()

};


#endif //CS163_PROG5_VERTEX_H
