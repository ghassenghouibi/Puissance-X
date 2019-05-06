/**
* This file contains the game rules
*/
#include "shared.hpp"

class Game{
	public:
		grid_t grid;
		int played=W*H;
	public:
		grid_t    init_grid();
		grid_t    get_grid();
		grid_t 	  play(grid_t grid,int placement,int player); 
		void 	  show_grid(grid_t grid);
		int   	  check_winner(grid_t grid);
		int       check_play(grid_t grid,int placement);

};