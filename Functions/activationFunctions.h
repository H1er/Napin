#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H


double calculate (char* id, double x, double a);

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



#endif /* ACTIVATIONFUNCTIONS_H */