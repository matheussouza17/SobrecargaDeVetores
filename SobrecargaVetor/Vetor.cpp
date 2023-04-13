#include "Vetor.h"


Vetor::Vetor(int tamanho)
{
	Size = (tamanho > 0 ? tamanho : 10);
	ptr = new int[Size];
	for (int i = 0; i < Size; i++)
		ptr[i] = 0;
}

Vetor::Vetor(const Vetor& origem) : Size(origem.Size)//size=origem.size; construtor por cópia
{
	ptr = new int[Size];
	for (int i = 0; i < Size; i++)
		ptr[i] = origem.ptr[i];

}

Vetor::~Vetor()
{
	delete ptr;
}

int Vetor::getSize()
{
	return Size;
}

const Vetor& Vetor::operator=(const Vetor& direita)
{
	// TODO: inserir instrução return aqui
	if (&direita != this) {
		if (Size != direita.Size) {
			delete ptr;
			Size = direita.Size;
			ptr = new int[Size];
			for (int i = 0; i < Size; i++)
				ptr[i] = direita.ptr[i];
		}
	}
	return *this;
}

bool Vetor::operator==(const Vetor& direita)
{
	if (Size != direita.Size)
		return false;

	for (int i = 0; i < Size; i++)
		if (ptr != direita.ptr)
			return false;
	return true;
}

bool Vetor::operator!=(const Vetor& direita)
{
	return !(*this == direita);
}

int& Vetor::operator[](int indice)
{
	// TODO: inserir instrução return aqui
	if (indice < 0 || indice >= Size) {
		cerr << "Erro: indice " << indice << "fora dos limites.";
		exit(1);
	}
	return ptr[indice];
}

Vetor Vetor::operator+(const Vetor& direita)const {
	if (Size != direita.Size) {
		cerr << "Erro: vetores de tamanhos diferentes." << endl;
		exit(1);
	}
	Vetor resultado(Size);
	for (int i = 0; i < Size; i++) {
		resultado.ptr[i] = this->ptr[i] + direita.ptr[i];
	}
	return resultado;
}

Vetor Vetor::operator-(const Vetor& direita)const {
	if (Size != direita.Size) {
		cerr << "Erro: vetores de tamanhos diferentes." << endl;
		exit(1);
	}
	Vetor resultado(Size);
	for (int i = 0; i < Size; i++) {
		resultado.ptr[i] = this->ptr[i] - direita.ptr[i];
	}
	return resultado;
}

double Vetor::operator*(const Vetor& direita)const {
	if (Size != direita.Size) {
		cerr << "Erro: vetores de tamanhos diferentes." << endl;
		exit(1);
	}
	double valor = 0;
	for (int i = 0; i < Size; i++) {
		valor += this->ptr[i] * direita.ptr[i];
	}
	return valor;
}



ostream& operator<<(ostream& saida, const Vetor& vet)
{
	// TODO: inserir instrução return aqui
	saida << "{ ";
	for (int i = 0; i < vet.Size; i++) {
		saida << *(vet.ptr + i) << " ";
	}
	saida << "}";
	return saida;

}

istream& operator>>(istream& leitura, const Vetor& vet)
{
	// TODO: inserir instrução return aqui
	for (int i = 0; i < vet.Size; i++) {
		leitura >> *(vet.ptr + i);
	}
	return leitura;
}