#include <stdio.h>

#include "handler.h"

int main(int argc, char** args) {
	double number;
	int code = getOpt(argc, args, &number);
	if (code) {
		HandlerError(code);
		return 1;
	}
	return 0;
}