#include <iostream>
#include "LaVieja.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */





int main(int argc, char** argv) {
	
	LaVieja *juego = new LaVieja();
	juego->jugar();
	
	return 0;
}
