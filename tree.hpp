#include "node.hpp"
#include <mutex>
#include <thread>
 
class Tree{
	
	public:
		Node* root=nullptr;
	public:
		void create_tree(grid_t grid,int depth);	
		
};