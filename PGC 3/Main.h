#include <iostream>
#include <fstream>

//Definição de produtos
struct produto {
	char nome[25];
	float prec;
	unsigned int quant;
};

//facilitaçõe do código
#define cls system("cls")