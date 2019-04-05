/*
*This file contains function declared in game.hpp
*this functions handle the game play and checking the winner
* @author : ghouibi ghassen
*/
#include <iostream>
#include <random>
#include "game.hpp"

/*
* Function to init the grid
*/
grid_t Game::init_grid(){
	grid.line=L;
	grid.colomn=H;
	for(int i=0;i<L;i++){
		for(int j=0;j<H;j++)
			grid.grid[i][j]=0;
	}

	return grid;
}

/*
*Function to get the grid
*/
grid_t Game::get_grid(){
	return grid;
}
/*
* Function to show the grid
*/
void Game::show_grid(grid_t grid){

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
}

/*
* The function to play otherwise to place our pawn in the grid
*/
grid_t Game::play(grid_t grid,int placement,int player){
	if(check_play(grid,placement)){
		for(int i=0;i<H;i++){
			if (grid.grid[placement][i]==0){
				grid.grid[placement][i]=player;
				show_grid(grid);
				return grid;
			}
		}
	}
	return grid;
}
/*
* Function check the next played move if we can place our pawn
*/
int Game::check_play(grid_t grid,int placement){
	if(placement>=L){
		std::cout<<"This placment does'nt exist ! \n";
		return 0;
	}
	for(int i=0;i<H;i++){
		if(grid.grid[placement][i]==0)
			return 1;
	}
	std::cout<<"injection rejected colone is full !\n";
	return 0;
}


/*
* Function to check winner in case we have 4 pawn in line or colomn or diagonal
*/
int Game::check_winner(grid_t grid){
	played--;
	if(played==0){
		std::cout<<"Null Game\n";
		return 1;
	}
	//check vertical
	for(int i=0;i<L;i++){
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
	for(int i=3;i<L;i++){
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
	for(int i=3;i<L;i++){
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
	for(int i=3;i<L;i++){
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
