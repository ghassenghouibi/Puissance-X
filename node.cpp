#include "node.hpp"


void Node::add_node(Node* root_node,Node* new_node,int i){
	root_node->nodes[i]=new_node;

}


void Node::show_grid(grid_t grid){

	for(int j=H-1;j>=0;j--){
			for(int i=0;i<L;i++){
				if(grid.grid[i][j]==1)
					std::cout<<"O";
				else if(grid.grid[i][j]==2)
					std::cout<<"X";
				else
					std::cout<<".";
				std::cout<<" ";
			}
			std::cout<<"\n";
	}
}

void Node::print_node(Node* node_print){
		std::cout   <<"Node_number " <<node_print->node_number
					<<" Depth "      <<node_print->depth
					<<" Value "      <<node_print->value
					<<" Grid  of node :"      
					<<" \n";
					show_grid(node_print->grid);
		std::cout <<"End printing node\n";	
}



Node* Node::new_node(int node_number,int depth,int value,grid_t grid){
    Node *x = new Node;
    x->node_number=node_number;
    x->depth=depth;
    x->value=value;
    x->grid=grid;
    return x; 
}



void Tree::insert_node(Node* node){
	if(!node)
		return;
	if(root==NULL){
		root=node;
		return;
	}

	Node* current=root;
	Node* next=NULL;
	int i=0;
	


	
	Node x;
	x.print_node(node);
	
}