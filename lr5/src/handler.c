#include "handler.h"

#include <stdio.h>

double fabs(double number) { return (number >= 0) ? number : -number; }

void HandlerError(int number) {
	switch (number) {
		case ERROR_ARGS_COUNT:
			printf("Args count error\n");
			break;
		case ERROR_ARGS_FLAG:
			printf("Wrong flag\n");
			break;
	}
}

int atoiCustom(const char *inputString) {
	int result = 0, sign = 1, index = 0;
	if (inputString[0] == '-') {
		sign = -1;
		index++;
	} else if (inputString[0] == '+') {
		index++;
	}
	while (inputString[index] != '\0') {
		if (inputString[index] > '9' || inputString[index] < '0') {
			break;
		}
		result = result * 10 + (inputString[index] - '0');
		index++;
	}
	return sign * result;
}

double atofCustom(const char *inputString) {
	int sign = 1, index = 0, flag = 0;
	double result = 0.0, afterPointCount = 1.0;
	if (inputString[0] == '-') {
		sign = -1;
		index++;
	} else if (inputString[0] == '+') {
		index++;
	}
	while (inputString[index] != '\0') {
		if (inputString[index] == '.') {
			flag = 1;
			index++;
		}
		if (inputString[index] > '9' || inputString[index] < '0') {
			index++;
			continue;
		}
		if (!flag) {
			result = result * 10.0 + (inputString[index] - '0');
			index++;
		} else {
			afterPointCount /= 10.0;
			result += (inputString[index] - '0') * afterPointCount;
			index++;
		}
	}
	return sign * result;
}
double powCustom(int number, int mult) {
	int res = 1.0;
	for (int i = 0; i < mult; i++) {
		res *= number;
	}
	return res;
}
double optA(double *number, double eps) {
	double next = 1.0;
	double res = 1.0;
	int n = 1;
	while (next >= eps) {
		next *= *number / n;
		res += next;
		n++;
	}
	return res;
}

double optB(double *number, double eps) {
	double next = 1.0;
	double res = 1.0;
	double x = *number;
	int n = 1;
	while (fabs(next) >= eps) {
		next *= (-1.0 * x * x) / (2 * n * (2 * n - 1.0));
		res += next;
		n++;
	}
	return res;
}

double optC(double *number, double eps) {
	double next = 1.0;
	double res = 1.0;
	double x = *number;
	int n = 1;
	while (next >= eps) {
		next *= (27.0 * n * n * n * x * x) / ((3 * n) * (3 * n - 1) * (3 * n - 2));
		res += next;
		n++;
	}
	return res;
}
double optD(double *number, double eps) {
	double next = 1.0;
	double res = 0.0;
	double x = *number;
	int n = 1;
	while (fabs(next) >= eps) {
		next *= (-1.0 * x * x * (2.0 * n - 1)) / (2.0 * n);
		res += next;
		n++;
	}
	return res;
}

// сначала число, потом epsilon
int getOpt(int argc, char **args, double *number) {
	if (argc != 3) {
		return ERROR_ARGS_COUNT;
	}
	double eps = atofCustom(args[2]);
	*number = atofCustom(args[1]);
	printf("%f = number\n%f = eps\n", *number, eps);
	printf("%f A\n", optA(number, eps));
	printf("%f B\n", optB(number, eps));
	printf("%f C\n", optC(number, eps));
	printf("%f, D\n", optD(number, eps));
	return POBEDA_GOOOOOL;
}