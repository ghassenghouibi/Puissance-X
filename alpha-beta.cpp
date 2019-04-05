/*
* This file contains functions of minmax algorithm
* @author ghouibi ghassen 
*/
#include <iostream>
#include "alpha-beta.hpp"


void get(grid_t grid,int indice){


}

void MinMax::get_possible_shot(grid_t grid ){
	for(int i=0;i<L;i++){
		if(grid.grid[i][H]==0)
			simulate_shot(grid,i);

	}
}


void MinMax::simulate_shot(grid_t grid,int position){

	std::cout << "-------------------------------------\n";
	for(int i=0;i<H;i++){
		if (grid.grid[position][i]==0){
			grid.grid[position][i]=2;
			break;
		}
	}
	for(int j=H-1;j>=0;j--){
			for(int i=0;i<L;i++){
				if(grid.grid[i][j]==1)
					std::cout<<"O";
				else if(grid.grid[i][j]==2)
					std::cout<<"X";
				else
					std::cout<<".";
				std::cout<<" ";
			}
			std::cout<<"\n";
	}

	std::cout << "-------------------------------------\n";
}

int MinMax::play(grid_t grid){
	get_possible_shot(grid);

	return 0;
}