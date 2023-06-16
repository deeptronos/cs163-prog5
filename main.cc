#include "my_graph.h"

#include <iostream>

void my_visit(vertex* v){
	v->display();
};

int main(){
	my_graph g;
	g.addVertex("Hello");
	g.depthFirstTraverse("Hello", my_visit);
	return 0;
}