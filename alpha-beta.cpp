/** This file contains functions of minmax algorithm
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


int MinMax::negamax(grid_t grid, int depth ,int player){
	if(grid_full(grid)){
		std::cout<<"grid is full fool";
		return 0;
	}

	std::vector<int> shots=get_possible_shots(grid);
	for(int i=0;i<shots.size();i++){
		std::cout<<shots[i]<<" this shot is possible \n";
	}

	return 0;
}


std::vector<int> MinMax::get_possible_shots(grid_t grid){

	std::vector<int> possible_shots;
	for(int j=0;j<W;j++){
		for(int i=0;i<H;i++){
			if (grid.grid[j][i]==0){
				possible_shots.push_back(j);
				break;
			}
		}
	}

	return possible_shots;

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



/*Function to check the grid*/
int MinMax::grid_full(grid_t grid){
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(grid.grid[j][i]==0){
				return 0;
			}
		}
	}

	return 1;
}