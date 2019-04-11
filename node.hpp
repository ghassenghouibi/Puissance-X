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