#include <iostream>
#include <fstream>
#include <iomanip> 

//Definição de produtos
struct produto {
	char nome[25];
	float prec;
	unsigned int quant;
};

//Declaração de Funções Main
char modoExecucao();
unsigned short getInt(char);
void erro(int);

//facilitaçõe do código
//limpar tela

#define cls system("cls")
#define pause system("pause")
