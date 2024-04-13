#include "Main.h"
#include "appUser.h"

using namespace std;

char appUser( produto ptr[], int tamVet,unsigned short pd) {
	char ch = 'A';
	
	cout << " Rapizinho" << endl
			<< "===========" << endl;
	if (pd != 0) {
		
	}
	for (int i = 0; i< tamVet;i++){
		cout << "(" << ch << ") " << ptr[i].nome << endl;
		ch++;
	}
	cout << "(S) Sair" << endl
		<< "===========" << endl
		<< "Opção: [_]\b\b";
	cin >> ch;
	return ch;
}
unsigned short Pedido(produto ptr[], int posicao) {
	//A lógica usada aqui foi de manter um int carregando 2 informações
	//A posição no vetor ( 8 Bits )
	//A quantidade de itens a serem pedidos ( 8 bits )
	//infelizmente não achei utilizada para os outros 16 bits

	unsigned short retorno,mid = posicao;
	mid = mid << 8;
	cout << "Pedido\n"
		<< "======\n"
		<< ptr[posicao].nome << endl
		<< "R$" << ptr[posicao].prec << endl
		<< "======" << endl
		<< "Quantidade: [_]\b\b";
	cin >> retorno;
	if (retorno > ptr[posicao].quant) {
		erro(1);
		cout << "Quantidade disponivel: "
			<< ptr[posicao].quant << endl;
		return 0;
	}
	else {
		retorno = retorno | mid;
		return retorno;
	}
	
}
void Pagamento() {

}
void Finalizar() {

}