#include "my_graph.h"

#include <iostream>


int main(){
	my_graph g;
	g.display();
	g.insert_vertex("Hello");
	g.insert_vertex("goodbyte");
	g.insert_connection("Hello", "goodbyte");
	g.display();
	return 0;
}