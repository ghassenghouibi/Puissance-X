/**
* This file contains the class of minmax algorithme
* @author ghouibi ghassen
**/
#include "shared.hpp"

typedef struct tree tree;
class MinMax{
	private:
			
	public:
		int 	play(grid_t grid);
		int  	show_grid(int placement,int player);
		void 	get_possible_shot(grid_t grid);
		void 	get_shot();
		void 	shot_score();
		void 	minmax();
		void 	calculate_best_shot(void* player_position);
		void 	simulate_shot(grid_t grid,int position);
		void 	evaluate(void* player_position);
		void 	get_score();
};