/**
* This file contains the class of minmax algorithme
* @author ghouibi ghassen
**/

#include "game.hpp"
#include <iostream>

class Node{

	public:
		int node_number;
		int depth;
		int value;
		grid_t grid;
		Node* nodes[L];
	public:
		Node* new_node(int node_number,int depth,int value,grid_t grid);
		void  add_node(Node* root_node,Node* new_node,int i);
		void  print_node(Node *print_node);
		void  show_grid(grid_t grid);		
};


class Tree{
	
	public:
		Node* root;
		static int node_number;
		
	public:
		void insert_node(Node* node);

};

class MinMax{
				
	public:
		int 	play(grid_t grid,int played);

		int     check(grid_t grid); 

		void 	get_possible_shot(grid_t grid,int played);

		void 	get_shot();

		void    create_tree(grid_t grid);

		void 	shot_score();

		void 	calculate_best_shot(void* player_position);

		grid_t 	simulate_shot(grid_t grid,int position,int player);

		int 	evaluate_shot(grid_t grid,int played);

		int     check_winner(grid_t grid,int played);

		void 	get_score();
};


