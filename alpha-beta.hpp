/**
* This file contains the class of minmax algorithme
* @author ghouibi ghassen
**/
#include "tree.hpp"
#include <iostream>


class MinMax{
				
	public:
		int     negamax(grid_t grid,int depth,int player);		
		int     grid_full(grid_t grid);
		std::vector<int> get_possible_shots(grid_t grid);

		int 	play(grid_t grid,int played);
		int     check(grid_t grid); 

		
		void 	get_shot();

		void    create_tree(grid_t grid);

		void 	shot_score();

		void 	calculate_best_shot(void* player_position);

		grid_t 	simulate_shot(grid_t grid,int position,int player);

		int 	evaluate_shot(grid_t grid,int played);

		int     check_winner(grid_t grid,int played);

		void 	get_score();
};


