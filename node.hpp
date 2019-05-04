
#include "game.hpp"
#include <iostream>
#include <vector>
class Node{

	public:
		int node_number;
		int depth;
		int value;
		grid_t grid;
		std::vector<Node*> childNodes;
	public:
		Node*  new_node(int node_number,int depth,int value,grid_t grid);
		grid_t simulate_shot(grid_t grid,int position,int player);
		Node*  fill_node(Node* root,int node_number,int player);
		void   add_node(Node* root_node,Node* new_node,int i);
		void   print_node_with_child(Node* root_node);
		void   insert_node_to_root(Node* root,Node* node);
		void   show_grid(grid_t grid);
		Node*  create_node(grid_t grid,int player);
		int    grid_is_full(grid_t grid);
		int    possible_shots(grid_t grid,int position);
		int    evalute_node(grid_t grid,int player);

};


