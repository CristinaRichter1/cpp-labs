#include <iostream>
using namespace std;

class Bicicleta {
private:
	int nrCrt;
	float valoare;

public:
	Bicicleta(int nrCrtNou, float valoareNou) {
		this->nrCrt = nrCrtNou;
		this->valoare = valoareNou;
	}
};

class Masina {
private:
	int nrCrt;
	char* model = NULL;
	float valoare;
	bool manuala;
public:
	Masina() {
		this->nrCrt = 1;
		this->model = new char[strlen("default") + 1];
		strcpy(this->model, "default");
		this->valoare = 100;
		this->manuala = false;
	}

	Masina(int nrCrtNou, char* modelNou, float valoareNou,
		bool manualaNou) {
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->valoare = valoareNou;
		this->manuala = manualaNou;
	}
	
	Masina(Masina& m) {
		this->nrCrt = m.nrCrt;

		if (this != NULL) {
			delete this->model;
		}

		this->model = new char[strlen(m.model) + 1];
		strcpy(this->model, m.model);
		this->valoare = m.valoare;
		this->manuala = m.manuala;
	}

	Masina& operator ++() {
		cout << "++Masina";
		this->valoare ++;
		return *this;
	}

	Masina operator++(int x) {
		cout << "Masina++";
		Masina m(*this);
		this->valoare++;
		return m;
	}

	float getValoare() {
		return this->valoare;
	}

	bool operator <=(int i) {
		if (this->valoare <= i) {
			return true;
		}
		else {
			return false;
		}
	}

	operator int() {
		return this->valoare;
	}

	operator bool() {
		return this->manuala;
	}

	operator Bicicleta() {
		Bicicleta b(this->nrCrt, this->valoare);
		return b;
	}

	bool operator!() {
		return !this->manuala;
	}
};


int main() {
	cout << "hello";

	int x = 150;
	cout << ++x;
	cout << x++;

	Masina m1;
	++m1;
	m1++;

	cout << m1.getValoare();

	if (m1 <= x) {
		cout << "m1 <= x";
	}
	else {
		cout << "m1 > x";
	}

	int k = m1;
	int j = (int)m1;

	cout <<endl << "j = " << j << " k " << k;

	Bicicleta myB = m1;

	bool notManuala = !m1;

	cout << endl << notManuala;



	return 0;
}