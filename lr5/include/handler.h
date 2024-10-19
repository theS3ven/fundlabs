#ifndef HEADER_H
#define HEADER_H

typedef enum { POBEDA_GOOOOOL, ERROR_ARGS_COUNT, ERROR_ARGS_FLAG } state;

int getOpt(int argc, char** args, double* number);
void HandlerError(int number);

#endif