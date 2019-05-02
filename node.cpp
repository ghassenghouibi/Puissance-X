 #include "node.hpp"

Node* Node::new_node(int node_number,int depth,int value,grid_t grid){
    Node *x = new Node;
    x->node_number=node_number;
    x->depth=depth;
    x->value=value;
    x->grid=grid;
    for(int i=0;i<W;i++){
    	x->nodes[i]=nullptr;
	}
    return x; 
}



void Node::print_node_with_child(Node* node_print){


	std::cout   <<"Root Node Node_number " <<node_print->node_number
					<<" Depth "      <<node_print->depth
					<<" Value "      <<node_print->value
					<<" Grid  of node :"      
					<<" \n";
					show_grid(node_print->grid);
		std::cout <<"End printing node\n";

	//TODO check if nodes[L+1] != nullptr
	for(int i=0;i<W;i++){	
		if(node_print->nodes[i]!=nullptr){		
		std::cout   <<"Child Node Node_number " <<node_print->nodes[i]->node_number
					<<" Depth "      <<node_print->nodes[i]->depth
					<<" Value "      <<node_print->nodes[i]->value
					<<" Grid  of node :"       
					<<" \n";
					show_grid(node_print->nodes[i]->grid);
		std::cout <<"End printing node\n";	
		}
		else{
			std::cout<<"null\n";
		}

	}

}

grid_t Node::simulate_shot(grid_t grid,int position,int player){

	for(int i=0;i<H;i++){
		if (grid.grid[position][i]==0){
			grid.grid[position][i]=player;
			return grid;
		}
	}
	
	return grid;
}


void Node::add_node(Node* root_node,Node* new_node,int i){
	root_node->nodes[i]=new_node;
}

Node* Node::fill_root_node(Node* root,grid_t grid,int node_number,int player,int depth){
		
	for(int i=0;i<W;i++){
		grid_t gridsimulated=simulate_shot(grid,i,player);
		Node* child=nullptr;
		child=new_node(node_number,depth,0,gridsimulated);
		add_node(root,child,i);
		node_number++;
	}

  return root;
}

void Node::show_grid(grid_t grid){

	for(int j=H-1;j>=0;j--){
			for(int i=0;i<W;i++){
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


int Node::grid_is_full(grid_t grid,int height){
	for(int i=0;i<height;i++){
		for(int j=0;j<W;j++){
			if(grid.grid[i][j]==0){
				return 0;
			}
		}
	}
	return 1;
}

void Node::insert_node_to_root(Node* root,Node* node){
	for(int i=0;i<W;i++){
		root->nodes[i]=node;
	}
}

