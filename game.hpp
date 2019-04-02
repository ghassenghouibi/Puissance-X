/**
*
*
*
*
*
*
*/
#include <array>
#define L 7
#define H 6

class Game{
	private:
		int grid[L][H]={0};
		int played=L*H;
	public:
		int 	play(int placement,int player); 
		void 	show_grid();
		int  	check_winner();
		void 	swap();
		void 	game_engine();
};