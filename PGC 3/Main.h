#include <iostream>
#include <fstream>
#include <iomanip> 

//Defini��o de produtos
struct produto {
	char nome[25];
	float prec;
	unsigned int quant;
};

//Declara��o de Fun��es Main
char modoExecucao();
unsigned short getInt(char);
void erro(int);

//facilita��e do c�digo
//limpar tela

#define cls system("cls")
#define pause system("pause")
