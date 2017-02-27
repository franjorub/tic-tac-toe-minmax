#ifndef LAVIEJA_H
#define LAVIEJA_H
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using std::cout;
using std::endl;

class LaVieja
{
	public:
		LaVieja(){tablero = new int *[3]; for(int i = 0; i < 3; i++) tablero[i] = new int [3]; llenar(); fi=co=0;};
		int evaluacion();
		void llenar();
		void jugar();
		void imprimir();
		bool Terminal();
		bool tableroLLeno();
		int max();
		int min ();
		void JuegaMaquina();
	protected:
		int **tablero;
		int fi,co;
};

void LaVieja::JuegaMaquina(){/*BUSCA DONDE UBICAR AL MAXIMO*/
	if(!Terminal()){//SI LA PARTIDA NO HA TERMINADO
		int f = 0;
		int c = 0;
		int v = -999999;
		int aux;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (tablero [i][j]==-1){
					tablero[i][j]=0;//pongo la ficha				
					aux = min();//busco los varoes de min
					if(aux > v){//busco al mas grande
						v = aux;
						f = i;
						c = j;
					}
					tablero[i][j]=-1;//quito la ficha
				}
			}
		}
		tablero [f][c]=0;//ficha en la casilla definitiva
	}

}

int LaVieja::max(){
	//CASO BASE
    if (Terminal()){//si la partida termino
        if (evaluacion() != 0) return -10;//si el tablero es distinto de empate gano min por ser el ultimo en jugar
        else return 0;//hubo un empate
    }
    int v=-999999;
    int aux;
    for (int n=0;n<3;n++){
        for (int m=0;m<3;m++){
            if (tablero[n][m]==-1){
                tablero[n][m]=0;//pongo la ficha
                aux=min();//busco todos los valores que arroje min
                if (aux>v) v=aux;//los maximizo
            	tablero[n][m]=-1;//quito la ficha
                    
            }
        }
    }
    return v;//retorno el valor mas grande

}

int LaVieja::min(){
	//CASO BASE
    if (Terminal()){//si la partida termino
        if (evaluacion()!=0) return 10;//si la partida fue distinta de empate gana max ya que fue el ultimo en jugar
        else return 0;//hubo un empate
    }
    int v=999999;
    int aux;
    for (int n=0;n<3;n++){
  		for (int m=0;m<3;m++){
        	if (tablero[n][m]==-1){
            	tablero[n][m]=1;//pongo la ficha 
            	aux=max();//reviso todos los resultados que arroja max
            	if (aux<v) v=aux;//los minimizo
            	tablero[n][m]=-1;//quito la ficha
        	}
        }
    }
    return v;//retorno el mas bajo
}




bool LaVieja::tableroLLeno(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (tablero[i][j]==-1) return false;
		}
	}
	
	return true;
}

bool LaVieja::Terminal(){
	return evaluacion() !=0 || tableroLLeno();
}

void LaVieja::imprimir(){
	
	system ("cls");
	cout << "TE MUEVES CON W A S D PONES LA FICHA CON ESPACIO" << endl << endl << endl;
	for (int i = 0; i < 3; i++){
		
		for (int j = 0; j < 3; j++){
			cout<< "\t";
			if(tablero[i][j]==-1)
			cout << "*";
			else if(tablero[i][j]==1)
			cout << "X";
			else if (tablero[i][j]==0)
			cout << "O";
			else cout << tablero[i][j];		
		}
		cout << endl;
	}
	
}
void LaVieja::llenar(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			tablero[i][j]=-1;
		}
	}
}


void LaVieja::jugar(){
	
		char tecla;	
		int aux;
		
		int turno=0;
		
		
		aux = tablero[fi][co];
		tablero[fi][co]=2;
		imprimir();
		tablero[fi][co]=aux;
		
		
		while(!Terminal()){
			if(_kbhit()){
				tecla = getch();
				switch(tecla){
					case 'w':{
						if (fi-1>=0){
							fi--;
						}
						break;
					}
					case 'a':{
						if(co-1>=0){
							co--;
						}
						break;
					}
					case 's':{
						if(fi+1<3){
							fi++;
						}
						break;
					}
					case 'd':{
						if(co+1 < 3){
							co++;
						}
						break;
					}
					case ' ':{
						if(tablero[fi][co]==-1){
							tablero[fi][co]=1;
							imprimir();
							JuegaMaquina();
						}
						break;
					}
				}
			}
			Sleep(50);
		aux = tablero[fi][co];
		tablero[fi][co]=2;
		imprimir();
		tablero[fi][co]=aux;
			
	}
	
	switch (evaluacion()){
		case -10:{
			cout << endl << endl << "\t" << "perdiste";
			break;
		}
		case 10:{
			cout << endl << endl << "\t" << "ganaste";
			break;
		}
		case 0:{
			cout << endl << endl << "\t" << "empate";
			break;
		}
	}	
}


int LaVieja::evaluacion(){
	
	if (tablero[0][0] != -1 && tablero[0][0] == tablero[1][1]  && tablero[0][0] == tablero[2][2]){
		if(tablero[0][0]==1)
		return 10;
		else
		return -10;		
	}
        
    if (tablero[0][2] != -1 && tablero[0][2] == tablero[1][1]  && tablero[0][2] == tablero[2][0]){
    	if(tablero[0][2]==1)
		return 10;
		else
		return -10;
	}
        
    for (int n=0;n<3;n++){
        if (tablero[n][0] != -1 && tablero[n][0] == tablero[n][1] && tablero[n][0] == tablero[n][2]){
        	if(tablero[n][0]==1)
			return 10;
			else
			return -10;
		}
            
        if (tablero[0][n] != -1 && tablero[0][n] == tablero[1][n] && tablero[0][n] == tablero[2][n]){
        	if(tablero[0][n]==1)
			return 10;
			else
			return -10;
		}
            
    }
    return 0;
}



#endif
