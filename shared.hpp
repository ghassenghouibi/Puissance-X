/*
This file containes the grid of the game with width & height 
*/
#ifndef __SHARED_HPP_
#define __SHARED_HPP_
	#define W 4
	#define H 4

	typedef struct grid_t grid_t;
	struct grid_t{
		int colomn;
		int line;
		int grid[W][H];
	};

#endif 

