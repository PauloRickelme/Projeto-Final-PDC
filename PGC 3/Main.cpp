#include "Main.h"
#include "appUser.h"
#include "appAdmin.h"

using namespace std;

ifstream fin;
ofstream fout;


int main() {
	//Habiitando caracteres com acento!
	system("chcp 1252");
	cls;

	// Variaveis Comuns

	int tamVet; // Tamanho do vetor estoque.bin, também usado para verificar Usuario ou Admin
	char ch='A';

	produto p; // Struct generica para criação de possivel arquivo binario

	//---------------------------------
	// Verificação de Estoque.bin
	//---------------------------------

	fin.open("estoque.bin", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		fout.open("estoque.bin", ios_base::out | ios_base::binary | ios_base::app);
		cout << "Numero de produtos: ";
		cin >> tamVet;
		fout.write((char*)&tamVet, sizeof(int));
		fout.close();
		cls;
		for (int i = 0; i < tamVet;i++) {
			fout.open("estoque.bin", ios_base::binary | ios_base::out | ios_base::app);
			cout << "\nNome: ";
			cin >> p.nome;
			cout << "Preço: ";
			cin >> p.prec;
			cout << "Quantidade: ";
			cin >> p.quant;

			fout.write((char*)&p, sizeof(produto));
			fout.close();
		}
		fout.close();
	}

	//---------------------------------
	// Leitura de Estoque.bin
	// Criação de Vetor de Produtos
	//---------------------------------

	fin.read((char*)&tamVet, sizeof(int));
	
	produto * ptr = new produto[tamVet];

	for(int i = 0; fin.read((char*)&ptr[i], sizeof(produto)); i++) {
	}

	//---------------------------------
	// Escolha do modo de operação
	//---------------------------------

	ch = modoExecucao();
	switch (ch) {
	case 'A':
	case 'a':
		ch = 'A';
		break;
	case 'U':
	case 'u':
		ch = 'U';
	}

	//---------------------------------
	// Execução de Usuario
	//---------------------------------
	if (ch == 'U'){
		produto* pedidoAtual = new produto[tamVet];
		int escolha;
		unsigned short pedido=0;
		while (ch != 'S' && ch != 's') {
			ch = appUser(ptr, tamVet, pedido);
			escolha = getInt(ch);
			if (escolha > tamVet && ch !='S' && ch != 's') {
				erro(0);
			}
			else if(ch != 'S' && ch != 's'){
				cls;
				pedido = Pedido(ptr,escolha);
			}
			else {

			}
			pause; cls;
		}

	}
	//---------------------------------
	// Execução de Admin
	//---------------------------------
	else {
		while (ch != 'S' && ch != 's') {
			ch = appAdmin(ptr, tamVet);
			switch (ch) {
			case 'A':
			case 'a':
				break;
			case 'E':
			case 'e':
				break;
			case 'L':
			case 'l':
				Listar(ptr, tamVet);
				break;
			case 'S':
			case 's':
				break;
			default:
				erro(0);
				pause;
			}
			pause; cls;
		}
	}
	cout << "---------------------------------------"
		<< "\n\033[32mObrigado por ter acessado meu programa!\033[0m\n"
		<< "---------------------------------------";
}

char modoExecucao() {
	char retorno = '.';
	cout << "Bem - Vindo\n"
		<< "Rapizinho iniciando....\n";

	pause; cls;
	do{
		if (retorno != '.') {
			erro(0);
			pause; cls;
		}

		cout << "Qual o modo atual de operação?\n"
			<< "-----------\n"
			<< "(U)suario\n(A)dmin\n"
			<< "-----------\n\n"
			<< "Opção: [_]\b\b";
		cin >> retorno; 

		switch (retorno) {
		case 'A':
		case 'a':
			retorno = 'A';
			break;
		case 'U':
		case 'u':
			retorno = 'U';
			break;
		default:
			retorno = '.';
	}
	} while (retorno != 'A' && retorno != 'U');
	cls;
	return retorno;
}
unsigned short getInt(char ch) {
	unsigned short retorno = 0;
	char loop;
	for (int i = 65; i < 123;i++) {
		loop = i;
		if (ch == loop) {
			retorno = i;
			if (retorno < 91 && retorno > 64) {
				retorno -= 65;
				i = 122;
			}
			else if (retorno < 123 && retorno > 96) {
				retorno -= 97;
				i = 122;
			}
			else {
				retorno = 0;
				i = 122;
			}
		}
	}
	return retorno;
}

void erro(int a) {
	if (a == 0) {
		cout << "\033[41m"	
			<< "\n Erro! Entrada inválida! \n"
			<< "\033[0m\n";
	}
	else if(a == 1){
		cout << "\033[41m"
			<< "\n Erro! Quantidade invalida! \n"
			<< "\033[0m\n";
	}
	
}