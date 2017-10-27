#include <iostream>

using namespace std;

class Masina {
private:
	int nrCrt;
	char* model;
	float valoare;
	bool manuala;

public:
	Masina() {
		cout << "Hello constructor!";
		this->nrCrt = 1;
		
		this->model = new char[strlen("audi") + 1];//"audi";
		strcpy(this->model, "audi");
		this->valoare = 100.3;
		this->manuala = true;
	}

	Masina(int nrCrtNou, char* modelNou, float valoareNou,
		bool manualaNou) {
		this->nrCrt = nrCrtNou;
		//this->model = modelNou; 1. alocarea memoriei 2. copiem variabila
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->valoare = valoareNou;
		this->manuala = manualaNou;
	}

	Masina(int nrCrtNou, char* modelNou, float valoareNou) {
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->valoare = valoareNou;
		this->manuala = true;
	}

	~Masina() {
		cout << "Hello destructor !";
		if (this->model != NULL) {
			delete[] this->model;
		}
	}

	int getNrCrt() {
		return this->nrCrt;
	}

	void setNrCrt(int nrCrtNou) {
		this->nrCrt = nrCrtNou;
	}

	char* getModel() {
		return this->model;
	}

	float getValoare() {
		return this->valoare;
	}

	void setValoare(float valoareNoua) {
		this->valoare = valoareNoua;
	}

	void setModel(char* modelNou) {
		if (modelNou != NULL) {
			this->model = new char[strlen(modelNou) + 1];
			strcpy(this->model, modelNou);
		}
	}
	bool isManuala() {
		return this->manuala;
	}

	void afiseaza() {
		cout << "NrCrt: " << this->nrCrt << " Model : " << this->model
			<< " Valoare : " << this->valoare << " Este manuala? "<<
			(this->manuala?"da":"nu") <<endl;
	}

};

int main() {
	Masina m1;
	m1.afiseaza();

	char* model = new char[strlen("kia") + 1];
	strcpy(model, "kia");

	Masina m2(1, model, 98.3, false);
	m2.afiseaza();
	model[1] = 'x';
	m2.afiseaza();

	Masina m3(1, "myModel", 8754.3);
	m3.afiseaza();

	return 0;
}
