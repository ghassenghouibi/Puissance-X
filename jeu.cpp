/*
*
*
*
*
*
*
*/
#include <iostream>
#include <random>
#include "jeu.hpp"

using namespace std;



	


void Jeu::play(int p){

    std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,100);
	int number;
	bool joueur=false;

	do{

		number = distribution(generator);
		joueur=!joueur;

	}while(grille[number]==0);
	
}


void Jeu::show(){
	for(int i=0;i<L;i++){
		for(int j=0;j<H;j++){
			std::cout<<grille[i*j];
		}
		std::cout<<"\n";
	}
}

