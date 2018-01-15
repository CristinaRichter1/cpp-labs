class InvalidParam {
private:
	char* message;
public:
	InvalidParam(char* message);
	char* getError();
};