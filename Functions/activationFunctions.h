#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H


double calculate (char* id, double x, double a);

double calculateprime(char* function, double x, double a);


//regular activation functions

static double sigmoid (double x);

static double hard_sigmoid (double x);

static double elu (double x, double a);

static double relu (double x);

static double leaky_relu (double x);

static double randomize_relu (double x, double a);

static double tanhip (double x);

static double softplus (double x);

static double softsign (double x); 

static double paso (double x);


//derivative of activation functions

static double sigmoid_prime (double x);

static double hard_sigmoid_prime (double x);

static double elu_prime (double x, double a);

static double relu_prime (double x);

static double leaky_relu_prime (double x);

static double randomize_relu_prime (double x, double a);

static double tanhip_prime (double x);

static double softplus_prime (double x);

static double softsign_prime (double x); 

static double paso_prime (double x);




#endif /* ACTIVATIONFUNCTIONS_H */