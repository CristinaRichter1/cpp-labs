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
		cout <<endl << "constructor";
		this->model = NULL;
	}

	Masina(int nrCrtNou, char* modelNou, float valoareNou,
		bool manualaNou) {
		cout << endl << "constructor";
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->valoare = valoareNou;
		this->manuala = manualaNou;
	}

	Masina(int nrCrtNou, char* modelNou, float valoareNou) {
		cout << endl << "constructor";
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->valoare = valoareNou;
		this->manuala = true;
	}

	void afiseaza() {
		cout << "nrCrt : " << this->nrCrt << " model : " << this->model
			<< " valoare : " << this->valoare << " manuala ? "
			<< (this->manuala ? "da" : "nu");
	}

	~Masina() {
		cout << endl << "destructor";
		if (this->model != NULL) {
			delete[] this->model;
		}
	}

	Masina(Masina& m) {
		this->nrCrt = m.nrCrt;
		this->model = new char[strlen(m.model) + 1];
		strcpy(this->model, m.model);
		this->valoare = m.valoare;
		this->manuala = m.manuala;
	}

	void operator=(Masina& m) {
		this->nrCrt = m.nrCrt;
		this->model = new char[strlen(m.model) + 1];
		strcpy(this->model, m.model);
		this->valoare = m.valoare;
		this->manuala = m.manuala;
	}

	void setNrCrt(int nrCrtNou) {
		this->nrCrt = nrCrtNou;
	}

	void setModel(char* modelNou) {
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
	}

	void setValoare(float valoareNou) {
		this->valoare = valoareNou;
	}

	void setManuala(bool manualaNou) {
		this->manuala = manualaNou;
	}

	float operator+(Masina& m) {
		return this->valoare + m.valoare;
	}

	Masina operator-(Masina& m) {
		Masina result;
		result.setNrCrt(this->nrCrt - m.nrCrt);
		result.setModel(m.model);
		result.setValoare(this->valoare - m.valoare);
		result.setManuala(m.manuala);

		return result;
	}
};

int main() {
	//Masina m1;
	Masina m2(1, "audi", 32.1, false);
	Masina m3(3, "bmw", 312.4);

	Masina m4;
	m4 = m2; // m4 = Masina(m2);
	
	m4.afiseaza();
	m2.afiseaza();

	float valoareTotala = m2 + m3;
	cout << endl << "ValoareTotala :" << valoareTotala;

	Masina m5 = m4 - m3;
	m5.afiseaza();


}