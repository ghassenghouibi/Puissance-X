/**
* This file contains the class of minmax algorithme
* @author ghouibi ghassen
**/
#include "node.hpp"


class MinMax{
	public:
		Tree root_node;
				
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