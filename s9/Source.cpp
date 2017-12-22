#include<iostream>
using namespace std;

class Masina {

private:
	int nrCrt;
	char* model = NULL;
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
		cout << "Masina cont";
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->manuala = manualaNou;
		this->valoare = valoareNou;
	}

	Masina(Masina& m) {
		cout << "Masina copy";
		this->nrCrt = m.nrCrt;
		this->model = new char[strlen(m.model) + 1];
		strcpy(this->model, m.model);
		this->manuala = m.manuala;
		this->valoare = m.valoare;
	}

	void afiseaza() {
		cout << this->nrCrt << " " << this->model << " " << this->manuala << " "
			<< this->valoare << endl;
	}

	~Masina() {
		cout << "Destructor Masina";
		if (this->model != NULL) {
			delete[] model;
		}
	}

};


class MasinaSport : public Masina {
private:
	char* categorie = NULL;
	int caiPutere;

public:

	MasinaSport() : Masina() {
		this->categorie = new char[strlen("super-sport") + 1];
		strcpy(this->categorie, "super-sport");
		this->caiPutere = 600;
	}

	MasinaSport(int nrCrtNou, char* modelNou, bool manualaNou, float valoareNou,
		char* categorieNou, int caiPutereNou): Masina(nrCrtNou, modelNou, modelNou, valoareNou) {
		cout << "MasinaSport const";
		this->categorie = new char[strlen(categorieNou) + 1];
		strcpy(this->categorie, categorieNou);
		this->caiPutere = caiPutereNou;
	}

	MasinaSport(MasinaSport& ms) {
		Masina::Masina(ms);
		cout << "const MasinaSport";

		this->categorie = new char[strlen(ms.categorie) + 1];
		strcpy(this->categorie, ms.categorie);

		this->caiPutere = ms.caiPutere;

	}

	void afiseaza() {
		Masina::afiseaza();
		cout << " categorie " << this->categorie << " cai putere " << this->caiPutere;
	}

	~MasinaSport() {
		cout << "Destructor MasinaSport";
		if (this->categorie != NULL) {
			delete[] categorie;
		}
	}

};

int main2() {
	Masina* m1 = new Masina(10, "audi", false, 332.1);
	m1->afiseaza();
	
	MasinaSport* m2 = new MasinaSport(100, "bmw", true, 22.1, "sport", 400);
	m2->afiseaza();
	cout << endl;

	MasinaSport* m3 = m2;
	m3->afiseaza();

	return 0;
} 