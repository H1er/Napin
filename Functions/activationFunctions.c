#include "activationFunctions.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


double calculate(char* id, double x, double a)
{
    if (!strcmp(id, "sigmoid"))
    {
        return sigmoid(x);
    }
    else if(!strcmp(id, "hsigmoid"))
    {
        return hard_sigmoid(x);
    }
    else if(!strcmp(id, "elu"))
    {
        return elu(x, a);
    }
    else if(!strcmp(id, "relu"))
    {
        return relu(x);
    }
    else if(!strcmp(id, "lrelu"))
    {
        return leaky_relu(x);
    }
    else if(!strcmp(id, "Rrelu"))
    {
        return randomize_relu(x, a);
    }
    else if(!strcmp(id, "tanh"))
    {
        return tanh(x);
    }
    else if(!strcmp(id, "softplus"))
    {
        return softplus(x);
    }
    else if(!strcmp(id, "softsign"))
    {
        return softsign(x);
    }
    else if(!strcmp(id,"paso"))
    {
        return paso(x);
    }
    else
    {
        //hacer que de algun error
        printf("Error, activation function name incorrect or not defined in here\n");
        exit(-1);
    }
}

double calculateprime(char* id, double x, double a)
{
    if (!strcmp(id, "sigmoid"))
    {
        return sigmoid_prime(x);
    }
    else if(!strcmp(id, "hsigmoid"))
    {
        return hard_sigmoid_prime(x);
    }
    else if(!strcmp(id, "elu"))
    {
        return elu_prime(x, a);
    }
    else if(!strcmp(id, "relu"))
    {
        return relu_prime(x);
    }
    else if(!strcmp(id, "lrelu"))
    {
        return leaky_relu_prime(x);
    }
    else if(!strcmp(id, "Rrelu"))
    {
        return randomize_relu_prime(x, a);
    }
    else if(!strcmp(id, "tanh"))
    {
        return tanhip_prime(x);
    }
    else if(!strcmp(id, "softplus"))
    {
        return softplus_prime(x);
    }
    else if(!strcmp(id, "softsign"))
    {
        return softsign_prime(x);
    }
    else if(!strcmp(id,"paso"))
    {
        return paso_prime(x);
    }
    else
    {
        //hacer que de algun error
        printf("Error, prime activation function name incorrect or not defined in here\n");
        exit(-1);
    }

}

static double paso(double x)
{
    if (x>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


static double sigmoid (double x)
{
    return (1 / (1+exp(-x)));
}

static double hard_sigmoid (double x)
{
    if(x<-2.5)
    {
        return 0;
    }
    if(x> 2.5)
    {
        return 1;
    }
    else
    {
        return ((0.2*x)+0.5);
    }
}

static double elu (double x, double a)
{
    if(x>0)
    {
        return x;
    }
    else
    {
        return a*(exp(x)-1);
    }
}

static double relu (double x)
{
    if (x>0)
    {
        return x;
    }
    else
    {
        return 0;
    }
}

static double leaky_relu (double x)
{
    if (x>0)
    {
        return x;
    }
    else
    {
        return 0.01*x;
    }
}

static double randomize_relu (double x, double a)
{
    if (x>0)
    {
        return x;
    }
    else
    {
        return a*x; 
    }
}

static double tanhip (double x)
{
    return (2/(1+exp(-2*x)))-1;
}

static double softplus (double x)
{
    return log(1+exp(x));
}

static double softsign (double x)
{
    return x/(fabs(x)+1);
}



static double sigmoid_prime (double x)
{
    return sigmoid(x) * (1-sigmoid(x));
}

static double hard_sigmoid_prime (double x)
{
    if(x<-2.5 || x >2.5)
    {
        return 0;
    }
    else
    {
        return 0.2;
    }

}

static double elu_prime (double x, double a)
{
    if(x<0)
    {
        return elu(x, a) + a;
    }
    else
    {
        return 1;
    }
}

static double relu_prime (double x)
{
    if(x<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

static double leaky_relu_prime (double x)
{
     if (x>0)
    {
        return 1;
    }
    else
    {
        return 0.01;
    }

}

static double randomize_relu_prime (double x, double a)
{
    if (x>0)
    {
        return 1;
    }
    else
    {
        return a; 
    }

}

static double tanhip_prime (double x)
{
    return (1 - pow(tanhip(x), 2) );
}

static double softplus_prime (double x)
{
    return 1/(1+exp(-x));
}

static double softsign_prime (double x)
{
    return (1/pow((1+abs(x)), 2));

}

static double paso_prime (double x)
{
    return 0;
}








