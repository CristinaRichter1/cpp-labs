#include <iostream>
using namespace std;

class Masina {

private:
	int nrCrt;
	char* model;
	float valoare;
	const bool manuala;
	int vechime;
	int* depreciere;

public:
	static int nrMasini;

	Masina() : manuala(true) {

		Masina::nrMasini++;
		this->nrCrt = Masina::nrMasini;
		this->model = new char[strlen("audi") + 1];
		this->valoare = 9932;
		strcpy(this->model, "audi");
		this->vechime = 2;
		this->depreciere = new int[this->vechime];
		this->depreciere[0] = 3;
		this->depreciere[1] = 20;
	}

	Masina(char* modelNou, float valoareNou,
		bool manualaNou, int vechimeNou, int* depreciereNou) : manuala(manualaNou) {

		Masina::nrMasini++;
		this->nrCrt = Masina::nrMasini;
		this->model = new char[strlen(modelNou) + 1];
		strcpy(this->model, modelNou);
		this->valoare = valoareNou;
		this->vechime = vechimeNou;
		this->depreciere = new int[this->vechime];

		for (int i = 0; i < this->vechime; i++) {
			this->depreciere[i] = depreciereNou[i];
		}
	}

	void afiseaza() {
		cout << " nrCrt " << this->nrCrt << " model " << this->model
			<< " valoare :" << this->valoare << " manuala "
			<< (manuala ? "da" : "nu") << "vechime :" << this->vechime;

		for (int i = 0; i < this->vechime; i++) {
			cout << " in anul " << i << "depreciere = "
				<< this->depreciere[i];
		}

		cout << endl;
	}

	int operator[](int index) {
		return this->depreciere[index];
	}

	void operator delete(void *pointer) {
		cout << "delete operator";
		delete[] static_cast<char*>(pointer);
	}

	friend ostream& operator<<(ostream& out, Masina& m);
	friend istream& operator>>(istream& in, Masina& m);

};

ostream& operator<<(ostream& out, Masina& m) {
	out << "nrCrt " << m.nrCrt << " model " << m.model << " valoare "
		<< m.valoare << " manuala " << (m.manuala ? "da" : "nu")
		<< " vechime " << m.vechime;

	for (int i = 0; i < m.vechime; i++) {
		out << "depreciere in anul 1 =" << m.depreciere[i];
	}

	return out;
}

istream& operator >> (istream& in, Masina& m) {
	cout << "nrCrt : ";
	in >> m.nrCrt;

	cout << "Model : ";
	char buffer[100];
	in >> buffer;
	delete m.model;
	m.model = new char[strlen(buffer) + 1];
	strcpy(m.model, buffer);

	cout << "valoare : ";
	in >> m.valoare;
	//cout << "manuala ?";
	//in >> m.manuala;
	cout << " vechime : ";
	in >> m.vechime;

	delete[] m.depreciere;
	m.depreciere = new int[m.vechime];
	for (int i = 0; i < m.vechime; i++) {
		cout << "depreciere in anul " << i << " ";
		in >> m.depreciere[i];
	}

	return in;
}

int Masina::nrMasini = 0;

int main() {
	Masina m1;
	Masina m2("bmw", 32, false, 2, new int[2]{10, 20});
	Masina m3("bmw", 32, false, 3, new int[3]{20, 30, 10});

	Masina* m4 = new Masina();

	//m1.afiseaza();
	//m2.afiseaza();
	//m3.afiseaza();

	//cout << "depreciere in anul 1: " << m3[1];
	//delete m4;

	cout <<endl << m2;
	cin >> m2;
	cout << endl << m2;

	return 0;
}