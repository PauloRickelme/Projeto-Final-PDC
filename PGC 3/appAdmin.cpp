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

void Adicionar() {

}
void Excluir() {

}
void Listar(produto ptr[],int tamVet) {
	cout << "Listagem\n" 
		<< "--------\n";
	for (int i = 0; i < tamVet; i++) {
		cout << ptr[i].nome;
		cout.left; cout.width(10); cout << "- R$" << ptr[i].prec;
		cout.left; cout.width(4); cout << "- " << ptr[i].quant << "und."<< endl;
	}
}