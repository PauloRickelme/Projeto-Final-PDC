#include <iostream>
#include <fstream>

//Defini��o de produtos
struct produto {
	char nome[25];
	float prec;
	unsigned int quant;
};

//Declara��o de Fun��es
char modoExecucao();
unsigned short getInt(char);
void erro(int);

//facilita��e do c�digo
//limpar tela

#define cls system("cls")
#define pause system("pause")

//Cores
#define vermelho 31
#define verde 32
#define  semCor 0