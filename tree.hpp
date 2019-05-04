#include "node.hpp"
#include <mutex>
#include <thread>
 
class Tree{
	
	public:
		Node* root=nullptr;
	public:
		int create_tree(grid_t grid,int depth);	

};