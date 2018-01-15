#include<iostream>
#include "Header.h"
using namespace std;

class Pisica {
private:
	int varsta;

public:
	Pisica(int varsta) {
		this->varsta = varsta;
	}

	void setVarsta(int varsta) {
		if (varsta > 0) {
			this->varsta = varsta;
		}else {
			//throw 10;
			//throw exception("invalid");
			throw InvalidParam("parametrul varsta este invalid");
		}
	}
};


int main() {
	Pisica p1(1);
	p1.setVarsta(10);

	try{
		p1.setVarsta(-1);
	}
	catch (InvalidParam& invalidParam) {
		cout << invalidParam.getError();
	}
	
	

	return 0;
}