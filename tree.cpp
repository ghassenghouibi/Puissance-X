#include "tree.hpp"



void Tree::create_tree(grid_t grid){


	
	std::vector<Node*> tree;

	std::vector<grid_t> treeGrid;

	Node* root=new Node();
	root=root->create_node(grid,1);

	for(int i=0;i<root->childNodes.size();i++){
		tree.push_back(root->childNodes[i]);
	}

	int size=tree.size();
	int first_size=0;
	int played=H*W;
	played--;
	int player=2;
	Node* f;
	while(played){
		
		f=new Node();
		for(int j=0;j<size;j++){
			for(int i=0;i<W;i++){
				f=f->create_node(tree[j]->grid,player);
			}
			/*std::cout<<"\n played :"<<played<<"\n";
			std::cout<<"\n size :"<<size<<" now :"<<j<<"\n";
			std::cout<<"\n childNodes :"<<f->childNodes.size()<<"\n";*/
			for(int k=0;k<f->childNodes.size();k++){
				tree.push_back(f->childNodes[k]);
			}
		}
		if(player==2)
			player=1;
		else
			player=2;

		//tree.erase(tree.begin(),tree.begin()+size);
		size=tree.size();
		played--;
	}




	/*for(int i=0;i<tree.size();i++){
		std::cout<<"------------"<<i<<"----------\n";
		root->show_grid(tree[i]->grid);
		std::cout<<"------------H---------\n";
	}
	*/
	std::cout<<"\n"<<tree.size()<<"\n";





}
