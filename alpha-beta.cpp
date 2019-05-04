/*
* This file contains functions of minmax algorithm
* @author ghouibi ghassen 
*/


#include <iostream>
#include "alpha-beta.hpp"



int MinMax::check(grid_t grid){
	for(int i=0;i<W;++i){
		if(grid.grid[i][H-1]==0)
			return i;
	}
	return 0;
}



/*
int negamax(grid_t,int depth,int plater,int coup){
	if(possible_shots().empty())
		return evaluations.of.possible_shots();

	int best_shot=


	for(list des coups possible ){
		play();
		int eval=-negamax(depth-1,player,shot);
		if(eval> best_eval){
			best_eval=eval;
			best_eval=play();
		}
		unplay();
	}
	return best_shot;
}*/