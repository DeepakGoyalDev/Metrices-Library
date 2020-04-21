#ifndef METRICE_H_INCLUDED
#define METRICE_H_INCLUDED

#include<iostream>
enum Type
{
    TYPE_MATRIX = 1,
    TYPE_DAIGONAL,
    TYPE_LOWER_TRIANGULAR,
    TYPE_UPPER_TRIANGULAR,
    TYPE_SYMMETRIC,
    TYPE_TRIBAND,
    TYPE_TOEPLITZ,
};
class Metrices
{
private:
Type matrix_type;

protected:
    int dim;
    int  *a;

public:
    Metrices(int dd, Type mt)
    {
        dim = dd;
        matrix_type = mt;
        switch(matrix_type)
        {
        case 1: a = new int[dim*dim];
            break;
        case 2: a = new int[dim];
            break;
        case 3:
        case 4:
        case 5: a = new int[dim*(dim+1)/2];
            break;
        case 6: a = new int[3*dim-2];
            break;
        case 7: a = new int[2*dim-1];
            break;
        }
    }
    ~Metrices()
    {
        delete[] a;
    }
    void set(int r, int c, int value);
    int get(int r, int c);
    void display();
};
class matrix : public Metrices
{
    public:
    matrix(int n=0, Type t = TYPE_MATRIX): Metrices(n, t){}
};
class daigonal : public Metrices
{
    public:
    daigonal(int n=0, Type t = TYPE_DAIGONAL) : Metrices(n, t){}
};
class lower_triangular : public Metrices
{
    public:
    lower_triangular(int n = 0, Type t = TYPE_LOWER_TRIANGULAR) : Metrices(n, t){}
};
class upper_triangular : public Metrices
{
    public:
    upper_triangular(int n = 0, Type t = TYPE_UPPER_TRIANGULAR) : Metrices(n, t){}
};
class symmetric : public Metrices
{
    public:
    symmetric(int n = 0, Type t = TYPE_SYMMETRIC) : Metrices(n, t){}
};
class triband : public Metrices
{
    public:
    triband(int n = 0, Type t = TYPE_TRIBAND) : Metrices(n, t){}
};
class toeplitz : public Metrices
{
    public:
    toeplitz(int n = 0, Type t = TYPE_TOEPLITZ) : Metrices(n, t){}
};

#endif // METRICE_H_INCLUDED
