/*
* This file contains functions of minmax algorithm
* @author ghouibi ghassen 
*/
#include <iostream>
#include "alpha-beta.hpp"


 
void MinMax::get_possible_shot(grid_t grid ,int played){
	int res,player=1;
	do{
		for(int i=0;i<W;++i){
			if(grid.grid[i][H-1]==0){
				grid=simulate_shot(grid,i,(player+1));
				player=!(player);
				res=check_winner(grid,played);
				if(res==1)
					break;
			}
		}
	}while(res!=1);
}

grid_t MinMax::simulate_shot(grid_t grid,int position,int player){

	for(int i=0;i<H;i++){
		if (grid.grid[position][i]==0){
			grid.grid[position][i]=player;
			break;
		}
	}
	
	return grid;
}

int MinMax::check(grid_t grid){
	for(int i=0;i<W;++i){
		if(grid.grid[i][H-1]==0)
			return i;
	}
	return 0;
}

int MinMax::play(grid_t grid,int played){

	get_possible_shot(grid,played);
	int res=check(grid);
	return res;
}

int MinMax::evaluate_shot(grid_t grid,int played){
	int res;
	res=check_winner(grid,played);
	if(res==1)
		return res*1000;
	else
		return -res*1000;

	return 0;

}

int MinMax::check_winner(grid_t grid,int played){
	played--;
	if(played==0){
		std::cout<<"Null Game\n";
		return 1;
	}
	//check vertical
	for(int i=0;i<W;i++){
		for(int j=3;j<H;j++){
			if( 	(grid.grid[i][j] != 0) 
				 && ( grid.grid[i][j]== grid.grid[i][j-1] )
				 && ( grid.grid[i][j]== grid.grid[i][j-2] )
				 && ( grid.grid[i][j]== grid.grid[i][j-3] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid.grid[i][j]<<"\n";
				return 1;
			}
		}
	}

	//check horizontal
	for(int i=3;i<W;i++){
		for(int j=0;j<H;j++){
			if( 	(grid.grid[i][j] != 0) 
				 && ( grid.grid[i][j]== grid.grid[i-1][j] )
				 && ( grid.grid[i][j]== grid.grid[i-2][j] )
				 && ( grid.grid[i][j]== grid.grid[i-3][j] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid.grid[i][j]<<"\n";
				return 1;
			}
		}
	}

	//check diagonal
	for(int i=3;i<W;i++){
		for(int j=3;j<H;j++){
			if( 	(grid.grid[i][j] != 0) 
				 && ( grid.grid[i][j]== grid.grid[i-1][j-1] )
				 && ( grid.grid[i][j]== grid.grid[i-2][j-2] )
				 && ( grid.grid[i][j]== grid.grid[i-3][j-3] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid.grid[i][j]<<"\n";
				return 1;
			}
			
		}
	}
	
	//check diagonal
	for(int i=3;i<W;i++){
		for(int j=0;j<H-4;j++){

			if( 	(grid.grid[i][j] != 0) 
				 && ( grid.grid[i][j]== grid.grid[i-1][j+1] )
				 && ( grid.grid[i][j]== grid.grid[i-2][j+2] )
				 && ( grid.grid[i][j]== grid.grid[i-3][j+3] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid.grid[i][j]<<"\n";
				return 1;
			}
			
		}
	}
	

	return 0;
	
}

