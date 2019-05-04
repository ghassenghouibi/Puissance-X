#include "tree.hpp"



int Tree::create_tree(grid_t grid,int depth){


	std::vector<Node*> tree;
	std::vector<grid_t> treeGrid;
	std::mutex child_mutex;

	Node* root=new Node();
	root=root->create_node(grid,1);
	root->show_grid(root->grid);

	for(int i=0;i<signed(root->childNodes.size());i++){
		tree.push_back(root->childNodes[i]);
	}

	int size=tree.size();
	int player=2;
	Node* f;

	while(depth){

		f=new Node();
		for(int j=0;j<size;j++){
			for(int i=0;i<W;i++){
				f=f->create_node(tree[j]->grid,player);
			}
			for(int k=0;k<signed(f->childNodes.size());k++){
				tree.push_back(f->childNodes[k]);

			}
		}
		if(player==2)
			player=1;
		else
			player=2;
		
		size=tree.size();
		depth--;
	}

	for(int i=0;i<signed(tree.size());i++){
		if(tree[i]->value==10){
			std::cout<<tree[i]->node_number<<"\n";
			return tree[i]->node_number;
			//root->show_grid(tree[i]->grid);
		}		
	}

	return tree[tree.size()-1]->node_number;
}

/*
void save_child(Node* child){
	std::lock_guard<std::mutex> lock(numbers_mutex);
	tree.push_back(child);
}
*/