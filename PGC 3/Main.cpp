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
	char ch = 'A';

	produto* ptr = nullptr; //Vetor principal


	//---------------------------------
	// Verificação de Estoque.bin
	//---------------------------------

	fin.open("estoque.bin", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		//Cria o arquivo de estoque
		fout.open("estoque.bin", ios_base::out | ios_base::binary | ios_base::app);
		fout.close();
	}
	else {
		//---------------------------------
		// Leitura de Estoque.bin
		// Criação de Vetor de Produtos
		//---------------------------------

		fin.read((char*)&tamVet, sizeof(int));

		ptr = new produto[tamVet];

		//Criando vetor de produtos 
		//Lendo produtos do estoque
		for (int i = 0; fin.read((char*)&ptr[i], sizeof(produto)); i++) {
		}

	}
	fin.close();

	//---------------------------------
	// Leitura de Estoque.bin
	// Criação de Vetor de Produtos
	//---------------------------------

	fin.open("estoque.bin", ios_base::in | ios_base::binary);

	fin.read((char*)&tamVet, sizeof(int));

	//Criando vetor de produtos 
	//Lendo produtos do estoque
	for(int i = 0; fin.read((char*)&ptr[i], sizeof(produto)); i++) {
	}

	fin.close();
	//---------------------------------
	// Escolha do modo de operação
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
	// Execução de Usuario
	//---------------------------------
	if (ch == 'U'){
		//Varaivieis:
		int escolha; //Int que sera obtido ao transformar o char do usuario
		int itemPedido[10] = { 0 }; //Guarda qual o item necessario no pedido
		int itemQuantidade[10] = { 0 }; //Guarda a quantidade necessaria no pedido
		int cesta = 0; //guarda o numero atual de produtos adicionados

		while (ch != 'S' && ch != 's') {
			ch = appUser(ptr,tamVet,&itemPedido[0], &itemQuantidade[0], cesta);
			escolha = getInt(ch);
			if (escolha > tamVet && ch !='S' && ch != 's') {
				erro(0);
			}
			else if(ch != 'S' && ch != 's'){
				cls;
				if (Pedido(ptr, escolha, &itemPedido[cesta], &itemQuantidade[cesta])) {
					cesta++;
				}
				
			}
			else {
				cls;
				Pagamento(ptr, tamVet, &itemPedido[0], &itemQuantidade[0], cesta);
				cout << "---------------------------------------"
					<< "\n\033[32mObrigado por ter acessado meu programa!\033[0m\n"
					<< "---------------------------------------\n";
				pause;
			}
			char estoque[] = "Pedido_"  ".txt";
			cls;
		}

		fout.open("estoque.bin", ios_base::trunc | ios_base::in | ios_base::binary);
		fout.write((char*)&tamVet, sizeof(int));
		for (int i = 0; i < tamVet; i++) {
			fout.write((char*)&ptr[i], sizeof(produto));
		}
		fout.close();

		delete[] ptr;
	}
	//---------------------------------
	// Execução de Admin
	//---------------------------------
	else {
		produto* ptrNovo = new produto[tamVet];
		while (ch != 'S' && ch != 's') {
			ch = appAdmin(ptr, tamVet);
			switch (ch) {
			case 'A':
			case 'a':

				cls;
				
				delete[]ptrNovo;
				ptrNovo = new produto[tamVet+1];
				for (int i = 0; i < tamVet; i++) {
					for (int j = 0; j < 25; j++) {
						ptrNovo[i].nome[j] = ptr[i].nome[j];
						if (ptrNovo[i].nome[j] >=65 || ptrNovo[i].nome[j] <=90) {	
						}
						else if (ptrNovo[i].nome[j] >= 97 || ptrNovo[i].nome[j] <= 122) {
						}
						else {
							ptrNovo[i].nome[j] = '\0';
							i = 24;
						}

					}
					ptrNovo[i].prec = ptr[i].prec;
					ptrNovo[i].quant = ptr[i].quant;
				}
				ptr = new produto[tamVet+1];

				Adicionar(ptrNovo, tamVet);
				tamVet += 1;

				for (int i = 0; i < tamVet; i++) {
					for (int j = 0; j < 25; j++) {
						ptr[i].nome[j] = ptrNovo[i].nome[j];
						if (ptr[i].nome[j] >= 65 || ptr[i].nome[j] <= 90) {
						}
						else if (ptr[i].nome[j] >= 97 || ptr[i].nome[j] <= 122) {
						}
						else {
							ptr[i].nome[j] = '\0';
							i = 24;
						}
					}
					ptr[i].prec = ptrNovo[i].prec;
					ptr[i].quant = ptrNovo[i].quant;
				}
				
				cls;
				break;

			case 'E':
			case 'e':

				cls;

				delete[]ptrNovo;
				ptrNovo = new produto[tamVet-1];
				Excluir(ptr, tamVet);
				tamVet -= 1;

				for (int i = 0; i < tamVet; i++) {
					for (int j = 0; j < 25; j++) {
						ptrNovo[i].nome[j] = ptr[i].nome[j];
						if (ptrNovo[i].nome[j] >= 65 || ptrNovo[i].nome[j] <= 90) {
						}
						else if (ptrNovo[i].nome[j] >= 97 || ptrNovo[i].nome[j] <= 122) {
						}
						else {
							ptrNovo[i].nome[j] = '\0';
							i = 24;
						}

					}
					ptrNovo[i].prec = ptr[i].prec;
					ptrNovo[i].quant = ptr[i].quant;
				}
				delete[]ptr;
				ptr = new produto[tamVet];
				
				for (int i = 0; i < tamVet; i++) {
					for (int j = 0; j < 25; j++) {
						ptr[i].nome[j] = ptrNovo[i].nome[j];
						if (ptr[i].nome[j] >= 65 || ptr[i].nome[j] <= 90) {
						}
						else if (ptr[i].nome[j] >= 97 || ptr[i].nome[j] <= 122) {
						}
						else {
							ptr[i].nome[j] = '\0';
							i = 24;
						}
					}
					ptr[i].prec = ptrNovo[i].prec;
					ptr[i].quant = ptrNovo[i].quant;
				}

				cls;

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
		delete[] ptrNovo;
		cout << "---------------------------------------"
			<< "\n\033[32mObrigado por ter acessado meu programa!\033[0m\n"
			<< "---------------------------------------\n";
		pause; cls;

		fout.open("estoque.bin", ios_base::trunc | ios_base::in | ios_base::binary);
		fout.write((char*)&tamVet, sizeof(int));
		for (int i = 0; i < tamVet; i++) {
			fout.write((char*)&ptr[i], sizeof(produto));
		}
		fout.close();

		delete[] ptr;
	}
}


//Mensagem de confirmação de modo de execução
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
	}
	} while (retorno != 'A' && retorno != 'U');
	cls;
	return retorno;
}

//Recebe um caractere qualquer
//e retorna o endereço do vetor a acessar
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

//Mensagem de erro
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