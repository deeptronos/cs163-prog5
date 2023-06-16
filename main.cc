#include "my_graph.h"

#include <iostream>


void my_visit(vertex* v){
	cout << *v << endl;
}

int main(){
	my_graph g;
	g.display();

	g.insert_vertex("Go camping");

	g.insert_vertex("Pick your campsite");
		g.insert_vertex("Yosemite");
		g.insert_vertex("Arches");
		g.insert_vertex("Mt. Rainier");

		g.insert_connection("Pick your campsite", "Yosemite");
		g.insert_connection("Pick your campsite", "Arches");
		g.insert_connection("Pick your campsite", "Mt. Rainier");

		g.insert_connection("Go camping", "Pick your campsite");

	g.insert_vertex("Figure out how you'll sleep");
		g.insert_vertex("Rent or purchase a luxury trailer");
		g.insert_vertex("In the dirt");
		g.insert_vertex("In a tent");
		g.insert_vertex("In your car");

		g.insert_connection("Figure out how you'll sleep", "Rent or purchase a luxury trailer");
		g.insert_connection("Figure out how you'll sleep", "In the dirt");
		g.insert_connection("Figure out how you'll sleep", "In a tent");
		g.insert_connection("Figure out how you'll sleep", "In your car");

		g.insert_connection("Go camping", "Figure out how you'll sleep");

	g.insert_vertex("Reserve your campsite before arriving");
		g.insert_connection("Yosemite","Reserve your campsite before arriving");
		g.insert_connection("Arches","Reserve your campsite before arriving");
		g.insert_connection("Mt. Rainier", "Reserve your campsite before arriving");

	g.insert_connection("Go camping", "Pick your campsite");


	g.display();
	cout << endl << endl << endl << "Depth first traversal:" << endl;
	g.depthFirstTraverse("Go camping", my_visit);
	return 0;
}