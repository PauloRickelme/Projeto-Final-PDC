#include "Main.h"
#include "appAdmin.h"

using namespace std;

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

void Adicionar(produto p[], int tan) {
	produto novo;
	cout << "Adicionar\n"
		<< "--------\n";
	cout << "Nome: ";
	cin >> novo.nome;
	cout << "Preço: ";
	cin >> novo.prec;
	cout << "Quantidade: ";
	cin >> novo.quant;
}
void Excluir(produto p[], int tam) {
	int escolha;
	char confirmar;
	cout << "Listagem\n"
		<< "--------\n";
	for (int i = 0; i < tam; i++) {
		cout << i + 1 << ") " << p[i].nome << endl;
	}
	cout << "\nProduto: [_]\b\b";
	cin >> escolha;
	cout << "Deseja excluir \"" << p[escolha - 1].nome << "\" (S/N)? ";
	cin >>confirmar;
}
void Listar(produto ptr[],int tamVet) {
	cout << "Listagem\n" 
		<< "--------\n";
	for (int i = 0; i < tamVet; i++) {
		cout.width(8); cout.fill(' '); cout << left << ptr[i].nome;
		cout << "- R$" << setprecision(2) << fixed << ptr[i].prec << " - ";
		cout.width(2); cout.fill(' '); cout << right << ptr[i].quant << " und." << endl;
	}
}