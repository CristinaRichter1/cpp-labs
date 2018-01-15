#include<iostream>
#include "Header.h"

	InvalidParam::InvalidParam(char* message) {
		this->message = new char[strlen(message) + 1];
		strcpy(this->message, message);
	}

	char* InvalidParam::getError() {
		return this->message;
	}