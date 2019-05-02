
#include "game.hpp"
#include <iostream>

class Node{

	public:
		int node_number;
		int depth;
		int value;
		grid_t grid;
		Node* nodes[W];
	public:
		Node*  new_node(int node_number,int depth,int value,grid_t grid);
		grid_t simulate_shot(grid_t grid,int position,int player);
		Node*  fill_root_node(Node* root,grid_t grid,int node_number,int player,int depth);
		void   add_node(Node* root_node,Node* new_node,int i);
		void   print_node_with_child(Node* root_node);
		void   insert_node_to_root(Node* root,Node* node);
		void   show_grid(grid_t grid);
		void   engine_nodes(grid_t grid);
		int    grid_is_full(grid_t grid,int height);

		
};


