#include "Main.h"
#include "appUser.h"

using namespace std;

char appUser( produto ptr[], int tamVet, int *item,int *quant,int cesta) {
	char ch = 'A';
	
	cout << " Rapizinho" << endl
			<< "===========" << endl;
	if (cesta != 0) {
		for (int i = 0; i < cesta; i++) {
			cout << quant[i] << " "
				<< ptr[item[i]].nome << " de R$";
			cout << setprecision(2) << fixed
				<< ptr[item[i]].prec << " = R$";
			cout << setprecision(2) << fixed
				<< ptr[item[i]].prec * quant[i] << endl;
		}
		cout << "===========" << endl;
	}
	for (int i = 0; i< tamVet;i++){
		cout << "(" << ch << ") " << ptr[i].nome;
		if (ptr[i].quant == 0) {
			cout << "(INDISPONIVEL)";
		}
		cout << endl;
		ch++;
	}
	cout << "(S) Sair" << endl
		<< "===========" << endl
		<< "Opção: [_]\b\b";
	cin >> ch;
	return ch;
}
void Pedido(produto ptr[], int posicao, int *item, int *quant) {

	int retorno;
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
	}
	else {
		*item = posicao;
		*quant = retorno;
		ptr[posicao].quant -= retorno;
	}
}
bool Pagamento(produto ptr[], int tamVet, int* item, int* quant, int cesta) {
	int loop = 0;
	float total = 0, desconto;
	char ch;

	for (int i = 0; i < cesta; i++) {
		total += ptr[item[i]].prec * quant[i];
	}
	total += 6;

	do {
		cout << " Rapizinho" << endl
			<< "===========" << endl;
		for (int i = 0; i < cesta; i++) {
			cout << quant[i] << " "
				<< ptr[item[i]].nome << " de R$";
			cout << setprecision(2) << fixed
				<< ptr[item[i]].prec << " = R$";
			cout << setprecision(2) << fixed
				<< ptr[item[i]].prec * quant[i] << endl;
		}
		cout << "Taxa de entrega = R$6.00\n";
		if (loop != 0) {
			if (ch == 'P') {
				desconto = total * 0.10;
				cout << "Desconto de 10% = R$";
				cout << setprecision(2) << fixed << desconto << endl;
				total -= desconto;
			}
			else {
				desconto = total * 0.05;
				cout << "Desconto de 5% = R$";
				cout << setprecision(2) << fixed << desconto << endl;
				total -= desconto;
			}
				
			
		}
		cout << "===========\n";
		if (loop == 0) {
			cout << "Total = R$";
			cout << setprecision(2) << fixed << total;

			cout << "\n\n[P] Pix\n"
				<< "[C] Cartão\n\n"
				<< "Pagamento: [_]\b\b";
			cin >> ch;
			switch (ch)
			{
			case 'p':
			case 'P':
				ch = 'P';
				loop++;
				break;
			case 'c':
			case 'C':
				ch = 'C';
				loop++;
				break;
			default:
				erro(0);
				break;
			}
		}
		else {
			cout << "Total = R$";
			cout << setprecision(2) << fixed << total;

			cout << "\nConfirma Pedido (S/N): [_]\b\b";
			cin >> ch;
			loop++;
		}
		cls;
	} while (loop < 2);
	if (ch == 's' || ch == 'S') {
		return 1;
	}
	else return 0;
}