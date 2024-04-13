#include <iostream>
#include <fstream>

//Definição de produtos
struct produto {
	char nome[25];
	float prec;
	unsigned int quant;
};

//Declaração de Funções
char modoExecucao();
unsigned short getInt(char);
void erro(int);

//facilitaçõe do código
//limpar tela

#define cls system("cls")
#define pause system("pause")

//Cores
#define vermelho 31
#define verde 32
#define  semCor 0