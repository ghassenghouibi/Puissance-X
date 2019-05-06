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

int a=0;
int MinMax::negamax(grid_t grid, int depth ,int player){
	a++;
	std::cout<<"Appel :"<<a<<"\n";
	if(grid_full(grid)){
		std::cout<<"grid is full fool";
		return 0;
	}

	int eval=evalute_grid(grid,player);
	std::vector<int> shots=get_possible_shots(grid);
	for(int i=0;i<shots.size();i++){
		if(!(grid_full(grid)) && check_win( simulate_shot(grid,i,player))){
			std::cout<<"Winn !\n";
			return 10-i;
		}
	}

	int best_score=10;
	for(int i=0;i<W;i++){
		if(!(grid_full(grid)) ){
			Node* new_node=new Node();
			new_node=new_node->create_node(grid,player);
			new_node->print_node_with_child(new_node);

			if(player==2)
				player=1;
			else
				player=2;

			int acctual_score;
			std::cout<<i<<"<===================\n";
			std::cout<<new_node->childNodes.size()<<"<=============\n";
			if(i<new_node->childNodes.size())
				acctual_score=-negamax(new_node->childNodes[i]->grid,depth,player);



			//for(int k=0;k<signed(new_node->childNodes.size());k++){
			//	std::cout<<"Score   "<<acctual_score<<"\n";
			//}
			if(acctual_score>best_score){
				best_score=acctual_score;
				new_node->node_number=i;
			}
			//int acctual_score=-negamax(new_node->grid,depth,player);
			
		}
	}
	std::cout<<"The besttt \n"<<best_score<<"\n";
	return best_score;
}


grid_t MinMax::simulate_shot(grid_t grid,int position,int player){
	for(int i=0;i<H;i++){
		if (grid.grid[position][i]==0){
			grid.grid[position][i]=player;
			return grid;
		}
	}
	
	return grid;
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

int MinMax::evalute_grid(grid_t grid,int player){

		//check vertical
	for(int i=0;i<W;i++){
		for(int j=3;j<H;j++){
			if( 	(grid.grid[i][j] != 0) 
				 && ( grid.grid[i][j]== grid.grid[i][j-1] )
				 && ( grid.grid[i][j]== grid.grid[i][j-2] )
				 && ( grid.grid[i][j]== grid.grid[i][j-3] )
				 ){
				if(grid.grid[i][j]==player){
					return 10;	
				}
				else{
					return -10;
				}
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
				if(grid.grid[i][j]==player){
					return 10;	
				}
				else{
					return -10;
				}
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
				if(grid.grid[i][j]==player){
					return 10;	
				}
				else{
					return -10;
				}
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
				if(grid.grid[i][j]==player){
					return 10;	
				}
				else{
					return -10;
				}
			}
			
		}
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


int MinMax::check_win(grid_t grid){
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