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
int MinMax::negamax(Node* node, int depth ,int player){
	a++;
	if(grid_full(node->grid)){
		std::cout<<"grid is full fool";
		return 0;
	}

	int eval=evalute_grid(node->grid,player);
	std::vector<int> shots=get_possible_shots(node->grid);
	for(int i=0;i<signed(shots.size());i++){
		if(!(grid_full(node->grid)) && check_win( simulate_shot(node->grid,i,player))){
			return 1000-i;
		}
	}

	

	int best_score=0;
	for(int i=0;i<W;i++){
        if(!(height_full(node->grid,i))){
			Node* new_node=new_node->new_node(i,a,eval,node->grid);
			
			grid_t gridPlayed=new_node->simulate_shot(node->grid,i,player);
			Node* child =child->new_node(i,a++,eval,gridPlayed);
			new_node->childNodes[i]=child;
			if(player==2)
				player=1;
			else
				player=2;
			new_node->print_node_with_child(new_node);
			int actual_score=negamax(new_node->childNodes[i],depth,player);
			std::cout<<"score "<<actual_score<<" \n";
			if(actual_score>best_score){
				best_score=actual_score;
				child->node_number=i;
				std::cout<<"hahahahahahha \n "<<i;
			}
			//int acctual_score=-negamax(new_node->grid,depth,player);
			
		}
	}
	std::cout<<"The bestt \n"<<best_score<<"\n";
	
	return best_score;
}

int MinMax::height_full(grid_t grid,int position){
	for(int i=0;i<H;i++){
		if(grid.grid[position][i]==0){
			return 0;
		}
	}
	return 1;
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
					return 1000  ;	
				}
				else{
					return -1000 ;
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
					return 1000;	
				}
				else{
					return -1000;
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
					return 1000;	
				}
				else{
					return -1000;
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
					return 1000;	
				}
				else{
					return -1000;
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