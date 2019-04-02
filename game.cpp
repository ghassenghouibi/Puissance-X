/*
*This file contains function declared in game.hpp
*this functions handle the game play and checking the winner
* @author : ghouibi ghassen
*/
#include <iostream>
#include <random>
#include "game.hpp"

using namespace std;



int Game::play(int placement,int joueur){
	if(placement>=L){
		std::cout<<"This placment does'nt exist ! \n";
		return 0;
	}
	for(int i=0;i<H;i++){
		if (grid[placement][i]==0){
			grid[placement][i]=joueur;
			show_grid();
			return 1;
		}
	}
	std::cout<<"injection rejected colone is full !\n";
	return 0;
	
}

void Game::show_grid(){
	for(int j=H-1;j>=0;j--){
		for(int i=0;i<L;i++){
			if(grid[i][j]==1)
				std::cout<<"O";
			else if(grid[i][j]==2)
				std::cout<<"X";
			else
				std::cout<<".";
			std::cout<<" ";
		}
		std::cout<<"\n";
	}
}


int Game::check_winner(){
	played--;
	if(played==0){
		std::cout<<"Null Game\n";
		return 1;
	}
	//check vertical
	for(int i=0;i<L;i++){
		for(int j=3;j<H;j++){
			if( 	(grid[i][j] != 0) 
				 && ( grid[i][j]== grid[i][j-1] )
				 && ( grid[i][j]== grid[i][j-2] )
				 && ( grid[i][j]== grid[i][j-3] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid[i][j]<<"\n";
				return 1;
			}
		}
	}

	//check horizontal
	for(int i=3;i<L;i++){
		for(int j=0;j<H;j++){
			if( 	(grid[i][j] != 0) 
				 && ( grid[i][j]== grid[i-1][j] )
				 && ( grid[i][j]== grid[i-2][j] )
				 && ( grid[i][j]== grid[i-3][j] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid[i][j]<<"\n";
				return 1;
			}
		}
	}

	//check diagonal
	for(int i=3;i<L;i++){
		for(int j=3;j<H;j++){
			if( 	(grid[i][j] != 0) 
				 && ( grid[i][j]== grid[i-1][j-1] )
				 && ( grid[i][j]== grid[i-2][j-2] )
				 && ( grid[i][j]== grid[i-3][j-3] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid[i][j]<<"\n";
				return 1;
			}
			if( 	(grid[i][j] != 0) 
				 && ( grid[i][j]== grid[i+1][j+1] )
				 && ( grid[i][j]== grid[i+2][j+2] )
				 && ( grid[i][j]== grid[i+3][j+3] )
				 ){
				std::cout<<"We have a winner Player Number  "<<grid[i][j]<<"\n";
			}
		}
	}
	
	return 0;
}

void Game::game_engine(){
	Game game;
   	std::cout << "Hello this a game called Puissance 4\nvery simple you have to place 4 times your pawn \nvertically or horizontally or diagonally" << "\n";
	game.show_grid();

	int player,v,x,placment;
	bool swap=true;
	do{
		if(swap)
			player=1;
		else
			player=2;

	 
	    do{
    	   	std::cout <<"Player "<<player<< " Your placment please? \n";
	    	std::cin >> placment;
	    	v=game.play(placment,player);
		}while(v==0);
    	x=game.check_winner();
		swap=!(swap);

	}while(x!=1);
	std::cout<<"GoodBye !!\n";
}
