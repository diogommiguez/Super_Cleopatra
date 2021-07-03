#include "func.hpp"
#include "ofMath.h"

double distance(double x1, double y1, double x2, double y2){
    return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2),1/2.0);
}

double* normalize(double* array, int array_size){
    if(array)//array IS TRUE IF NOT NULL
    {
        double maximo = array[0];
        //FIND MAXIMUM (1 cycle)
        for (int i = 1; i < array_size; i++)
        {
            if (array[i] > maximo) maximo = array[i];
        }
        //NORMALIZE ARRAY (2nd cycle)
        for (int i = 0; i < array_size; i++)
        {
            array[i]  = array[i]/maximo;
        }
    }
    return array;
}

double max(double* array, int array_size){
    double maximo = array[0];
    //FIND MAXIMUM (1 cycle)
    for (int i = 1; i < array_size; i++)
    {
        if (array[i] > maximo) maximo = array[i];
    }
    return maximo;
}

double get_frequency(double slider_value){
    // f(x) = m*x + a*b^x
    double m = 4.;
    double a = 3;
    double b = 1.083;
    
    return m*slider_value + a*pow(b, slider_value);
}

double get_volume(double slider_value){
    // f(x) = m*x + (c)/(1 + (x/a)^b)
    double m = 0.001;
    double c = 1.2;
    double a = 120.;
    double b = -3.8;
    
    return m*slider_value + (c)/(1 + pow(slider_value/a, b));
}
