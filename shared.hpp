#ifndef __SHARED_HPP_
#define __SHARED_HPP_
	#define W 7
	#define H 6

	typedef struct grid_t grid_t;
	struct grid_t{
		int colomn;
		int line;
		int grid[W][H];
	};

#endif 

