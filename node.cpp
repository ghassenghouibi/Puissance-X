 #include "node.hpp"

Node* Node::new_node(int node_number,int depth,int value,grid_t grid){
    Node *x = new Node;
    x->node_number=node_number;
    x->depth=depth;
    x->value=value;
    x->grid=grid;
    for(int i=0;i<L;i++){
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
		for(int i=0;i<L;i++){			
			std::cout   <<"Child Node Node_number " <<node_print->nodes[i]->node_number
						<<" Depth "      <<node_print->nodes[i]->depth
						<<" Value "      <<node_print->nodes[i]->value
						<<" Grid  of node :"       
						<<" \n";
						show_grid(node_print->nodes[i]->grid);
			std::cout <<"End printing node\n";	

		}
		/*std::cout<<"****************************\n";
		show_grid(node_print->nodes[0]->grid);
		std::cout<<"****************************\n";
		for(int i=0;i<7;i++){
			show_grid(node_print->nodes[0]->nodes[0]->grid);
		}
		std::cout<<"****************************\n";
		show_grid(node_print->nodes[0]->nodes[0]->nodes[0]->grid);
		std::cout<<"****************************\n";
		for(int i=0;i<7;i++){
			show_grid(node_print->nodes[0]->nodes[0]->nodes[0]->nodes[i]->grid);
		}
		std::cout<<"****************************\n";*/

}

grid_t Node::simulate_shot(grid_t grid,int position,int player){

	for(int i=0;i<H;i++){
		if (grid.grid[position][i]==0){
			grid.grid[position][i]=player;
			break;
		}
	}
	
	return grid;
}


void Node::add_node(Node* root_node,Node* new_node,int i){
	root_node->nodes[i]=new_node;
}

Node* Node::fill_root_node(Node* root,grid_t grid){
	
	int node_number=0;
	int depth=0;
	for(int i=0;i<L;i++){
		grid_t gridsimulated=simulate_shot(grid,i,1);
		Node* child=nullptr;
		child=new_node(node_number,depth,0,gridsimulated);
		add_node(root,child,i);
		node_number++;
	}

	print_node_with_child(root);
	depth++;
	for(int i=0;i<L;i++){
		grid=root->nodes[i]->grid;
		for(int j=0;j<L;j++){
			Node* child=nullptr;
			grid_t gridsimulated=simulate_shot(grid,j,2);
			child=new_node(node_number,depth,0,gridsimulated);
			add_node(root->nodes[i],child,j);
			node_number++;
		}
	}
	depth++;
	for(int k=0;k<L;k++){
		for(int i=0;i<L;i++){
			grid=root->nodes[k]->nodes[i]->grid;
			for(int j=0;j<L;j++){
			Node* child=nullptr;
			grid_t gridsimulated=simulate_shot(grid,j,1);
			child=new_node(node_number,depth,0,gridsimulated);
			add_node(root->nodes[k]->nodes[i],child,j);
			node_number++;
			}
		}
	}
	print_node_with_child(root->nodes[2]->nodes[4]);
	

	depth++;
	for(int i=0;i<L;i++){
		grid=root->nodes[i]->nodes[i]->nodes[i]->grid;
		for(int j=0;j<L;j++){
			Node* child=nullptr;
			grid_t gridsimulated=simulate_shot(grid,j,2);
			child=new_node(node_number,depth,0,gridsimulated);
			add_node(root->nodes[i]->nodes[i]->nodes[i],child,j);
			node_number++;
		}
	}
	//print_node_with_child(root->nodes[0]->nodes[0]->nodes[0]);
	
		

	/*

	for(int i=0;i<L;i++){
		Node* child=nullptr;
		grid_t gridsimulated=simulate_shot(root->nodes[0]->nodes[i]->grid,i,1);
		child=new_node(i,0,0,gridsimulated);
		add_node(root->nodes[0]->nodes[0],child,i);
	}

	for(int i=0;i<L;i++){
		Node* child=nullptr;
		grid_t gridsimulated=simulate_shot(root->nodes[0]->nodes[0]->nodes[i]->grid,i,2);
		child=new_node(i,0,0,gridsimulated);
		add_node(root->nodes[0]->nodes[0]->nodes[0],child,i);
	}

	for(int i=0;i<L;i++){
		Node* child=nullptr;
		grid_t gridsimulated=simulate_shot(root->nodes[0]->nodes[0]->nodes[i]->grid,i,2);
		child=new_node(i,0,0,gridsimulated);
		add_node(root->nodes[0]->nodes[0]->nodes[0],child,i);
	}*/


  return root;
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

void Node::engine_nodes(grid_t grid){

	Node* root=new Node();
	root=new_node(0,0,0,grid);
	root=fill_root_node(root,grid);

}