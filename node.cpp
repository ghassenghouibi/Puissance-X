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
		for(int i=0;i<3;i++){
			show_grid(node_print->nodes[0]->nodes[0]->grid);
		}
		std::cout<<"****************************\n";
		show_grid(node_print->nodes[0]->nodes[0]->nodes[0]->grid);
		std::cout<<"****************************\n";
		for(int i=0;i<3;i++){
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
	
	
	for(int i=0;i<L;i++){
		grid_t gridsimulated=simulate_shot(grid,i,player);
		Node* child=nullptr;
		child=new_node(node_number,depth,0,gridsimulated);
		add_node(root,child,i);
		node_number++;
	}

//	

	/*
	while(grid_raws!=4){
		Node* tmp=root;
		for(int j=0;j<L;j++){
			for(int i=0;i<L;i++){
				grid_t gridsimulated=simulate_shot(grid,i,player);
				Node* child=nullptr;
				child=new_node(node_number,depth,0,gridsimulated);
				add_node(root->nodes[j],child,i);
				node_number++;
			}
			grid=root->nodes[j]->grid;
		}
		root=root->node;
		grid_raws++;
	}*/
	/*player=2;
	Node* tmp=root;
	while(l!=L){
		tmp=tmp->nodes[l];
		grid=root->nodes[l]->grid;
		while(length!=L){
			for(int i=0;i<L;i++){
				grid_t gridsimulated=simulate_shot(grid,i,player);
				Node* child=nullptr;
				child=new_node(node_number,depth,0,gridsimulated);
				add_node(tmp,child,i);
				node_number++;
			}
			if(player==1) player=2;
			else player=1;

			//grid=root->nodes[length]->grid;
			//root=root->nodes[l];
			//std::cout<<root->nodes[0]->node_number;
			print_node_with_child(root);

			depth++;
			length++;
			std::cout<<"----------------------PNL-------------------\n";			
		}
		l++;
	}*/
		/*
	while(grid_raws!=2){
		while(length!=L){
			
			for(int i=0;i<L;i++){
				grid_t gridsimulated=simulate_shot(grid,i,player);
				Node* child=nullptr;
				child=new_node(node_number,depth,0,gridsimulated);
				add_node(root,child,i);
				node_number++;
			}
			
			if(player==1) player=2;
			else player=1;
			depth++;
			length++;
			print_node_with_child(root);
			grid=root->nodes[length]->grid;
			root=root->nodes[length];
		}
		length=0;
		grid_raws++;

	}
		
    print_node_with_child(root);

*/
/*
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
	//print_node_with_child(root->nodes[6]->nodes[3]);
	

	depth++;
	for(int f=0;f<L;f++){
		for(int k=0;k<L;k++){
			for(int i=0;i<L;i++){
				grid=root->nodes[f]->nodes[k]->nodes[i]->grid;
				for(int j=0;j<L;j++){
				Node* child=nullptr;
				grid_t gridsimulated=simulate_shot(grid,j,2);
				child=new_node(node_number,depth,0,gridsimulated);
				add_node(root->nodes[f]->nodes[k]->nodes[i],child,j);
				node_number++;
				}
			}
		}
	}

	//print_node_with_child(root->nodes[6]->nodes[3]->nodes[2]);
	depth++;
	for(int x=0;x<L;x++){
		for(int f=0;f<L;f++){
			for(int k=0;k<L;k++){
				for(int i=0;i<L;i++){
					grid=root->nodes[x]->nodes[f]->nodes[k]->nodes[i]->grid;
					for(int j=0;j<L;j++){
					Node* child=nullptr;
					grid_t gridsimulated=simulate_shot(grid,j,1);
					child=new_node(node_number,depth,0,gridsimulated);
					add_node(root->nodes[x]->nodes[f]->nodes[k]->nodes[i],child,j);
					node_number++;
					}
				}
			}
		}
	}

	//print_node_with_child(root->nodes[0]->nodes[6]->nodes[2]->nodes[6]);
	depth++;

	for(int y=0;y<L;y++){
		for(int x=0;x<L;x++){
			for(int f=0;f<L;f++){
				for(int k=0;k<L;k++){
					for(int i=0;i<L;i++){
						grid=root->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i]->grid;
						for(int j=0;j<L;j++){
						Node* child=nullptr;
						grid_t gridsimulated=simulate_shot(grid,j,2);
						child=new_node(node_number,depth,0,gridsimulated);
						add_node(root->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i],child,j);
						node_number++;
						}
					}
				}
			}
		}
	}

	//print_node_with_child(root->nodes[0]->nodes[6]->nodes[2]->nodes[6]->nodes[1]);
	depth++;

	for(int w=0;w<L;w++){
		for(int y=0;y<L;y++){
			for(int x=0;x<L;x++){
				for(int f=0;f<L;f++){
					for(int k=0;k<L;k++){
						for(int i=0;i<L;i++){
							grid=root->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i]->grid;
							for(int j=0;j<L;j++){
							Node* child=nullptr;
							grid_t gridsimulated=simulate_shot(grid,j,1);
							child=new_node(node_number,depth,0,gridsimulated);
							add_node(root->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i],child,j);
							node_number++;
							}
						}
					}
				}
			}
		}
	}
	//print_node_with_child(root->nodes[5]->nodes[3]->nodes[2]->nodes[6]->nodes[1]->nodes[3]);
	depth++;
	for(int a=0;a<L;a++){
		for(int w=0;w<L;w++){
			for(int y=0;y<L;y++){
				for(int x=0;x<L;x++){
					for(int f=0;f<L;f++){
						for(int k=0;k<L;k++){
							for(int i=0;i<L;i++){
								grid=root->nodes[a]->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i]->grid;
								for(int j=0;j<L;j++){
								Node* child=nullptr;
								grid_t gridsimulated=simulate_shot(grid,j,2);
								child=new_node(node_number,depth,0,gridsimulated);
								add_node(root->nodes[a]->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i],child,j);
								node_number++;
								}
							}
						}
					}
				}
			}
		}
	}
	//print_node_with_child(root->nodes[5]->nodes[3]->nodes[2]->nodes[6]->nodes[1]->nodes[3]->nodes[0]);

	depth++;
	for(int b=0;b<L;b++){
		for(int a=0;a<L;a++){
			for(int w=0;w<L;w++){
				for(int y=0;y<L;y++){
					for(int x=0;x<L;x++){
						for(int f=0;f<L;f++){
							for(int k=0;k<L;k++){
								for(int i=0;i<L;i++){
									grid=root->nodes[b]->nodes[a]->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i]->grid;
									for(int j=0;j<L;j++){
									Node* child=nullptr;
									grid_t gridsimulated=simulate_shot(grid,j,1);
									child=new_node(node_number,depth,0,gridsimulated);
									add_node(root->nodes[b]->nodes[a]->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i],child,j);
									node_number++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//print_node_with_child(root->nodes[5]->nodes[3]->nodes[2]->nodes[6]->nodes[1]->nodes[3]->nodes[0]->nodes[5]);
  	depth++;
  	for(int c=0;c<L;c++){
		for(int b=0;b<L;b++){
			for(int a=0;a<L;a++){
				for(int w=0;w<L;w++){
					for(int y=0;y<L;y++){
						for(int x=0;x<L;x++){
							for(int f=0;f<L;f++){
								for(int k=0;k<L;k++){
									for(int i=0;i<L;i++){
										grid=root->nodes[c]->nodes[b]->nodes[a]->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i]->grid;
										for(int j=0;j<L;j++){
										Node* child=nullptr;
										grid_t gridsimulated=simulate_shot(grid,j,1);
										child=new_node(node_number,depth,0,gridsimulated);
										add_node(root->nodes[c]->nodes[b]->nodes[a]->nodes[w]->nodes[y]->nodes[x]->nodes[f]->nodes[k]->nodes[i],child,j);
										node_number++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	print_node_with_child(root->nodes[5]->nodes[3]->nodes[2]->nodes[6]->nodes[1]->nodes[3]->nodes[0]->nodes[5]->nodes[3]);
*/
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