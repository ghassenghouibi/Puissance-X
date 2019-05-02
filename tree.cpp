#include "tree.hpp"



void Tree::create_tree(grid_t grid){


	Tree root;
	Node* new_node=new Node();
	int depth=0;

	new_node->fill_root_node(new_node,grid,0,1,depth);



	depth++;
	for(int j=0;j<W;j++){
		for(int i=0;i<W;i++){
			Node* t;
			t=new Node();
			t->fill_root_node(new_node->nodes[j],new_node->nodes[j]->grid,0,2,depth);
		}
	}
	new_node->print_node_with_child(new_node->nodes[1]);

	//new_node->print_node_with_child(new_node->nodes[2]);

	/*int possible=1;
	for(int j=0;j<2;j++){
		grid=new_node->nodes[j]->grid;
		
		new_node->print_node_with_child()
		new_node=new_node->nodes[0];
	}
	*/



}
