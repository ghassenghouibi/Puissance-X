 #include "node.hpp"

Node* Node::new_node(int node_number,int depth,int value,grid_t grid){

    Node *new_node = new Node;
    new_node->node_number=node_number;
    new_node->depth=depth;
    new_node->value=value;
    new_node->grid=grid;   

    return new_node; 
}



Node* Node::create_node(grid_t grid,int player){

	Node* node=new Node();
	node=new_node(0,0,0,grid);
	int depth=node->depth;

	node=fill_node(node,1,player);

	return node;
}

grid_t Node:: simulate_shot(grid_t grid,int position,int player){
	for(int i=0;i<H;i++){
		if (grid.grid[position][i]==0){
			grid.grid[position][i]=player;
			return grid;
		}
	}
	
	return grid;
}

int Node::possible_shots(grid_t grid,int position){
	for(int i=0;i<H;i++){
		if (grid.grid[position][i]==0){
			return 1;
		}
	}
	return 0;
}

Node* Node::fill_node(Node* root,int node_number,int player){

	for(int i=0;i<W;i++){
		if(possible_shots(root->grid,i)){
			grid_t gridsimulated=simulate_shot(root->grid,i,player);
			Node* child=new Node();
			child=new_node(node_number,++(root->depth),0,gridsimulated);
			(root->childNodes).push_back(child);
			node_number++;

		}

	}
	if(root->childNodes.size()==1){
		//std::cout<<"\n     Evaluteee ....\n";
	}
	//std::cout<<"------------------------------\n";
	//print_node_with_child(root);
	//std::cout<<"------------------------------\n";

	return root;
}


void Node::print_node_with_child(Node* node_print){


	std::cout   <<"Root Node Node_number " <<node_print->node_number
					<<" Depth "      <<node_print->depth
					<<" Value "      <<node_print->value
					<<" Grid  of node :"      
					<<" \n";
					show_grid(node_print->grid);
				
	std::cout<<"This root have "<<(node_print->childNodes).size()<<" child\n";
	int size=(node_print->childNodes).size();
	for(int i=0;i<size;i++){
		std::cout   <<"Root Node Node_number " <<node_print->childNodes[i]->node_number
					<<" Depth "      <<node_print->childNodes[i]->depth
					<<" Value "      <<node_print->childNodes[i]->value
					<<" Grid  of node :"      
					<<" \n";
					show_grid(node_print->childNodes[i]->grid);
	}	
	std::cout <<"End printing node\n";


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


int Node::grid_is_full(grid_t grid){
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(grid.grid[i][j]==0){
				return 0;
			}
		}
	}
	return 1;
}