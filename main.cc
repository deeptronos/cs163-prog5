//#include "my_graph.h"
#include "testing_interface_graph.h"

#include <iostream>




int main(){
	testing_interface_graph tig;
	bool run = true;
	do{
		run = tig.prompt_user();
	} while (run); // TODO good preactice?

	return 0;
}

int old_main(){
	my_graph g;
	g.display();

	g.insertVertex("Go camping");

	g.insertVertex("Pick your campsite");
	g.insertVertex("Yosemite");
	g.insertVertex("Arches");
	g.insertVertex("Mt. Rainier");

	g.insertConnection("Pick your campsite", "Yosemite");
	g.insertConnection("Pick your campsite", "Arches");
	g.insertConnection("Pick your campsite", "Mt. Rainier");

	g.insertConnection("Go camping", "Pick your campsite");

	g.insertVertex("Figure out how you'll sleep");
	g.insertVertex("Rent or purchase a luxury trailer");
	g.insertVertex("In the dirt");
	g.insertVertex("In a tent");
	g.insertVertex("In your car");

	g.insertConnection("Figure out how you'll sleep", "Rent or purchase a luxury trailer");
	g.insertConnection("Figure out how you'll sleep", "In the dirt");
	g.insertConnection("Figure out how you'll sleep", "In a tent");
	g.insertConnection("Figure out how you'll sleep", "In your car");

	g.insertConnection("Go camping", "Figure out how you'll sleep");

	g.insertVertex("Reserve your campsite before arriving");
	g.insertConnection("Yosemite", "Reserve your campsite before arriving");
	g.insertConnection("Arches", "Reserve your campsite before arriving");
	g.insertConnection("Mt. Rainier", "Reserve your campsite before arriving");



	cout << endl << "Display(): " << endl;
	g.display();

	cout << endl << "Depth first traversal1:" << endl;
	g.depthFirstTraverse("Go camping", my_visit);

	g.insertVertex("tent");
	g.insertConnection("In a tent", "tent");
	g.insertVertex("tent_child");
	g.insertConnection("tent", "tent_child");
	g.insertVertex("tent_child_child");
	g.insertConnection("tent_child", "tent_child_child");

	cout << endl << endl << endl << "Display(): " << endl;
	g.display();


	cout << endl << "Depth first traversal2:" << endl;
	g.depthFirstTraverse("Go camping", my_visit);

	return 0;
}