#include <iostream>
#include <fstream>
using namespace std;

struct produto{
	char nome[25];
	double prec;
	unsigned int quant;
};

ifstream fin;
ofstream fout;


int main() {
	produto p;
	int tamVet = 0;
	char controle = 'A';
	fin.open("estoque.bin",ios_base::in,ios_base::binary);
	if(fin.is_open()){
		cout << " Rapizinho"
			<< "===========";
		while (fin.read((char*)&p, sizeof(produto))) {
			cout << "(" << controle << ")"
				<< p.nome << endl;
			controle++;
		}
		cout << "(S)" << "Sair";
		controle = 'A';
		fin.close();
		cout << endl;
	}
	else {
		cout << "Arquivo não encontrado...";
		system("pause");
		fout.open("estoque.bin", ios_base::binary);
		fout.close();
	}
	cout << "Nome: ";
	cin >> p.nome;
	cout << "Preço: ";
	cin >> p.prec;
	cout << "Quantidade: ";
	cin >> p.quant;
	
	fout.open("estoque.bin", ios_base::out | ios_base::app | ios_base::binary);
	fout.write((char*)&p, sizeof(p));
	fout.close();
}