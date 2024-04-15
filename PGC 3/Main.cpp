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

	int tamVet; // Tamanho do vetor estoque.bin, tamb�m usado para verificar Usuario ou Admin
	char ch='A';

	produto p; // Struct generica para cria��o de possivel arquivo binario

	//---------------------------------
	// Verifica��o de Estoque.bin
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
			cout << "Pre�o: ";
			cin >> p.prec;
			cout << "Quantidade: ";
			cin >> p.quant;

			fout.write((char*)&p, sizeof(produto));
			fout.close();
		}
	}

	//---------------------------------
	// Leitura de Estoque.bin
	// Cria��o de Vetor de Produtos
	//---------------------------------

	fin.read((char*)&tamVet, sizeof(int));
	
	produto * ptr = new produto[tamVet];

	for(int i = 0; fin.read((char*)&ptr[i], sizeof(produto)); i++) {
	}

	fin.close();
	//---------------------------------
	// Escolha do modo de opera��o
	//---------------------------------

	ch = modoExecucao();
	switch (ch) {
	case 'a':
		ch = 'A';
		break;
	case 'u':
		ch = 'U';
	}

	//---------------------------------
	// Execu��o de Usuario
	//---------------------------------
	if (ch == 'U'){
		const int a = tamVet;
		int escolha, itemPedido[10] = { 0 }, itemQuantidade[10] = {0}, cesta = 0;

		while (ch != 'S' && ch != 's') {
			ch = appUser(ptr,tamVet,&itemPedido[0], &itemQuantidade[0], cesta);
			escolha = getInt(ch);
			if (escolha > tamVet && ch !='S' && ch != 's') {
				erro(0);
			}
			else if(ch != 'S' && ch != 's'){
				cls;
				Pedido(ptr,escolha,&itemPedido[cesta], &itemQuantidade[cesta]);
				cesta++;
			}
			else {
				cls;
				Pagamento(ptr, tamVet, &itemPedido[0], &itemQuantidade[0], cesta);
				cout << "---------------------------------------"
					<< "\n\033[32mObrigado por ter acessado meu programa!\033[0m\n"
					<< "---------------------------------------\n";
				pause;
			}
			cls;
		}

	}
	//---------------------------------
	// Execu��o de Admin
	//---------------------------------
	else {
		while (ch != 'S' && ch != 's') {
			ch = appAdmin(ptr, tamVet);
			switch (ch) {
			case 'A':
			case 'a':
				cls;
				Adicionar(ptr, tamVet);
				pause; cls;
				break;
			case 'E':
			case 'e':
				cls;
				Excluir(ptr, tamVet);
				pause; cls;
				break;
			case 'L':
			case 'l':
				cls;
				Listar(ptr, tamVet);
				pause; cls;
				break;
			case 'S':
			case 's':
				cls;
				break;
			default:
				erro(0);
				pause;
			}
		}
	}
	delete ptr;
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

		cout << "Qual o modo atual de opera��o?\n"
			<< "-----------\n"
			<< "(U)suario\n(A)dmin\n"
			<< "-----------\n\n"
			<< "Op��o: [_]\b\b";
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
			<< "\n Erro! Entrada inv�lida! \n"
			<< "\033[0m\n";
	}
	else if(a == 1){
		cout << "\033[41m"
			<< "\n Erro! Quantidade invalida! \n"
			<< "\033[0m\n";
	}
	
}