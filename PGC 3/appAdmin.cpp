#include "Main.h"
#include "appAdmin.h"

using namespace std;


//Retorna o modo de  operação de admin
char appAdmin(produto ptr[],int tamVet) {
	char ch;
	cout << " Painel de Controle\n"
		<< " ===================\n"
		<< " (A)dicionar\n"
		<< " (E)xcluir\n"
		<< " (L)istar\n"
		<< " (S)air\n"
		<< " ===================\n"
		<< " Opção: [_]\b\b";
	cin >> ch;
	return ch;
}

//Adiciona valor do ponteiro
void Adicionar(produto p[], int tan) {
	Listar(p, tan);
	cin.get();
	cout << "Adicionar\n"
		<< "--------\n";
	cout << "Nome: ";
	cin.getline(p[tan].nome,25);
	cout << "Preço: ";
	cin >> p[tan].prec;
	cout << "Quantidade: ";
	cin >> p[tan].quant;
}

//Exclui valor do ponteiro
void Excluir(produto p[],int tam) {
	Listar(p, tam);
	int escolha;
	char confirmar;
	cout << "Listagem\n"
		<< "--------\n";
	for (int i = 0; i < tam; i++) {
		cout << i + 1 << ") " << p[i].nome << endl;
	}
	cout << "\nProduto: [_]\b\b";
	cin >> escolha;
	escolha -= 1;
	cout << "Deseja excluir \"" << p[escolha].nome << "\" (S/N)? ";
	cin >> confirmar;
	if (confirmar == 's' || confirmar =='S') {
		if (escolha < tam - 1) {
			for (int i = 0; i < 25; i++) {
				p[escolha].nome[i] = p[tam - 1].nome[i];
				if (p[escolha].nome[i] == '\0') {
					i = 24;
				}
			}
			p[escolha].prec = p[tam - 1].prec;
			p[escolha].quant = p[tam - 1].quant;
		}
	}
}

//Mostra os produtos do estoque
void Listar(produto ptr[],int tamVet) {
	cout << "Listagem\n" 
		<< "--------\n";
	for (int i = 0; i < tamVet; i++) {
		cout.width(8); cout.fill(' '); cout << left << ptr[i].nome;
		cout << "- R$" << setprecision(2) << fixed << ptr[i].prec << " - ";
		cout.width(2); cout.fill(' '); cout << right << ptr[i].quant << " und." << endl;
	}
}