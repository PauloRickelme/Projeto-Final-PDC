#include <iostream>
#include <fstream>

//Defini��o de produtos
struct produto {
	char nome[25];
	float prec;
	unsigned int quant;
};

//facilita��e do c�digo
#define cls system("cls")