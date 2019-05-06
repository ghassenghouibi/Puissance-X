/** This file contains the functions of the gameEngine class
* @author ghouibi ghassen
**/
#include <iostream>
#include "gameEngine.hpp"
#include "alpha-beta.hpp"

void GameEngine::print_welcome(){
   	std::cout<<"Hello this a game called Connect4\nvery simple you have to place 4 times your pawn \nvertically or horizontally or diagonally" << "\n";
}

void GameEngine::print_goodbye(){
	std::cout<<"GoodBye my friend\n";
}

void GameEngine::game_engine(){
	

	int player,v,x,placment;
	bool swap=true;
	Game game;
	MinMax ia;
	grid_t grid;
	Tree t;
	grid=game.init_grid();
	print_welcome();
	game.show_grid(grid);

	do{
		if(swap)
			player=1;
		else
			player=2;

		if(player==1){
		    do{
				placment=ia.negamax(grid,0,player);
		    	//t.create_tree(grid,5);
		    	v=game.check_play(grid,placment);
		    	grid=game.play(grid,placment,player);
		    	if(v!=1){
	    			std::cout <<"Player "<<player<< " Your placment please? \n";
		    		std::cin >> placment;
			    	v=game.check_play(grid,placment);
			    	grid=game.play(grid,placment,player);

		    	}
			}while(v==0);
		}
		else if(player==2){
			do{
	    	   	ia.negamax(grid,0,player);
	    	   	std::cout <<"Player "<<player<< " Your placment please? \n";
		    	std::cin >> placment;
		    	v=game.check_play(grid,placment);
		    	grid=game.play(grid,placment,player);
			}while(v==0);	
		}
    	x=game.check_winner(grid);
		swap=!(swap);


	}while(x!=1);

	print_goodbye();
    exit (EXIT_SUCCESS);
}