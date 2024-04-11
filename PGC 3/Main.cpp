#include "Main.h"
#include "appUser.h"
#include "appAdmin.h"

using namespace std;
char modoExecucao();


ifstream fin;
ofstream fout;

//A main se divide em 2 execuções de programa:

//Caso opção 1: Usuario, o programa estara apto a fazer um pedido

//Caso opção 2: Admin, o programa estara apto a modificar informações de estoque


int main() {
	//Habiitando caracteres com acento!
	system("chcp 1252");
	cls;

	//definição de variaves comuns

	int tamVet; //tamanho do vetor estoque.bin, também usado para verificar Usuario ou Admin
	int cont = 0; //contagem padrão, utilizado para loops
	char ch='A';

	produto p; //Struct generica de leitura/escrita 

	//---------------------------------
	//Abertura de Estoque.bin
	//---------------------------------

	fin.open("estoque.bin", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		fout.open("estoque.bin", ios_base::out | ios_base::binary | ios_base::app);
		cin >> tamVet;
		fout.write((char*)&tamVet, sizeof(int));
		fout.close();
		while (cont < tamVet) {
			fout.open("estoque.bin", ios_base::binary | ios_base::out | ios_base::app);
			
			cin >> p.nome >> p.prec >> p.quant;

			fout.write((char*)&p, sizeof(produto));
			fout.close();
			cont++;
		}
		cont = 0;
		fout.close();
	}
	fin.read((char*)&tamVet, sizeof(int));
	
	produto * ptr = new produto[tamVet];

	for(int i = 0; fin.read((char*)&ptr[i], sizeof(produto)); i++) {
	}

	//---------------------------------
	//Escolha do modo de operação
	//---------------------------------

	if (modoExecucao() == 'U') {
		cls;
		cout << " Rapizinho" << endl
			<< "===========" << endl;
		while (cont < tamVet) {
			cout << "(" << ch << ") " << ptr[cont].nome << endl;
			cont++;
			ch++;
		}
		cont = 0;
		cout << "(S) Sair" << endl
			<< "===========" << endl
			<< "Opção: [_]\b\b";
		cin>> ch;
	}
	else {

	}




}

char modoExecucao() {
	char retorno;
	cout << "Bem - Vindo\n"
		<< "Rapizinho iniciando....\n";

	system("pause"); system("cls");

	cout << "Qual o modo atual de operação?\n"
		<< "-----------\n"
		<< "(U)suario\n(A)dmin\n"
		<< "-----------\n\n"
		<< "Opção: [_]\b\b";
	cin.get(retorno);
	switch (retorno) {
	case 'A':
	case 'a':
		retorno = 'A';
		break;
	case 'U':
	case 'u':
		retorno = 'U';
		break;
	}
	return retorno;
}