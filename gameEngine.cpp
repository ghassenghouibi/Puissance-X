/*
* This file contains the functions of the gameEngine class
* @author ghouibi ghassen
*/
#include <iostream>
#include "gameEngine.hpp"
#include "game.hpp"
#include "alpha-beta.hpp"
void GameEngine::print_welcome(){
   	std::cout << "Hello this a game called Puissance 4\nvery simple you have to place 4 times your pawn \nvertically or horizontally or diagonally" << "\n";
}
void GameEngine::game_engine(){
	Game game;
	print_welcome();
	game.init_grid();
	game.show_grid();
	game.get_grid();
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

    exit (EXIT_SUCCESS);
}