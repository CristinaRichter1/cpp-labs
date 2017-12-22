#include <iostream>
#include <fstream>
using namespace std;

class Masina {
public:
	int nrCrt;
	char* model;
	bool manuala;
	float valoare;
	int nrComponente;
	int* componente;

public:
	Masina() {
		this->nrCrt = 0;
		this->model = new char[strlen("default") + 1];
		strcpy(this->model, "default");
		this->manuala = false;
		this->valoare = 22.3;
		this->nrComponente = 2;
		this->componente = new int[2];
		this->componente[0] = 10;
		this->componente[1] = 11;
	}

	Masina(int nrCrtNou, char* modelNou, bool manualaNou,
		float valoareNou) {
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->manuala = manualaNou;
		this->valoare = valoareNou;
		this->componente = new int[2];
		this->componente[0] = 10;
		this->componente[1] = 11;
	}

	Masina(int nrCrtNou, char* modelNou, bool manualaNou,
		float valoareNou, int* componenteNou, int nrComponente) {
		this->nrCrt = nrCrtNou;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->manuala = manualaNou;
		this->valoare = valoareNou;
		this->nrComponente = nrComponente;
		this->componente = new int[nrComponente];
		for (int i = 0; i < nrComponente; i++) {
			this->componente[i] = componenteNou[i];
		}
	}

	void afiseaza() {
		cout << "nrCrt : " << this->nrCrt << " Model : "
			<< this->model << " Manuala : " << (this->manuala ? "da" : "nu")
			<< " Valoare : " << this->valoare << " nrComponente " << this->nrComponente;

		cout << "Pret componente";
		for (int i = 0; i < this->nrComponente; i++) {
			cout << " " << this->componente[i];
		}
	}
	// fstream istream
	friend ifstream& operator >> (ifstream& in, Masina& m);
	friend ofstream& operator << (ofstream& out, Masina& m);
};


ifstream& operator >> (ifstream& in, Masina& m) {
	in >> m.nrCrt;
	char buffer[50];
	in.ignore();
	in.getline(buffer, 50);
	delete m.model;
	m.model = new char[strlen(buffer) + 1];
	strcpy(m.model, buffer);
	in >> m.manuala;
	in >> m.valoare;
	in >> m.nrComponente;

	delete m.componente;
	m.componente = new int[m.nrComponente];

	for (int i = 0; i < m.nrComponente; i++) {
		in >> m.componente[i];
	}

	return in;
}

ofstream& operator << (ofstream& out, Masina& m) {
	out << m.nrCrt << endl;
	out << m.model << endl;
	out << m.manuala << endl;
	out << m.valoare << endl;
	out << m.nrComponente << endl;
	for (int i = 0; i < m.nrComponente; i++) {
		out << m.componente[i] << endl;
	}

	return out;
}

void scrieBinFisier(Masina m) {
	int modelLength = strlen(m.model) + 1;
	ofstream out("out.bin", ios::binary);
	out.write((char*)&m.nrCrt, sizeof(int));
	out.write((char*)&modelLength, sizeof(int));
	out.write(m.model, sizeof(char) * modelLength);
	out.write((char*)&m.manuala, sizeof(bool));
	out.write((char*)&m.valoare, sizeof(float));

	out.close();
}

Masina citesteBinFisier() {
	ifstream in("out.bin", ios::binary);
	int nrCrt;
	in.read((char*)&nrCrt, sizeof(int));
	int modelLength;
	in.read((char*)&modelLength, sizeof(int));
	char buffer[100];
	in.read(buffer, modelLength);
	bool manuala;
	in.read((char*)&manuala, sizeof(bool));
	float valoare;
	in.read((char*)&valoare, sizeof(float));

	Masina m(nrCrt, buffer, manuala, valoare);
	return m;
}


int main() {

	int* componente = new int[3];
	componente[0] = 3;
	componente[1] = 1;
	componente[2] = 6;

	Masina m1;
	Masina m2(1, "bmw", false, 3243.2, componente, 3);

	ofstream out("out.txt", ios::out);
	out << m2;
	out.close();

	ifstream in("out.txt", ios::in);
	in >> m1;
	m1.afiseaza();
	in.close();
	

	/* Masina m3(4, "audi", true, 99.1);
	scrieBinFisier(m3);

	Masina m4 = citesteBinFisier();
	m4.afiseaza();
	*/

	return 0;
}