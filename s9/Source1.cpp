#include<iostream>
using namespace std;

class Masina {

private:
	int nrCrt;
	char* model;
	bool manuala;
	float valoare;

public:

	Masina() {
		this->nrCrt = 1;
		this->model = new char[strlen("audi") + 1];
		strcpy(this->model, "audi");
		this->manuala = true;
		this->valoare = 32.1;
	}

	Masina(int nrCrtNou, char* modelNou, bool manualaNou, float valoareNou) {
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->manuala = manualaNou;
		this->valoare = valoareNou;
	}

	void afiseaza() {
		cout << this->nrCrt << " " << this->model << " " << this->manuala << " "
			<< this->valoare << endl;
	}

};

 int main(int n, char** args) {
	Masina* m1 = new Masina(10, "audi", false, 332.1);
	m1->afiseaza();

	int nrCrt = atoi(args[1]);
	char* model = args[2];
	bool manuala = (bool)atoi(args[3]);
	float valoare = atof(args[4]);

	Masina* m2 = new Masina(nrCrt, model, manuala, valoare);
	m2->afiseaza();

	return 0;
}